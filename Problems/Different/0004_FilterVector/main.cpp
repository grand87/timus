#include <algorithm>
#include <iostream>
#include <vector>

struct mystruct {
    int id;
    std::string name;
};

int main() {
    std::vector<mystruct> all_items {
        {151, "test1"},
        {154, "test4"},
        {152, "test2"},
        {151, "test1"},
        {151, "test1"},
        {153, "test3"}
    };
    const std::vector<int> bad_ids = {
        151,
        152
    };

    
    auto filteredEnd = std::partition(
        all_items.begin(), all_items.end(), [&bad_ids](const mystruct& record) -> bool {
        return std::find(bad_ids.begin(), bad_ids.end(), record.id) == bad_ids.end();
    });

    for (auto it = all_items.begin(); it != filteredEnd; it++) {
        std::cout << "Good item: " << it->id << std::endl;
    }

    return 0;
}