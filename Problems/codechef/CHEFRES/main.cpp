#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct range
{
    int start;
    int end;

    range(int a = 0, int b = 0) : start(a), end(b)
    {

    }

    bool in(int time) const
    {
        return time >= start && time < end;
    }

    int distance(int time) const
    {
        return time < end ? time >= start ? 0 : start - time : -1;
    }
};

bool operator<(const range &a, const range &b)
{
    return a.end < b.start;
}

vector<range> openHours(100000);

range search(int left, int right, int time)
{
    range r(-1, -1);

    int wait_for_a = openHours[left].distance(time);
    if (wait_for_a >= 0)
        return openHours[left];

    if (left != right)
    {
        int wait_for_b = openHours[right].distance(time);
        if (wait_for_b == 0)
            return openHours[right];

        if (wait_for_b == -1)
            return r;

        const int size = right - left + 1;
        int middle = left + size / 2;
        wait_for_a = openHours[middle].distance(time);
        if (wait_for_a == 0)
            return openHours[middle];

        if (wait_for_a == -1)
            return search(middle + 1, right, time);
        else
            return search(left, middle, time);
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif	
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int opens = 0;
        int guests = 0;
        cin >> opens >> guests;

        for (int openHour = 0; openHour < opens; ++openHour) {         
            cin >> openHours[openHour].start >> openHours[openHour].end;
        }

        sort(openHours.begin(), openHours.begin() + opens);

        for (int guest = 0; guest < guests; ++guest) {
            int time;
            cin >> time;
            
            range r = search(0, opens - 1, time);
            cout << r.distance(time) << endl;
        }
    }
}