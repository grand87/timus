#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string names[100000];

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int candidates;
        cin >> candidates;
        for (int i = 0; i < candidates; i++)
            cin >> names[i];

        unordered_map<string, int> votes;
        for (int i = 0; i < candidates; i++)
            votes[names[i]]++;

        unordered_map<int, vector<string>> votesRev;

        //sort(votes.begin(), votes.end(), [](const pair<string, int>& a, const pair<string, int>& b) -> bool { 
        //    if (a.second > b.second)
        //        return true;
        //    if (a.second == b.second) {
        //        return strcmp(a.first.c_str(), b.first.c_str()) < 0;
        //        }
        //    return false;
        //});

        int maxCount = 0;
        for (auto& v : votes) {
            votesRev[v.second].push_back(v.first);
            maxCount = max(maxCount, v.second);
        }

        vector<string>& maxVotesNames = votesRev[maxCount];
        sort(maxVotesNames.begin(), maxVotesNames.end());

        cout << maxVotesNames[0] << endl;
    }
    return 0;
}