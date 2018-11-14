#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment
{
    int len;
    int start;
    int end;
    int id;

    bool hasPoint(int a) const
    {
        return a >= start && a <= end;
    }
};

typedef vector <segment> SegmentsArray;

// returns id of segment with the smalles length & contains the required point
int getID(const SegmentsArray& ar, const int point)
{
    //linear search
    for (int i = 0; i < ar.size(); ++i)
    {
        const segment &s = ar[i];
        if (s.hasPoint(point))
            return s.id;
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif
    int segmentsCount;
    cin >> segmentsCount;


    SegmentsArray segments;
    segments.reserve(segmentsCount);
    segments.resize(segmentsCount);

    for (int i = 0; i < segmentsCount; ++i)
    {
        int a, b;
        cin >> a >> b;

        segments[i].id = i + 1;
        segments[i].len = b - a;
        segments[i].start = a;
        segments[i].end = b;
    }

    //sort by length
    sort(segments.begin(), segments.end(), [](const segment& a, const segment& b) {
        return a.len < b.len;
    });

    int queries;
    cin >> queries;
    for (int i = 0; i < queries; ++i)
    {
        int q;
        cin >> q;
        cout << getID(segments, q) << endl;
    }
}