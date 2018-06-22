#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <tuple>
#include <string>

template<typename T>
class Array
{
public:
    Array(unsigned int size);

    bool add(T item);

    bool add(T item, unsigned int index);

    bool remove(unsigned int index);

    T get(unsigned int index);

    T operator[](unsigned int index);

    //friend std::ostream& operator<<(std::ostream& os, const Array<T>& array);
protected:
    //
private:
    std::vector<T*> array;
    unsigned int lastIndex = 0;
    bool sorted = false;
};

//template<typename T>
//std::ostream& operator<<(std::ostream& os, const Array<T>& array);