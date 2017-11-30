#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct heap
{
    int max;
    int maxPosition;

    heap()
    {
        max = 0;
        maxPosition = 0;
    }

    std::list<int> data;

    void push(int value)
    {
        data.push_back(value);
        if (value > max)
        {
            max = value;
            maxPosition = data.size() - 1;
        }
    }

    int getMax() const
    {
        return max;
    }

    void pop()
    {
        data.pop_front();
        if (maxPosition == 0)
        {
            max = 0;
            //search for a new max
            int pos = 0;
            for (std::list<int>::const_iterator it = data.begin(); it != data.end(); ++it, ++pos)
            {
                if (*it > max)
                {
                    max = *it;
                    maxPosition = pos;
                }
            }
        }
        else
            --maxPosition;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    int duration = 0;
    cin >> duration;
    int step = 0;

    heap h;

    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
            break;
  
        h.push(value);
        ++step;
        if (step >= duration)
        {
            cout << h.getMax() << endl;
            h.pop();
        }
    }
}