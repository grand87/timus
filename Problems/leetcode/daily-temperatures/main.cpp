#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        map<int, int> tempsHist;

        vector<int> result(T.size());
        result[T.size() - 1] = 0;
        tempsHist[T[T.size() - 1]] = T.size() - 1;

        int minTemp = T[T.size() - 1];
        int maxTemp = T[T.size() - 1];

        for (int i = T.size() - 2; i >= 0; i--) {
            const int localTemp = T[i];
            //need to locate next day with bigger temp
            if (localTemp < maxTemp) {
                //at least we know there will be a day with bigger temp
                int day = T.size();
                for (int t = localTemp + 1; t <= maxTemp; t++) {
                    auto locationWarmerDay = tempsHist.find(t);
                    if (locationWarmerDay != tempsHist.end()) {
                        day = min(locationWarmerDay->second, day);
                    }
                }
                result[i] = day - i;
            } else {
                result[i] = 0;
            }
            tempsHist[localTemp] = i;
            minTemp = min(minTemp, localTemp);
            maxTemp = max(maxTemp, localTemp);
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size());
        result[T.size() - 1] = 0;
        if (T.size() == 1)
            return result;

        stack<pair<int, int>> tempHistory;
        tempHistory.push(make_pair(T[T.size() - 1], T.size() - 1));

        for (int day = T.size() - 2; day >= 0; day--) {
            int currentTemp = T[day];
            while (tempHistory.size() > 0 && currentTemp >= tempHistory.top().first) {
                tempHistory.pop();
            }
            if (tempHistory.size() == 0) {
                //no warmer day in future
                result[day] = 0;
            } else {
                result[day] = tempHistory.top().second - day;
            }
            tempHistory.push(make_pair(currentTemp, day));
        }

        return result;
    }
};


int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> temps(n);
        readVector(cin, temps, n);
        Solution2 s;
        vector<int> res = s.dailyTemperatures(temps);
        printVector(cout, res);
        cout << endl;
    }
}