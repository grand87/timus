#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long long n, k;
    cin >> n >> k;

    int hs = 0;

    int remain = n;
    do
    {
        int gID = 0;
        cin >> gID;
        int sGroupsCreated = 0;
        cin >> sGroupsCreated;

        vector<int> groups;
        for (int g = 0; g < sGroupsCreated; ++g)
        {
            int subGroupSize = 0;
            cin >> gID >> subGroupSize;
            groups.push_back(subGroupSize);

            if (subGroupSize == 1)
                --remain;
            else if (subGroupSize == 2 & k != 0)
            {
                --k;
                remain -= 2;
            }
        }

        sort(groups.begin(), groups.end(), std::greater<int>());

        for (int i = 0; i < groups.size() - 1; ++i)
        {
            int hss = 0;
            for (int j = i + 1; j < groups.size(); ++j)
            {
                hs += groups[i] * groups[j];
            }
        }
    } while (k == 0 ? remain != 0 : remain != 2);

    cout << hs;
}