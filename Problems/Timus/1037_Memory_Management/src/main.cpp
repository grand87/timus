/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>

using namespace std;

// #define ONLINE_JUDGE

struct block {
    block() {
        end_time = -1;
    }

    int end_time;
};

class manager {
    static const int max_block = 30001;
    static const int max_life_time = 10 * 60;
    block memory[max_block];

    int lastTime = 0;
    int lastFree = 1;

public:
    manager() {
    }

    int allocate(int time) {
        // need to evaluate all requested blocks & free block where was no access for a period of time
        // and this block should be return
        int block_id = lastTime == time ? lastFree : 1;
        for (; block_id < max_block; ++block_id) {
            if (memory[block_id].end_time <= time) {
                break;
            }
        }

        memory[block_id].end_time = time + max_life_time;

        lastTime = time;
        lastFree = block_id;

        return block_id;
    }

    bool is_availible(int time, int block_id) {
        if (memory[block_id].end_time > time) {
            memory[block_id].end_time = time + max_life_time;
            return true;
        }
        return false;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif

    manager manager;

    int time;
    char operation;
    int block_id;

    while (scanf("%d %c", &time, &operation) != EOF) {
        if (operation == '+') {
            block_id = manager.allocate(time);
            printf("%d\n", block_id);
        } else {
            scanf("%d", &block_id);
            bool result = manager.is_availible(time, block_id);
            printf("%s\n", result ? "+" : "-");
        }
    }

    return 0;
}