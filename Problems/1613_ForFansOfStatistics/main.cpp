#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct city
{
    int id;
    long population;
};

bool cityComp(const city& a, const city& b)
{
    return a.population < b.population;
}

const int MAX_C = 70000;
city world[MAX_C];

typedef vector<int> Cities;

struct histogramItem
{
    histogramItem()
    {
        sorted = false;
    }

    bool sorted;
    long population;
    Cities cities;
};

template<typename T>
T* bst(T* w, long population, int left, int right)
{
    if (population < w[left].population || population > w[right].population)
        return 0;

    if (w[left].population == population)
        return &w[left];

    if (w[right].population == population)
        return &w[right];

    const int mediana = left + (right - left) / 2;
    if (w[mediana].population == population)
        return &w[mediana];

    if (w[mediana].population < population)
        return bst(w, population, mediana + 1, right);
    if (w[mediana].population > population)
        return bst(w, population, left, mediana - 1);

    return 0;
}

bool bst_interval(const Cities& data, int left, int right, int a, int b)
{
    if (a > data[right])
        return false;
    if (b < data[left])
        return false;

    if (a == data[left])
        return true;
    if (b == data[left])
        return true;
    if (a == data[right])
        return true;
    if (b == data[right])
        return true;

    int mediana = left + (right - left) / 2;
    if (data[mediana] >= a && data[mediana] <= b)
        return true;
    if (data[mediana] < a)
        return bst_interval(data, mediana + 1, right, a, b);
    if (data[mediana] > b)
        return bst_interval(data, left, mediana - 1, a, b);

    return 0;
}

histogramItem populationHistogram[MAX_C];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int cities;
    cin >> cities;
    for (int i = 0; i < cities; ++i)
    {
        world[i].id = i + 1;
        cin >> world[i].population;
    }
    sort(world, world + cities, &cityComp);

    //build population histogram
    int uniquePopulation = 1;
    populationHistogram[0].population = world[0].population;
    populationHistogram[0].cities.push_back(world[0].id);

    for (int i = 1; i < cities; i++)
    {
        if (world[i].population != world[i - 1].population)
        {
            populationHistogram[uniquePopulation].population = world[i].population;
            populationHistogram[uniquePopulation].cities.push_back(world[i].id);
            ++uniquePopulation;
        }
        else
            populationHistogram[uniquePopulation - 1].cities.push_back(world[i].id);
    }

    int quries;
    cin >> quries;

    for (int i = 0; i < quries; ++i)
    {
        int l, r;
        long population;
        cin >> l >> r >> population;

        histogramItem* c = bst(populationHistogram, population, 0, uniquePopulation - 1);
        bool located = false;
        if (c)
        {
            if (!c->sorted)
            {
                c->sorted = true;
                sort(c->cities.begin(), c->cities.end());
            }

            // implementation for search interval in the sorted array
            located = bst_interval(c->cities, 0, c->cities.size() - 1, l, r);
        }
        cout << (located ? "1" : "0");
    }
}