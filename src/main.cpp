#include <iostream>
#include "DArray.h"

// Quicksort Darray



template<typename T>
int partition(dvd::DArray<T>& arr,int low,int high)
{
    int partIndex = low;
    T pivot = arr[high - 1];

    if (low < high)
    {
        for (int i = low; i < high; i++)
        {
            if (arr[i] < pivot)
            {
                // Swap
                T temp = arr[partIndex];
                arr[partIndex] = arr[i];
                arr[i] = temp;

                partIndex++; 
            }
        }
    }


    // swap
    T temp = arr[partIndex];
    arr[partIndex] = arr[high-1];
    arr[high-1] = temp;
    
    return partIndex;
}

template<typename T>
void QuickSort(dvd::DArray<T>& arr,int low,int high)
{
    if(low < high)
    {
        int p = partition(arr,low,high);

        QuickSort(arr,low,p);
        QuickSort(arr,p+1,high);
    }
}


int main()
{
    dvd::DArray<int> a = {5,1,3,2,4};

    // a.push_back(6);
    // a.push_back(7);
    // a.push_back(8);
    // a.push_back(9);
    // a.push_back(10);
    a.push_back(2);
    a.push_back(5);
    // a.push_back(11);
    // a.push_back(12);
    // a.push_back(13);
    // a.push_back(14);
    // a.push_back(15);
    
    
    dvd::DArray<int> b;
    dvd::DArray<int>::iterator it = a.begin();
    it+=6;
    std::cout << "*it: " << *it << std::endl;
    for (auto& i : a)
        std::cout << i << ' ';
    QuickSort(a,0,a.Size());
    std::cout << std::endl;
    for (auto& i : a)
        std::cout << i << ' ';
    return 0;
}