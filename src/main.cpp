#include <iostream>
#include "DArray.h"

int main()
{
    dvd::DArray<int> a = {1,2,3,4,5};

    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(10);

    a.push_back(11);
    a.push_back(12);
    a.push_back(13);
    a.push_back(14);
    a.push_back(15);
    
    
    dvd::DArray<int> b;
    dvd::DArray<int>::iterator it = a.begin();
    it+=6;
    std::cout << "*it: " << *it << std::endl;
    for (auto& i : a)
        std::cout << i << ' ';
    return 0;
}