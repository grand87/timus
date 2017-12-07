#include <iostream>

const char* namesLocations[] =
{
    "Alice",    // 0
    "Ariel",
    "Aurora",
    "Phil",
    "Peter",
    "Olaf",
    "Phoebus",
    "Ralph",
    "Robin",    // 8

    "Bambi",    // 9
    "Belle",
    "Bolt",
    "Mulan",
    "Mowgli",
    "Mickey",
    "Silver",
    "Simba",
    "Stitch",   // 17

    "Dumbo",    // 18
    "Genie",
    "Jiminy",
    "Kuzko",
    "Kida",
    "Kenai",
    "Tarzan",
    "Tiana",
    "Winnie"    // 26
};

int getShelve(const char* name)
{
    for (int i = 0; i < 18; ++i)
    {
        if (strcmp(name, namesLocations[i]) == 0)
        {
            return i < 9 ? 0 : 1;
        }
    }

    return 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int n;
    std::cin >> n;

    char name[10] = "";

    int currentShelve = 0;
    int steps = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> name;
        int shelfForRecipient = getShelve(name);

        if (currentShelve != shelfForRecipient)
        {
            steps += abs(currentShelve - shelfForRecipient);
            currentShelve = shelfForRecipient;
        }

    }

    std::cout << steps;
}
