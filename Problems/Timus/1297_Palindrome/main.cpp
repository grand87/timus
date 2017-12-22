#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct poly
{
    poly(int loc, int l) : location(loc), len(l)
    {

    }
    int location;
    int len;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    char str[1001];
    cin >> str;

    const int len = strlen(str);

    
    vector<poly> polys;


    for (int i = 0; i < len; ++i)
    {
        for (int j = len - 1; j >= i; --j)
        {
            int l = i;
            int r = j;
            bool isPoly = true;

            while (l <= r)
            {
                if (str[l] != str[r])
                {
                    isPoly = false;
                    break;
                }
                l++;
                r--;
            }

            if (isPoly)
                polys.push_back(poly(i, j - i + 1));

        }
    }

    int maxLen = 0;
    int pos = -1;
    for (int i = 0; i < polys.size(); ++i)
    {
        if (polys[i].len > maxLen)
        {
            maxLen = polys[i].len;
            pos = polys[i].location;
        }
    }

    for (int i = 0; i < maxLen; ++i)
        cout << str[pos + i];
}