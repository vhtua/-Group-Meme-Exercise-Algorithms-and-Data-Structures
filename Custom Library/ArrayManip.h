#pragma once

#include <unordered_set>
#include <set>

void removeValue(int*& arr, int n, int val)
{
    int temp[n] = { 0 };
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

    arr = new int[size]();

    for (int i = 0; i < size; ++i)
    {
        arr[i] = temp[i];
    }
}

void removeDuplicate(int*& arr, int n)
{
    std::set<int> temp;

    for (int i = 0; i < n; ++i)
    {
        temp.insert(arr[i]);
    }

    delete[] arr;

    arr = new int[temp.size()];

    std::set<int>::iterator iter;

    int index = 0;

    for (iter = temp.begin(); iter != temp.end(); ++iter)
    {
        arr[index] = *iter;
        ++index;
    }
}

int countDistinct(int*& arr, int n)
{
    std::unordered_set<int> temp;

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