#include <iostream>
#include <list>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    unsigned int period = 0;
    std::cin >> period;

    std::list<int> magnetic_values;
    int last_peak = -1;
    std::list<int>::iterator prev_peak;
    bool max_removed = true;

    unsigned int values_red = 0;

    while (true)
    {
        int new_value = 0;
        std::cin >> new_value;

        if (new_value == -1)
            break;

        //skip the repeating values
        if (magnetic_values.size() < 2 || new_value != magnetic_values.back() || new_value > last_peak)
        {
            magnetic_values.push_back(new_value);
        }

        if (values_red < period - 1)
            values_red++;
        else
        {
            // locate max in current stack
            if (max_removed)
            {
                prev_peak = std::max_element(magnetic_values.begin(), magnetic_values.end());
                last_peak = *prev_peak;
            }
            else
            {
                if (new_value > last_peak)
                {
                    last_peak = new_value;
                    prev_peak = magnetic_values.end()--;
                }
            }
            std::cout << last_peak << std::endl;
            std::list<int>::iterator removed = magnetic_values.begin();
            max_removed = removed == prev_peak;
            magnetic_values.pop_front();
       }
   }
}