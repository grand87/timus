/**
    @brief task description link http://acm.timus.ru/problem.aspx?space=1&num=1837
    
    @author Volodymyr Sharayenko
    @mail grand87@yandex.ru
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

const int MAX_NAME_LENGTH = 21;
const int MAX_USERS = 4 * 100;

struct user
{
    user()
    {
        name[0] = 0;
        name_length = 0;
        distance = -1;
    }

    user(const char* name)
    {
        set(name);
        distance = -1;
    }

    void set(const char* name)
    {
        strcpy(this->name, name);
        name_length = strlen(name);
    }

    char name[MAX_NAME_LENGTH];
    int name_length;
    int distance;
};

int findUser(const char* name, int count, const user* users)
{
    const int size = strlen(name);

    for (int i = 0; i < count; ++i)
    {
        if (users[i].name_length == size && strcmp(users[i].name, name) == 0)
            return i;
    }
    return -1;
}

void addConnection(vector<int> *connections, int v1, int v2)
{
    connections[v1].push_back(v2);
    connections[v2].push_back(v1);
}

void calculateDistances(int rootVertex, const vector<int> *connections, user* users, int usersCount)
{
    bool visited[MAX_USERS];
    memset(visited, 0, MAX_USERS);

    list<int> toVisit;
    toVisit.push_back(rootVertex);
    while (toVisit.size())
    {
        const int currentVertex = toVisit.front();
        toVisit.pop_front();
        visited[currentVertex] = true;
        const int distance = users[currentVertex].distance + 1;

        for (vector<int>::const_iterator it = connections[currentVertex].begin(); it != connections[currentVertex].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                toVisit.push_back(*it);
                if(users[*it].distance == -1 || users[*it].distance > distance)
                    users[*it].distance = distance;
            }
        }
//        cout << "Visited " << users[currentVertex].name << " " << users[currentVertex].distance << endl;
    }
}

bool toLeft(const user& a, const user& b)
{
    less<string> cmp;
    return cmp(a.name, b.name);
}

int main()
{
    setbuf(stdout, NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    int users = 0;
    user all_users[MAX_USERS];

    int teamsCount;
    std::cin >> teamsCount;

    vector<int> connections[MAX_USERS];

    for (int i = 0; i < teamsCount; ++i)
    {
        char name[MAX_NAME_LENGTH];
        int connected[3];

        for (int n = 0; n < 3; ++n)
        {
            cin >> name;
            int userID = findUser(name, users, all_users);
            if (userID == -1)
            {
                userID = users;
                all_users[userID].set(name);
                connected[n] = userID;
                ++users;
            }
            else
                connected[n] = userID;
        }

        //define connections
        addConnection(connections, connected[0], connected[1]);
        addConnection(connections, connected[1], connected[2]);
        addConnection(connections, connected[0], connected[2]);
    }

    int rootID = findUser("Isenbaev", users, all_users);
    all_users[rootID].distance = 0;
    calculateDistances(rootID, connections, all_users, users);

    sort(all_users, all_users + users, &toLeft);

    for (int i = 0; i < users; ++i)
    {
        cout << all_users[i].name << " ";
        if (all_users[i].distance == -1)
            cout << "undefined\n";
        else
            cout << all_users[i].distance << endl;
    }
}
