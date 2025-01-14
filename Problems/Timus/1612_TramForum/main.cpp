/*
 * @author v.sharaienko (grandamx@gmail.com)
 */

#pragma comment(linker, "/STACK:16777216")

#include <array>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// #define ONLINE_JUDGE

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif

    string word;
    string text;
    text.reserve(11000);

    int trams = 0;
    int trolleybus = 0;

    while (cin >> word) {
        for (char& c : word) {
            switch (c) {
                case '.':
                case ',':
                case '?':
                case '!':
                case ':':
                case '-':
                    c = ' ';
            }
        }
        text += " " + word;
    }

    stringstream ss(text);
    while (ss >> word) {
        if (word.size() == 4) {
            // test for tram
            if (word == "tram") {
                trams++;
            }
        } else if (word.size() == 10) {
            // test for Trolleybus 
            if (word == "trolleybus") {
                trolleybus++;
            }
        }
    }

    if (trams > trolleybus) {
        cout << "Tram driver";
    } else if (trams < trolleybus) {
        cout << "Trolleybus driver";
    } else {
        cout << "Bus driver";
    }

    return 0;
}
