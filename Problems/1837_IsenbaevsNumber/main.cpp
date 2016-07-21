/**
    @brief task description link http://acm.timus.ru/problem.aspx?space=1&num=1837
    
    @author Volodymyr Sharayenko
    @mail grand87@yandex.ru
*/

#include <iostream>
#include <string>
#include <map>

struct UserMatrix
{
    UserMatrix(int aSize, int defaultValue = 0) : size(aSize)
    {
        matrix = new int*[size];
        for (int user = 0; user < size; ++user)
        {
            matrix[user] = new int[size];
            for (int u = 0; u < size; ++u)
                matrix[user][u] = defaultValue;
        }
    }

    ~UserMatrix()
    {
        if (matrix != 0)
            for (int user = 0; user < size; ++user)
                delete[] matrix[user];
            delete[] matrix;
            matrix = 0;
    }

    void dump(int userCount)
    {
        for (int user = 0; user < userCount; ++user)
        {
            for (int u = 0; u < userCount; ++u)
                std::cout << matrix[user][u] << " ";
            std::cout << std::endl;
        }
    }

    int size;
    int** matrix;
};

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

int main()
{
    setbuf(stdout, NULL);
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
    
    // create adjacency matrix
    UserMatrix *linksMatrix = new UserMatrix(maxUsers);

    int isenbaevIdx = -1;

    for (char i = 0; i < teamsCount; ++i)
    {
        bool isenbaevHere = false;

        // read team content
        for (int i = 0; i < 3; ++i)
        {
            std::cin >> name[i];

            //generate unique ID for user
            if (userIds.find(name[i]) == userIds.end())
            {
                userIds[name[i]] = userIds.size();
                if (strcmp(name[i], "Isenbaev") == 0)
                {
                    isenbaevIdx = userIds.size();
                }
            }

            //if (strcmp(name[i], "Isenbaev") == 0)
            //{
            //    isenbaevHere = true;
            //    if (isenbaevIdx == -1)
            //    {
            //        
            //    }
            //}
        }

        //for (int i = 0; i < 3; ++i)
        //{
        //    int uID = userIds[name[i]];

        //    // update links matrix
        //    for (int j = 0; j < 3; ++j)
        //    {
        //        if (i != j)
        //        {
        //            int neiberID = userIds[name[j]];
        //            links[uID][neiberID] = 1;
        //            //links[neiberID][uID] = 1;
        //        }
        //    }
        //}
    }

    linksMatrix->dump(userIds.size());

    //for (auto user : userIds)
    //{
    //    auto value = getIValue(links, user.second, isenbaevIdx, userIds.size());
    //    std::cout << "[" << user.second << "]" << user.first.c_str() << " " << value << std::endl;
    //}

    delete linksMatrix;
}