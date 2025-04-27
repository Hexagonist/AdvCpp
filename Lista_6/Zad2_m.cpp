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
                        
                        current_task = tasks.back();
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

    ~thread_pool()
    {
        stop();
    }




    void add_task(Task task)
    {
        std::lock_guard lock(mTask);
        tasks.emplace_back(std::move(task));
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
        for(auto &thread : threads)
        {
            if(thread.joinable()) thread.join();
        }
    }


};



int main()
{
    // thread_pool pool(4);

    return 0;
}