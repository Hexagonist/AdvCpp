#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

// Mateusz Wójcicki ISSP sem 5; grupa czwartek 15:15

class thread_pool
{
    using Task = std::function<double()>;

    private:
    int thread_num; // number of threads
    std::vector<std::thread> threads; // our workers :)
    std::vector<Task> tasks;
    std::vector<double> results; // results of finished tasks
    std::mutex mTasks;
    std::mutex mResults;
    std::condition_variable mCondVar;
    bool stop_flag;


    public:
    thread_pool(int num) : thread_num(num), stop_flag(false)
    {
        for(auto i = 0; i < num; i++)
        {
            threads.emplace_back([this]
            {
                // lambda to create body of every thread - our workers
                while(true)
                {
                    Task current_task;
                    {
                        std::unique_lock<std::mutex> lock(mTasks);
                        mCondVar.wait(lock, [this]{return stop_flag || !tasks.empty();});
                        if(stop_flag && tasks.empty())   
                            break;
                        
                        current_task = std::move(tasks.back());
                        tasks.pop_back();
                    }

                    double result = current_task();
                    {
                        std::lock_guard<std::mutex> lock(mResults);
                        results.push_back(result);
                    }
                }
            });
        }
    }

    void add_task(Task task)
    {
        {
            std::lock_guard<std::mutex> lock(mTasks);
            tasks.emplace_back(std::move(task));
        }
        mCondVar.notify_one();
    }

    double average()
    {
        std::lock_guard<std::mutex> lock(mResults);
        double avg = 0.0;

        if(!results.empty())
        {
            for(auto result : results)
            avg += result;

            avg /= results.size();
        }
        return avg;
    }

    void stop()
    {
        {
            std::lock_guard<std::mutex> lock(mTasks);
            stop_flag = true;
        }

        mCondVar.notify_all(); // Wake up all threads
        for(auto &thread : threads)
        {
            // Check if they are done with work and only then join them
            if(thread.joinable()) thread.join(); 
        }
    }

    ~thread_pool()
    {
        stop();
    }
};