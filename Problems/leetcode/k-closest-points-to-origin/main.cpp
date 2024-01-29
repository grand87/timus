#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <functional>

using namespace std;

//class Solution { //accepted - 344ms
//    int calculateDistance(int x, int y) {
//        return x*x + y*y;
//    }
//public:
//    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//        typedef pair<int, int> Point;
//        
//        //map of distance list of points
//        unordered_map<int, vector<Point>> distancesTable;
//        for (auto point : points) {
//            const int distance = calculateDistance(point[0], point[1]);
//            distancesTable[distance].push_back(make_pair(point[0], point[1]));
//        }
//
//        //heap sort
//        int pointsCount = 0;
//        vector<int> distncesHeap;
//        bool isheap = false;
//        for (auto rec : distancesTable) {
//            if (isheap) {
//                distncesHeap.push_back(rec.first);
//                push_heap(distncesHeap.begin(), distncesHeap.end());
//            } else {
//                distncesHeap.push_back(rec.first);
//            }
//            pointsCount += rec.second.size();
//
//            if (pointsCount >= K) {
//                if (!isheap) {
//                    isheap = true;
//                    //added required amount to make a heap
//                    make_heap(distncesHeap.begin(), distncesHeap.end());
//                } else {
//                    // remove extra points from heap
//                    pop_heap(distncesHeap.begin(), distncesHeap.end());
//                    distncesHeap.pop_back();
//                }
//            }
//        }
//
//        vector<vector<int>> res;
//        while (res.size() < K) {
//            const int dist = distncesHeap.front();
//
//            const vector<Point>& pointsWithDistanceX = distancesTable[dist];
//            for (auto p : pointsWithDistanceX) {
//                const vector<int> newPoint { p.first, p.second };
//                res.push_back(newPoint);
//                if (res.size() == K)
//                    return res;
//            }
//            pop_heap(distncesHeap.begin(), distncesHeap.end());
//            distncesHeap.pop_back();
//        }
//
//        return res;
//    }
//};

class Solution {
    int calculateDistance(int x, int y) {
        return x*x + y*y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        typedef pair<int, int> Point;

        //map of distance list of points
        unordered_map<int, vector<Point>> distancesTable;
        for (auto point : points) {
            const int distance = calculateDistance(point[0], point[1]);
            distancesTable[distance].push_back(make_pair(point[0], point[1]));
        }

        vector<int> distancesStored(distancesTable.size());
        int i = 0;
        for (auto rec : distancesTable) {
            distancesStored[i++] = rec.first;
        }
        //smaller comes first
        sort(distancesStored.begin(), distancesStored.end());

        vector<vector<int>> res;
        for(int distance : distancesStored) {
            const vector<Point>& pointsWithDistanceX = distancesTable[distance];
    
            for (const Point& p : pointsWithDistanceX) {
                const vector<int> newPoint{ p.first, p.second };
                res.push_back(newPoint);
                if (res.size() == K)
                    return res;
            }
        }

        return res;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int vals, k;
        cin >> vals >> k;
        vector<vector<int>> values(vals);

        for (int j = 0; j < vals; j++) {
            values[j].resize(2);
            cin >> values[j][0] >> values[j][1];
        }

        Solution s;
        vector<vector<int>> res = s.kClosest(values, k);
     
        for (auto val : res)
            cout << val[0] << " " << val[1] << endl;
        cout << endl;
    }
}