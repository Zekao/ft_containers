#include <stack>
#include <map>
#include <vector>
#include "vector.hpp"
#include <iostream>
#include "stack.hpp"
#define Buffer std::string
int	main(void)
{
    std::cout << "===== real vector =====" << std::endl;
    std::vector<int> a;
    std::vector<int>::iterator  std_it;

    std_it = a.begin();
    std::cout << "is it empty? : " << a.empty() << std::endl;
    std::cout << "size : " << a.size() << std::endl;
    std::cout << "max size : " << a.max_size() << std::endl;
    std::cout << "capacity of vector : " << a.capacity() << std::endl;
    a.reserve(15);
    a.resize(16);
    std::cout << "new capacity of vector : " << a.capacity() << std::endl;

    std::cout << "=====  my vector =====" << std::endl;
    ft::vector<int> b;
    std::cout << "is it empty? : " << b.empty() << std::endl;
    std::cout << "size : " << b.size() << std::endl;
    std::cout << "max size : " << b.max_size() << std::endl;
    std::cout << "capacity of vector : " << b.capacity() << std::endl;
    b.reserve(15);
    b.resize(16);
    std::cout << "new capacity of vector : " << b.capacity() << std::endl;
    // std::cout << "capacity of vector : " << b.capacity() << std::endl;
}