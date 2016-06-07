#include <iostream>
#include <string>
#include <map>

int** generateUserLinksMatrix(int teamCount)
{
    // could be optimized
    const int maxUsers = teamCount * 3;

    int** res = new int* [maxUsers];

    for (int user = 0; user < maxUsers; ++user)
    {
        res[user] = new int [maxUsers];

        for (int u = 0; u < maxUsers; ++u)
        {
            res[user][u] = 0;
        }
    }

    return res;
}

int getIValue(int** links, int userIdx, int isenbaevIdx, int userCount)
{
    // need to find path to Isenbayev
    if (userIdx == isenbaevIdx)
    {
        return 0;
    }

    for (int i = 0 ; i < userCount; ++i)
    {
        if (i != userIdx)
        {
            if (links[userIdx][i] != 0 && i == isenbaevIdx)
            {
                return 1;
            }
            else
            {
                if (links[userIdx][i] != 0)
                {
                    return 1 + getIValue(links, i, isenbaevIdx, userCount);
                }
            }
        }
    }

    return -1;
}

void dumpLinks(int** links, int userCount)
{
    for (int user = 0; user < userCount; ++user)
    {
        for (int u = 0; u < userCount; ++u)
        {
            std::cout << links[user][u] << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int teamsCount;
    std::cin >> teamsCount;

    char name[3][21] = { "", "", "" };

    typedef std::map<std::string, int> UserIds;
    UserIds userIds;

    // could be optimized
    const int maxUsers = teamsCount * 3;

    int** links = generateUserLinksMatrix(teamsCount);
    int isenbaevIdx = -1;

    for (char i = 0; i < teamsCount; ++i)
    {
        bool isenbaevHere = false;

        for (int i = 0; i < 3; ++i)
        {
            std::cin >> name[i];

            //generate unique ID for user
            if (userIds.find(name[i]) == userIds.end())
            {
                userIds[name[i]] = userIds.size();
            }

            if (strcmp(name[i], "Isenbaev") == 0)
            {
                isenbaevHere = true;

                if (isenbaevIdx == -1)
                {
                    isenbaevIdx = userIds[name[i]];
                }
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            int uID = userIds[name[i]];

            // update links matrix
            for (int j = 0; j < 3; ++j)
            {
                if (i != j)
                {
                    int neiberID = userIds[name[j]];
                    links[uID][neiberID] = 1;
                    //links[neiberID][uID] = 1;
                }
            }
        }
    }

    dumpLinks(links, userIds.size());

    for (auto user : userIds)
    {
        auto value = getIValue(links, user.second, isenbaevIdx, userIds.size());
        std::cout << "[" << user.second << "]" << user.first.c_str() << " " << value << std::endl;
    }
}