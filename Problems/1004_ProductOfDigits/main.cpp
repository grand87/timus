#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif
   long long value;

   cin >> value;

   if (value == 0)
       cout << "10";
   else if(value == 1)
       cout << "1";
   else
   {
       vector<short> ans;
       for (int i = 9; i > 1; --i)
       {
           if (value % i == 0)
           {
               ans.push_back(i);
               value = value / i;
               if (value == 1)
                   break;
               else
                   i = 10;
           }
       }

       if (value == 1)
       {
           sort(ans.begin(), ans.end());
           for (short i : ans)
           {
               cout << i;
           }
       }
       else
           cout << "-1";
    }
}