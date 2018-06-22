#include "Datastruct.hpp"

template<typename T>
Array<T>::Array(unsigned int size = 0)
{
    // Size can't be less than 0, if so return
    if (size < 0)
        return;

    // Reserve the requested number of items and set all to nullptr
    this->array.reserve(size);
    for (int i = 0; i < this->array.size(); i++)
        this->item[i] = nullptr;
}

template<typename T>
bool Array<T>::add(T item)
{
    if (index >= this->array.size() || this->array[index] != nullptr)
        return false;
    
    this->array.insert(this->array.begin() + index, new T);
    return true;
}

template<typename T>
bool Array<T>::add(T item, unsigned int index = -1)
{
    if (index >= this->array.size() || this->array[index] != nullptr)
        return false;
    
    this->array.insert(this->array.begin() + index, new T);
    return true;
}

template<typename T>
bool Array<T>::remove(unsigned int index)
{
    if (index >= this->array.size())
        return false;

    delete this->array[index];
    this->array[index] = nullptr;
    return true;
}

template<typename T>
T Array<T>::get(unsigned int index)
{
    if (index < this->array.size())
        return this->array[index];
    return nullptr;
}

template<typename T>
T Array<T>::operator[] (unsigned int index)
{
    return this->get(index);
}

/*template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array)  
{  
    os << std::string("{ ");
    for (auto& item : array)
    {
        os << *(item) << ((item == array[array.size() - 1]) ? "" : ", ");
    }
    os << std::string(" }");
    return os;
}*/