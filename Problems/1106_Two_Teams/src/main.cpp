/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

//#define ONLINE_JUDGE

const int MAX_GROUP_SIZE = 101;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int groupSize = 0;

    typedef pair<int, int> Friends;
    typedef vector<Friends> FriendsList;


    FriendsList friendsList;

    int friendsMap[MAX_GROUP_SIZE][MAX_GROUP_SIZE];
    for(int i = 0; i < MAX_GROUP_SIZE; ++i)
        for(int j = 0; j < MAX_GROUP_SIZE; ++j)
            friendsMap[i][j] = 0;

    scanf("%d", &groupSize);
    int friendNumber = 0;
    for(int member = 1; member <= groupSize; ++member) {
        while(true) {
            scanf("%d", &friendNumber);
            if(friendNumber > 0) {
                if(friendsMap[friendNumber][member] == 0) {
                    friendsMap[member][friendNumber] = friendNumber;
                    friendsList.push_back(Friends(member, friendNumber));
                }
            } else {
                break;
            }
        }
    }

    typedef map<int, int> Groups;
    Groups groups;
    
    for(FriendsList::iterator it = friendsList.begin(); it != friendsList.end(); ++it) {
        if(groups.find(it->first) == groups.end() && groups.find(it->second) == groups.end()) {
            groups[it->first] = false;
            groups[it->second] = true;
        } else {
            if(groups.find(it->first) == groups.end()) {
                groups[it->first] = !groups[it->second];
            } else {
                groups[it->second] = !groups[it->first];
            }
        }
    }

    int group1Size = 0;
    int group2Size = 0;

    for(Groups::iterator it = groups.begin(); it != groups.end(); ++it) {
        if(it->second == 0) {
            friendsMap[0][group1Size++] = it->first;
        } else {
            friendsMap[1][group2Size++] = it->first;
        }

    }

    if(group1Size == 0 || group1Size == groupSize) {
        printf("%d\n", group1Size);
        return 0;
    }

    int *firstGroup = group1Size > group2Size ? friendsMap[0] : friendsMap[1];
    groupSize = group1Size > group2Size ? group1Size : group2Size;

    printf("%d\n", groupSize);
    for(int i = 0; i < groupSize; ++i) {
        printf("%d ", firstGroup[i]);
    }

    return 0;
}

