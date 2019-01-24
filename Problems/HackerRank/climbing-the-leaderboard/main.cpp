#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    //need to remove duplicates
    std::set<int> uniqueScores;
    
    for (int i = 0; i < scores.size(); i++) {
        uniqueScores.insert(scores[i]);
    }

    std::set<int> uniqueGames;

    for (int i = 0; i < alice.size(); i++) {
        uniqueGames.insert(alice[i]);
    }

    vector<int> result(alice.size());

    //find first player with higher rank
    int lastPos = 0;
    std::set<int>::iterator greaterThanAlise = std::begin(uniqueScores);
    for (int i = 0; i < uniqueGames.size(); i++) {
        if (i > 0 && uniqueGames[i] == uniqueGames[i - 1]) {
            result[i] = result[i - 1];
            continue;
        }

        greaterThanAlise = std::upper_bound(greaterThanAlise, std::end(uniqueScores), uniqueGames[i]);

        if (greaterThanAlise == std::end(uniqueScores)) {
            //Alise is 1st
            result[i] = 1;
        } else {
            int rank = std::distance(greaterThanAlise, uniqueScores.end());
            lastPos = rank;
            result[i] = rank + 1;
        }
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    ofstream fout("out.txt");

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

