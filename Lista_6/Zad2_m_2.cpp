#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <numeric>


class thread_pool
{
    using Task = std::function<double()>;

    private:
    int thread_num;
    std::vector<std::thread> threads;
    std::vector<Task> tasks;
    std::vector<double> results;
    std::mutex mTask;
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
                while(true)
                {
                    Task current_task;
                    {
                        std::unique_lock<std::mutex> lock(mTask);
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
                stop();
            });
        }
    }




    void add_task(Task task)
    {
        {
            std::lock_guard lock(mTask);
            tasks.emplace_back(std::move(task));
        }
        mCondVar.notify_one();
    }

    double average()
    {
        std::lock_guard<std::mutex> lock(mResults);
        double sum = 0.0;

        for(auto result : results)
        sum += result;

        return sum / results.size();
    }

    void stop()
    {
        {
            std::lock_guard<std::mutex> lock(mTask);
            stop_flag = true;
        }

        mCondVar.notify_all();
        for(auto &thread : threads)
        {
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
    thread_pool test_pool(4);
    
    for(int i = 0; i < 10; i++)
    {
        test_pool.add_task([i]
        {
            return static_cast<double> (i * i);
        });
    }

    std::cout<<"average = "<<test_pool.average();

    test_pool.stop();

    return 0;
}