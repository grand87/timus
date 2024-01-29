#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct period
{
    int start, end;
};

const int cMaxCount = 100001;
period contest[cMaxCount];
int v[cMaxCount];
int w[cMaxCount];

int validV[cMaxCount];

bool compare(const period& a, const period& b) {
    return a.start < b.start;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 0; i < n; ++i) {
        period& c = contest[i];
        cin >> c.start >> c.end;
    }

    sort(contest, contest + n, compare);
    //const int minimalStart = contest[0].start;
    //const int maximalStart = contest[n - 1].start;

    int wormHoleOpen = 0;
    //int wormHoleOpenStartClosest = 0;
    //int wormHoleOpenStartCount = 0;

    int vCount = 0;
    for (int i = 0; i < x; ++i) {
        cin >> wormHoleOpen;
        //if (wormHoleOpen <= minimalStart && wormHoleOpen > wormHoleOpenStartClosest) {
        //    wormHoleOpenStartClosest = wormHoleOpen;
        //    wormHoleOpenStartCount++;
        //    v[vCount++] = wormHoleOpen;
        //} else if (wormHoleOpen >= minimalStart && wormHoleOpen <= maximalStart) {
            v[vCount++] = wormHoleOpen;
//        }
    }
    sort(v, v + vCount);
    //need to remove all before wormHoleOpenStartClosest
    //if (wormHoleOpenStartCount > 1) {
    //    int skip = 0;
    //    for (; skip < vCount; ++skip) {
    //        if (v[skip] == wormHoleOpenStartClosest)
    //            break;
    //    }
    //    if (skip > 0) {
    //        for (int i = 0; i < vCount - skip; ++i) {
    //            v[i] = v[skip + i];
    //        }
    //        vCount -= skip;
    //    }
    //}

    //const int minimalEnd = contest[0].end;
    //const int maximalEnd = contest[n - 1].end;

    int wormHoleClose = 0;
    //int wormHoleCloseEndClosest = 1000000;
    //int wormHoleClsoeEndCount = 0;

    int wCount = 0;
    for (int i = 0; i < y; ++i) {
        cin >> wormHoleClose;
        //if (wormHoleClose >= maximalEnd && wormHoleClose < wormHoleCloseEndClosest) {
        //    wormHoleCloseEndClosest = wormHoleClose;
        //    wormHoleClsoeEndCount++;
        //    w[wCount++] = wormHoleClose;
        //} else if (wormHoleClose >= minimalEnd && wormHoleClose <= maximalEnd) {
            w[wCount++] = wormHoleClose;
        //}
    }
    sort(w, w + wCount);
    //need to remove all before wormHoleOpenStartClosest
    //if (wormHoleClsoeEndCount > 1) {
    //    int skip = wCount - 1;
    //    for (; skip > 0; --skip) {
    //        if (w[skip] == wormHoleCloseEndClosest)
    //            break;
    //    }
    //    if (skip > 0) {
    //        wCount = skip + 1;
    //    }
    //}

    v[vCount] = -1;
    w[wCount] = -1;

    int minAns = 100000;

    // now we have sorted list of contests & sorted list of open & close for warmholes
    for (int startIndex = 0; startIndex < n; ++startIndex) {
        //for each contest based on binary search we need to find the most closes open & close wormhole
        int* closestStart = std::lower_bound(v, v + vCount, contest[startIndex].start);
        if (*closestStart != contest[startIndex].start) {
            if (closestStart != v && *(closestStart - 1) <= contest[startIndex].start)
                closestStart--;
            else
                continue;
        }

        int* closestStop = std::lower_bound(w, w + wCount, contest[startIndex].end);
        if (closestStop == w + wCount) {
            continue;
        }

        int ans = *closestStop - *closestStart + 1;
        if (minAns > ans)
            minAns = ans;
    }

    cout << minAns << endl;
}