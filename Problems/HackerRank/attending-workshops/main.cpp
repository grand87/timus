#include <iostream>
#include <algorithm>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
    int startTime;
    int duration;
    int endTime;
};

struct Available_Workshops {
    int numberWorkshops;
    Workshop* pWorkshops;
};

Workshop workshopsPool[100001];
Available_Workshops gWorkshops;

Available_Workshops* initialize(int *startTimes, int *durations, int n) {
    for (int i = 0; i < n; i++) {
        workshopsPool[i].startTime = startTimes[i];
        workshopsPool[i].duration = durations[i];
        workshopsPool[i].endTime = startTimes[i] + durations[i];
    }
    gWorkshops.numberWorkshops = n;
    gWorkshops.pWorkshops = workshopsPool;

    return &gWorkshops;
}

bool sortFunctor(const Workshop& w1, const Workshop& w2) {
    return w1.endTime < w2.endTime;
}

int CalculateMaxWorkshops(const Available_Workshops* workshops) {
    //preprocessing - sort all workshops by it's end time

    sort(workshops->pWorkshops, workshops->pWorkshops + workshops->numberWorkshops, sortFunctor);

    int ans = 0, cursor = 0;
    for (int i = 0; i < workshops->numberWorkshops; i++) {
        if (workshops->pWorkshops[i].startTime >= cursor) {
            ans++;
            cursor = workshops->pWorkshops[i].endTime;
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
