/*
 * @author v.sharaienko (grandamx@gmail.com)
 */

#pragma comment(linker, "/STACK:16777216")

#include <array>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//#define ONLINE_JUDGE

const array<string, 4> kFaculties = {"Slytherin",
                             "Hufflepuff",
                             "Gryffindor",
                             "Ravenclaw"};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif
    
    int studentsCount;
    cin >> studentsCount;

    map<string, vector<string>> studentsFaculty;

    string studentName;
    string faculty;

    for (int i = 0; i < studentsCount; i++) {      
        cin.ignore();
        getline(cin, studentName);
        cin >> faculty;

        studentsFaculty[faculty].push_back(studentName);
    }

    for (auto& facultyName : kFaculties) {
        cout << facultyName << ":" << endl;
        for (auto& name : studentsFaculty[facultyName]) {
            cout << name << endl;
        }
        cout << endl;
    }

    return 0;
}
 