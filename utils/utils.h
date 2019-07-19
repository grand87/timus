#ifndef __PROBLEMS_UTILS_H__
#define __PROBLEMS_UTILS_H__

#include <vector>
#include <iostream>

template<typename T>
void readVector(std::istream& is, std::vector<T>& vec, int count) {
    for (int i = 0; i < count; i++) {
        is >> vec[i];
    }
};


#endif /*__PROBLEMS_UTILS_H__*/