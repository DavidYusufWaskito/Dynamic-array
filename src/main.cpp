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
    dvd::DArray<int> a = {1,2,3,4,5};
    dvd::DArray<int> b = {6,7,8,9,10,11,12,13,14,15};

    a.extend_element(b);
    // a.push_back(6);
    // a.push_back(7);
    // a.push_back(8);
    // a.push_back(9);
    // a.push_back(10);
    // a.push_back(11);
    // a.push_back(12);
    // a.push_back(13);
    // a.push_back(14);
    // a.push_back(15);
    
    
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