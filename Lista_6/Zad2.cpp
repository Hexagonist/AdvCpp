#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <numeric>

class thread_pool {
private:
    std::vector<std::thread> workers;                  // Worker threads
    std::queue<std::function<double()>> tasks;         // Queue of tasks
    std::vector<double> results;                       // Completed task results
    std::mutex tasks_mutex;                            // Mutex for task queue
    std::mutex results_mutex;                          // Mutex for results vector
    std::condition_variable condition;                 // Condition variable for task notification
    std::atomic<bool> stop_flag;                       // Flag to stop threads
    std::atomic<size_t> tasks_remaining;               // Tracks remaining tasks

    void worker_thread() {
        while (true) {
            std::function<double()> task;
            {
                std::unique_lock<std::mutex> lock(tasks_mutex);
                condition.wait(lock, [this] { return stop_flag || !tasks.empty(); });

                if (stop_flag && tasks.empty()) break;

                task = std::move(tasks.front());
                tasks.pop();
                ++tasks_remaining; // Increment for a new task
            }

            // Execute the task outside the lock
            double result = task();

            {
                std::lock_guard<std::mutex> lock(results_mutex);
                results.push_back(result);
                --tasks_remaining; // Task completed
            }
        }
    }

public:
    // Constructor
    thread_pool(size_t num_threads) : stop_flag(false), tasks_remaining(0) {
        for (size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back(&thread_pool::worker_thread, this);
        }
    }

    // Add a new task
    void add_task(std::function<double()> task) {
        {
            std::lock_guard<std::mutex> lock(tasks_mutex);
            tasks.push(std::move(task));
        }
        condition.notify_one(); // Notify one waiting thread
    }

    // Calculate the average of results
    double average() {
        std::lock_guard<std::mutex> lock(results_mutex);
        if (results.empty()) return 0.0;
        double sum = std::accumulate(results.begin(), results.end(), 0.0);
        return sum / results.size();
    }

    // Stop the threads
    void stop() {
        {
            std::lock_guard<std::mutex> lock(tasks_mutex);
            stop_flag = true;
        }
        condition.notify_all(); // Wake up all threads to terminate
        for (std::thread& worker : workers) {
            if (worker.joinable()) worker.join();
        }
    }

    // Destructor
    ~thread_pool() {
        stop();
    }
};

int main() {
    thread_pool pool(4); // Create a thread pool with 4 worker threads

    // Add tasks to the pool
    for (int i = 0; i < 10; ++i) {
        pool.add_task([i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
            return static_cast<double>(i * i);
        });
    }

    // Wait for some time before stopping
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Average result: " << pool.average() << "\n";

    pool.stop();
    return 0;
}