#include <iostream>

#define MAX_JOBS 100
#define MAX_PRIORITIES 500
#define min(X, Y) X < Y ? X : Y


using namespace std;

struct Job
{
    unsigned int dl;
    unsigned int profit;

    Job(unsigned int d = 0, unsigned int p = 0)
    {
        dl = d;
        profit = p;
    }
};

template <typename T>
struct List
{
    T* data;
    unsigned int size;

    List(unsigned int size)
    {
        data = new T[size];
        memset(data, 0, size * (sizeof T));
        this->size = 0;
    }

    void add(const T& value)
    {
        data[size++] = value;
    }

    void dump() const
    {
        for (unsigned int i = 0; i < size; ++i)
            std::cout << data[i] << " ";
    }

};

template <typename T>
struct priority_queue
{
    List<T>** data;

    unsigned int prioritiesCount;

    priority_queue(T valuesCount, unsigned int prioritiesCount)
    {
        this->prioritiesCount = prioritiesCount;
        data = new List<T>*[prioritiesCount];
        for (unsigned int i = 0; i < prioritiesCount; ++i)
        {
            data[i] = new List<T>(valuesCount);
        }
    }

    void add(const T& value, unsigned int priority)
    {
        data[priority]->add(value);
    }

    T pop()
    {
        return 0;
    }

    void dump(Job* jobs) const
    {
        unsigned int pos = 0;
        for (unsigned int i = prioritiesCount - 1; i > 0; --i)
        {
            if (data[i]->size > 0)
            {
                /*
                cout << "Priority " << i << endl;
                data[i]->dump();
                cout << endl;
                */
                for (unsigned int j = 0; j < data[i]->size; ++j)
                {
                    jobs[pos++] = Job(data[i]->data[j], i);
                }
            }
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif

   unsigned int testCases = 0;

   cin >> testCases;

   for (int t = 0; t < testCases; ++t)
   {
       priority_queue<unsigned int> queue(MAX_JOBS, MAX_PRIORITIES);
       unsigned int jobsCount = 0;

       cin >> jobsCount;

       for (unsigned int j = 0; j < jobsCount; ++j)
       {
           unsigned int jobID, dl, profit;
           cin >> jobID >> dl >> profit;
           queue.add(dl, profit);
       }

       //generate sorted by profit array of jobs
       Job sortedByProfit[MAX_JOBS];
       queue.dump(sortedByProfit);


       //evaluate jobs profit and try to allocate time slotes from the latest availible time slot with the highest profit
       bool timeSlots[MAX_PRIORITIES];
       memset(timeSlots, 0, (sizeof timeSlots[0]) * MAX_PRIORITIES);

       List<unsigned int> profits(MAX_JOBS);

       for (unsigned int n = 0; n < jobsCount; ++n)
       {
           for (unsigned int ts = min(jobsCount, sortedByProfit[n].dl); ts > 0; --ts)
           {
               if (!timeSlots[ts])
               {
                   timeSlots[ts] = true;
                   profits.add(sortedByProfit[n].profit);
                   break;
               }
           }
       }
/*
       std::cout << std::endl << "profit " << std::endl;
       profits.dump();
*/
       unsigned int total = 0;
       for (int i = 0; i < profits.size; ++i)
       {
           total += profits.data[i];
       }
       std::cout << profits.size << " " << total << std::endl;
   }
}