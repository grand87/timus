#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

constexpr int cMaxN = 1000;

struct person {
    person() {
        visited = false;
    }
    list<int> children;
    list<int> parents;
    bool visited;
    int id;
};

person relations[cMaxN];

int findNonProcessedPerson(person* people, int size) {
    for (int i = 1; i <= size; ++i) {
        if (!people[i].visited)
            return i;
    }
    return 0;
}

int findPersonWithoutParent(person* person, int size) {
if (person->parents.size() == 0)
        return person->id;
    for (int id : person->parents) {
        return findPersonWithoutParent(&relations[id], size);
    }
    return 0;
}

int process(person* person, int size) {
    if (!person->visited) {
        person->visited = true;

        //remove itself from all children
        for (int id : person->children) {
            relations[id].parents.remove(person->id);
        }

        cout << person->id << endl;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif`
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;

    for (int parentID = 1; parentID <= n; ++parentID) {
        relations[parentID].id = parentID;

        int childId = 0;
        while(true) {
            cin >> childId;
            if (childId != 0) {
                relations[parentID].children.push_back(childId);
                relations[childId].parents.push_back(parentID);
            }
            else
                break;
        } 
    }

    while (true) {
        int personId = findNonProcessedPerson(relations, n);
        if (personId == 0)
            break;

        int rootId = findPersonWithoutParent(&relations[personId], n);
        process(&relations[rootId], n);
        if (rootId == 0)
            break;
    }

    return 0;
}  