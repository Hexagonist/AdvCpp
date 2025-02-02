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
            {// lambda to create body of every thread - our workers

                std::unique_lock<std::mutex> lock(mTasks);
                while(!stop_flag || (stop_flag && !tasks.empty()))
                {
                    mCondVar.wait(lock, [this]{return stop_flag || !tasks.empty();});
                    
                    if(!tasks.empty())
                    {
                        Task current_task = std::move(tasks.back());
                        tasks.pop_back();

                        lock.unlock();
                        double result = current_task();
                        lock.lock(); 

                        std::lock_guard<std::mutex> result_lock(mResults);
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
        stop_flag = true;
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

int main()
{
    thread_pool test_pool(10);
    
    for(int i = 0; i < 10; i++)
    {
        test_pool.add_task([i]
        {
            sleep(1); // simulate work (1second)
            return static_cast<double> (i * i);
        });
    }

    test_pool.stop();

    std::cout<<"average = "<<test_pool.average();

    return 0;
}