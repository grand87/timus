#include <stdio.h>

using namespace std;

const int MaxSize = 1000 + 2;

char a[MaxSize][MaxSize];
int countersPerLine[MaxSize][2];
int countersPerRow[MaxSize][2];

int commands[MaxSize][2];

void readField(int fieldSize) {
    for (int i = 0; i < fieldSize; i++) {
        scanf("%s", &a[i]);
    }
}

void dumpField(int fieldSize) {
    for (int i = 0; i < fieldSize; i++) {
        printf("%s", &a[i]);

        printf(" %d %d\n", countersPerLine[i][0], countersPerLine[i][1]);
    }
    
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < fieldSize; i++) {
            printf("%d ", countersPerRow[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

bool updateCounters(int fieldSize) {
    // use one counter istead of 2
    for (int i = 0; i < fieldSize; i++) {
        countersPerLine[i][0] = 0;
        countersPerLine[i][1] = 0;
        countersPerRow[i][0] = 0;
        countersPerRow[i][1] = 0;
    }

    int totalCounts[2] = {0, 0};

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if (a[i][j] == 'B') {
                countersPerLine[i][0]++;
                countersPerRow[j][0]++;
                totalCounts[0]++;
            } else {
                countersPerLine[i][1]++;
                countersPerRow[j][1]++;
                totalCounts[1]++;
            }
        }
    }

    return totalCounts[0] == 0 || totalCounts[1] == 0;
}

int findNextCell(int fieldSize, int& x, int& y) {
    int currentMax = 0;
    x = 0;
    y = 0;

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if ((countersPerLine[i][0] + countersPerRow[j][0] > currentMax) && a[i][j] == 'B') {
                currentMax = countersPerLine[i][0] + countersPerRow[j][0];
                y = i;
                x = j;
            }
            if ((countersPerLine[i][1] + countersPerRow[j][1] > currentMax) && a[i][j] == 'W') {
                currentMax = countersPerLine[i][1] + countersPerRow[j][1];
                y = i;
                x = j;
            }
        }
    }
    return currentMax;
}

void inverseField(int fieldSize, int x, int y) {
    for (int i = 0; i < fieldSize; i++) {
        if (a[y][i] == 'B') {
            a[y][i] = 'W';
        } else {
            a[y][i] = 'B';
        }
    }
#ifndef ONLINE_JUDGE
    //dumpField(fieldSize);
#endif
    for (int i = 0; i < fieldSize; i++) {
        if (a[i][x] == 'B') {
            a[i][x] = 'W';
        } else {
            a[i][x] = 'B';
        }
    }

    if (a[y][x] == 'B') {
        a[y][x] = 'W';
    } else {
        a[y][x] = 'B';
    }
#ifndef ONLINE_JUDGE
    //dumpField(fieldSize);
#endif
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif

    int fieldSize = 0;
    scanf("%d", &fieldSize);
    readField(fieldSize);

    int commandsCount = 0;
    while (commandsCount < MaxSize) {
        if (updateCounters(fieldSize)) {
            break;
        }
#ifndef ONLINE_JUDGE
        dumpField(fieldSize);
#endif
        // locate next cell to trigger inversion
        findNextCell(fieldSize, commands[commandsCount][0], commands[commandsCount][1]); 

        // inverse line & row
        inverseField(fieldSize, commands[commandsCount][0], commands[commandsCount][1]);
#ifndef ONLINE_JUDGE
        updateCounters(fieldSize);
        dumpField(fieldSize);
#endif
        commandsCount++;
    }

    printf("%d\n", commandsCount);
    for (int i = 0; i < commandsCount; i++) {
        printf("%d %d\n", commands[i][1] + 1, commands[i][0] + 1);
    }
    
    return 0;
}