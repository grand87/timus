#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <utils.h>

#define DEBUG

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort1 function below.
void insertionSort1(int n, vector<int> arr) {
    const int tmp = arr[n - 1];
    int i = n - 2;
    for (; i >= 0; i--) {
        if (arr[i] > tmp) {
            arr[i + 1] = arr[i];
        } else {
            arr[i + 1] = tmp;
            break;
        }
        printVector(cout, arr);
        cout << endl;
    }
    if (i == -1 && arr[0] > tmp) {
        arr[0] = tmp;
    }
    printVector(cout, arr);
    cout << endl;
}

int main()
{
#ifdef DEBUG
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);
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