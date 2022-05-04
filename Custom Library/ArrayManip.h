#pragma once

#include <unordered_set>
#include <set>

template <typename T>
int removeValue(T*& arr, int n, T val)
{
    T temp[n] = { 0 };
    int size = 0;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != val)
        {
            temp[i] = arr[i];
            ++size;
        }
    }

    delete[] arr;

    arr = new T[size]();

    for (int i = 0; i < size; ++i)
    {
        arr[i] = temp[i];
    }

    return size;
}

template<typename T>
int removeDuplicate(T*& arr, int n)
{
    std::set<T> temp;

    for (int i = 0; i < n; ++i)
    {
        temp.insert(arr[i]);
    }

    delete[] arr;

    arr = new T[temp.size()];

    typename std::set<T>::iterator iter;

    int index = 0;

    for (iter = temp.begin(); iter != temp.end(); ++iter)
    {
        arr[index] = *iter;
        ++index;
    }

    return (int)temp.size();
}

template<typename T>
int countDistinct(T*& arr, int n)
{
    std::unordered_set<T> temp;

    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (temp.find(arr[i]) == temp.end())
        {
            temp.insert(arr[i]);
            ++count;
        }
    }

    return count;
}