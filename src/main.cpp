#include <iostream>
#include "DArray.h"

int main()
{
    dvd::DArray<int> a;
    int b[]{6,7,8,9,10,11,12,13,14,15};
    a.extend_element(b);

    // dvd::DArray<int> c = {16,17,18,19,20,21,22,23,24,25};
    // a.extend_element(c);
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;
    std::cout << "Popped out: " << a.pop_back() << std::endl;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
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
    return 0;
}