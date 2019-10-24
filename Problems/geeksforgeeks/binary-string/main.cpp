#include<fstream>
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

const int MAX_STR_LEN = 10000;

int solution(char* str, int size) {
    static int buf[MAX_STR_LEN] {0};
    int count = 0;
    for (int i = size - 1; i > 0; i--) {
        count += str[i] == '1';
        buf[i] = count;
    }

    int result = 0;
    for (int i = 0; i < size - 1; i++) {
        if (str[i] == '1') {
            result += buf[i + 1];
        }
    }

    return result;
}

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    int t;
    cin >> t;

    char buf[MAX_STR_LEN + 1];

    for (int i = 0; i < t; i++) {
        int size;
        cin >> size >> buf;
        cout << solution(buf, size) << endl;
    }
    return 0;
}