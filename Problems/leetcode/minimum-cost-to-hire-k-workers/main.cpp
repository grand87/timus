#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

    void generate(int n, int k, int current, vector<int> currentCombination, vector<vector<int>> &combs) {

        if (currentCombination.size() == k) {
            combs.push_back(currentCombination);
            return;
        }

        if (current == n)
            return;

        currentCombination.push_back(current);
        generate(n, k, current + 1, currentCombination, combs);
        currentCombination.pop_back();
        generate(n, k, current + 1, currentCombination, combs);
    }


    void generate(int n, int k, vector<vector<int>> &combs) {
        vector<int> currentCombination;
        generate(n, k, 0, currentCombination, combs);
    }

    double calculatePrice(const vector<int>& quality, const vector<int>& wages, const vector<int> &empIDs) {

        //search the max wage to use it as reference
        int maxWageID = -1;
        int maxWage = 0;
        for (int i = 0; i < empIDs.size(); i++) {
            if (wages[empIDs[i]] > maxWage) {
                maxWageID = empIDs[i];
                maxWage = wages[maxWageID];
            }
        }

        const double ethalonPrice = wages[maxWageID];
        const double ethalonQuality = quality[maxWageID];

        double price = 0;
        for (size_t i = 0; i < empIDs.size(); i++) {
            const int workerId = empIDs[i];
            const double ratio = quality[workerId] / ethalonQuality;
            const double workerPrice = ethalonPrice * ratio;

            if (workerPrice < wages[workerId]) {
                //this is wrong option
                return -1;
            }
            price += workerPrice;
        }
    
        return price;
    }

    double calculatePrice2(const vector<int>& quality, const vector<int>& wages, const vector<int> &empIDs) {

        double ans = 1e9;
        for (int i = 0; i < empIDs.size(); i++) {
            const int eID = empIDs[i];
            const double factor = (double)wages[eID] / quality[eID];
            double price = 0;
            for (int j = 0; j < empIDs.size(); j++) {
                const int currentID = empIDs[j];
                const double personPrice = factor * quality[currentID];
                if (personPrice < wages[currentID]) {
                    price = 0;
                    break;
                }
                price += personPrice;
            }
            if(price > 0)
                ans = min(ans, price);
        }

        return ans;
    }

public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        const int n = quality.size();

        // now we need to generate all combinations from n by k and find the chiepest combination
        vector<vector<int>> combinationsByK;
        generate(n, K, combinationsByK);

        // for every combination calculate price and locate the minimal
        int currentCombination = 0;
        double minimalPrice = -1;
        while (minimalPrice < 0 && currentCombination < combinationsByK.size()) {
            minimalPrice = calculatePrice2(quality, wage, combinationsByK[currentCombination]);
            currentCombination++;
        }

        for (size_t c = currentCombination; c < combinationsByK.size(); c++) {
            const double currentPrice = calculatePrice2(quality, wage, combinationsByK[c]);
            if (currentPrice > 0 && currentPrice < minimalPrice)
                minimalPrice = currentPrice;
        }
        return minimalPrice;
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

       int n = 0, k = 0;
       cin >> n >> k;

       vector<int> quality(n);
       vector<int> wages(n);

       for (int j = 0; j < n; j++) {
           cin >> quality[j];
       }
       for (int j = 0; j < n; j++) {
           cin >> wages[j];
       }

       Solution s;

       cout << s.mincostToHireWorkers(quality, wages, k) << endl;
   }
}