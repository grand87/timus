#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#define DEBUG

/*
Memory allocator interface - custom implementation might be used for debug
purpose - such as mem leaks detection, etc.
*/
class MemoryAllocator {
    MemoryAllocator(const MemoryAllocator &copy) = delete;
    MemoryAllocator &operator=(const MemoryAllocator &copy) = delete;

public:
    MemoryAllocator() {}
    virtual void *allocate(size_t aSize) = 0;
    virtual void free(void *aPtr, size_t aSize) = 0;
};

class DefaultMemoryAllocator : public MemoryAllocator {
    DefaultMemoryAllocator(const DefaultMemoryAllocator &copy) = delete;
    DefaultMemoryAllocator &
        operator=(const DefaultMemoryAllocator &copy) = delete;

public:
    DefaultMemoryAllocator() {}

    ~DefaultMemoryAllocator() {}

    void *allocate(size_t aSize) override {
        return static_cast<void *>(new char[aSize]);
    }

    void free(void *aPtr, size_t /*aSize*/) override {
        delete[] static_cast<char *>(aPtr);
    }
};

/*
Memory class will encapsulate work related to track memory allocations
*/
class Memory {
    Memory(const Memory &copy) = delete;
    Memory &operator=(const Memory &copy) = delete;

public:
    Memory() : data(0), size(0), pAllocator(nullptr) {}
    ~Memory() { free(pAllocator); }

    Memory(const Memory &&copy) noexcept :
        size(std::move(copy.size)),
        data(std::move(copy.data)),
        pAllocator(std::move(copy.pAllocator))
    {
    }

    bool allocate(int aSize, MemoryAllocator *pAllocator) {
        size = aSize;
        this->pAllocator = pAllocator;
        data = pAllocator->allocate(aSize);
        return data != nullptr;
    }

    void free(MemoryAllocator *pAllocator) {
        if (data != nullptr && pAllocator != nullptr) {
            pAllocator->free(data, size);
            data = nullptr;
            size = 0;
        }
    }

    size_t getSize() const { return size; }

    void *getMemory() { return data; }

private:
    size_t size;
    void *data;
    MemoryAllocator *pAllocator;
};

/* 
Incapsulates feature to work with Memory Range in Memory object - for example with single row from 2D array
*/
class MemoryView {
    MemoryView(const MemoryView &copy) = delete;
    MemoryView &operator=(const MemoryView &copy) = delete;
public:
    MemoryView(Memory& aMemory, const vector<int> &aDimensions) : 
        memory(aMemory),
        dimensions(aDimensions),
        offset(0)
    {

    }

    MemoryView(MemoryView& aMemoryView, size_t aOffset) :
        memory(aMemoryView.memory),
        dimensions(aMemoryView.dimensions),
        offset(aOffset)
    {

    }

    float* getAddr() {
        return static_cast<float*>(memory.getMemory()) + offset;
    }

    const float* getAddr() const {
        return static_cast<float*>(memory.getMemory()) + offset;
    }

    const vector<int>& getDimensions() const {
        return dimensions;
    }

private:
    Memory& memory;
    vector<int> dimensions;
    size_t offset;
};

// class to implement storage N dimensional array representation with
// functionality to apply filters to it
class Tensor {
    Tensor(const Tensor &copy) = delete;
    Tensor &operator=(const Tensor &copy) = delete;
public:
    Tensor(const vector<int> &aDimensions) : dimensions(aDimensions) {}

    Tensor(const Tensor &&copy) noexcept :
        dimensions(std::move(copy.dimensions)),
        data(std::move(copy.data))
    {
    }

    // created separate API for a case custom memory allocator might be used
    bool init(MemoryAllocator *pAllocator) {
        size_t memorySize = 4; //4 bytes per item (to store float)
        for (size_t dim = 0; dim < dimensions.size(); dim++) {
            memorySize *= dimensions[dim];
        }
        return data.allocate(memorySize, pAllocator);
    }

    Memory& getMemory() { 
        return data;
    }

    const Memory& getMemory() const {
        return data;
    }

    const vector<int>& getDimensions() const {
        return dimensions;
    }

private:
    vector<int> dimensions;
    Memory data;
};

class Solution {
public:
    virtual vector<float> solveTask(const vector<float> &dimensions) = 0;
};

// TBD what really expected
class TrueSolution final : public Solution {
    TrueSolution(const TrueSolution &copy) = delete;
    TrueSolution &operator=(const TrueSolution &copy) = delete;

public:
    virtual vector<float> solveTask(const vector<float> &dimensions) {
        vector<float> result(dimensions.size());

        return result;
    }
};

// Just for demo purpose idea is to load Tensor input from the image.pgm file
class ExampleSolution2DTensor final : public Solution {
    ExampleSolution2DTensor(const ExampleSolution2DTensor &copy) = delete;
    ExampleSolution2DTensor &
        operator=(const ExampleSolution2DTensor &copy) = delete;

    vector<int> toIntVector(vector<float> aVector) {
        vector<int> result(aVector.size());
        for (size_t i = 0; i < aVector.size(); i++)
            result[i] = static_cast<int>(aVector[i]);
        return result;
    }

    bool loadPGMFile(const char *aFileName, Memory &memory) {
        ifstream image;
        image.open(aFileName);
        string format;
        image >> format;

        size_t sizeX, sizeY, maxValuePerDimension;
        image >> sizeX >> sizeY >> maxValuePerDimension;

        // vefiry amount of allocated memory to store tensor data
        const size_t requiredSize = sizeX * sizeY;
        if (memory.getSize() < requiredSize)
            return false;

        float *colorData = static_cast<float *>(memory.getMemory());

        // read the data
        for (size_t y = 0; y < sizeY; y++) {
            for (size_t x = 0; x < sizeX; x++) {
                const size_t position = y * sizeX + x;
                image >> colorData[position];
            }
        }

        return true;
    }

    bool savePGMFile(const char *aFileName, Memory &memory, const vector<int>& dimensions) {
        ofstream image;
        image.open(aFileName);
        string format;
        image << "P2\n";
        image << dimensions[0] << " " << dimensions[1] << "\n" << 255 << endl;

        // vefiry amount of allocated memory to store tensor data
        float *colorData = static_cast<float *>(memory.getMemory());

        // read the data
        for (size_t y = 0; y < dimensions[1]; y++) {
            for (size_t x = 0; x < dimensions[0]; x++) {
                const size_t position = y * dimensions[0] + x;
                image << (int)colorData[position] << " ";
            }
            image << endl;
        }

        return true;
    }
    
    size_t calculateOffset(const vector<int> &aDimensions, int dimension, const vector<int> &aLocation) {
        if (dimension == 1)
            return aLocation[0];
        else {
            return (aDimensions[aDimensions.size() - dimension]) * aLocation[dimension - 1] + calculateOffset(aDimensions, dimension - 1, aLocation);
        }
    }

    vector<pair<int, int>> window2D = { {0,0} ,{-1,0} ,{1,0} ,{0,-1} ,{0,1} }; // {x,y}

    void mean_(const MemoryView& source, size_t offset, size_t dimension, MemoryView& target) {
        // this is how we could go from 5D to 2D by 3D
        const int higherDimension = dimension % 3;
        
        switch (dimension) {
            case 1: {
                const float* addr = static_cast<const float*>(source.getAddr());
                float* dstAddr = static_cast<float*>(target.getAddr());

                dstAddr[0] = addr[0];
                const size_t dimensionSize = source.getDimensions()[0];

                for (size_t i = 1; i < dimensionSize - 1; i++) {
                    dstAddr[i] = (addr[i - 1] + addr[i] + addr[i + 1]) / 3;
                }
                dstAddr[dimensionSize - 1] = addr[dimensionSize - 1];
                break;
            }
            case 2: {
                
                const float* addr = source.getAddr();
                float* dstAddr = target.getAddr();

                /*
                TODO: preserve edges - copy
                */

                const size_t dimensionSizeX = source.getDimensions()[0];
                const size_t dimensionSizeY = source.getDimensions()[1];
                
                for (int y = 1; y < dimensionSizeY - 1; y++) {
                    for (int x = 1; x < dimensionSizeX - 1; x++) {
                        float sum = 0;
                        for (size_t i = 0; i < window2D.size(); i++) {
                            const size_t offset = calculateOffset(source.getDimensions(), dimension, vector<int>{x + window2D[i].first, y + window2D[i].second});
                            sum += addr[offset];
                        }
                        dstAddr[calculateOffset(source.getDimensions(), dimension, vector<int>{x, y})] = sum / window2D.size();
                    }
                }
                break;
            }
            case 3: {
                //TODO: might be covered test case like generate 10 2D images as an extension
                break;
            }
        }
    }

    void calculateMean(Tensor& source, Tensor& dest) {
        //recursively apply mean to every dimension

        const size_t dimensions = source.getDimensions().size();

        MemoryView src(source.getMemory(), source.getDimensions());
        MemoryView dst(dest.getMemory(), dest.getDimensions());

        mean_(src, 0, source.getDimensions().size(), dst);
    }

public:
    ExampleSolution2DTensor() {}

    vector<float> solveTask(const vector<float> &dimensions) override {
        vector<float> result(dimensions.size());

        DefaultMemoryAllocator memAllocator;
        Tensor t(toIntVector(dimensions));
        if (t.init(&memAllocator) == false)
            return result;
        Tensor t2(toIntVector(dimensions));
        if (t2.init(&memAllocator) == false)
            return result;

        if (loadPGMFile("image.pgm", t.getMemory()) == false)
            return result;

        calculateMean(t, t2);

        //TODO: dump memory allocated for T2 to PGM file for verification
        if (savePGMFile("image_out.pgm", t2.getMemory(), toIntVector(dimensions)) == false)
            return result;
        //TODO: dump to result vector

        return result;
    }
};

vector<float> meanFilteredTensor(vector<float> dimensions) {
#ifdef DEBUG
    ExampleSolution2DTensor solution;
#else
    TrueSolution solution;
#endif
    return solution.solveTask(dimensions);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    ostream &fout = cout;
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif
    string dimensions_count_temp;
    getline(cin, dimensions_count_temp);

    const int dimensions_count = stoi(ltrim(rtrim(dimensions_count_temp)));

    vector<float> dimensions(dimensions_count);

    for (int i = 0; i < dimensions_count; i++) {
        string dimensions_item_temp;
        getline(cin, dimensions_item_temp);

        const float dimensions_item = stof(ltrim(rtrim(dimensions_item_temp)));

        dimensions[i] = dimensions_item;
    }

    vector<float> result = meanFilteredTensor(dimensions);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << endl;

#ifdef ONLINE_JUDGE
    fout.close();
#endif
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
