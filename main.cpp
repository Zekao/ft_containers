#include <stack>
#include <map>
#include <vector>
#include "vector.hpp"
#include <iostream>
#include "stack.hpp"
#include "iterators/iterator.hpp"
#include "iterators/iterators_traits.hpp"
#include "iterators/random_access_iterator.hpp"

int	main(void)
{
    std::cout << "===== real vector =====" << std::endl;
    std::vector<int> a;
    std::vector<int>::iterator  std_it;

    std::cout << "is it empty? : " << a.empty() << std::endl;
    std::cout << "size : " << a.size() << std::endl;
    std::cout << "max size : " << a.max_size() << std::endl;
    std::cout << "capacity of vector : " << a.capacity() << std::endl;
    a.reserve(15);
    a.resize(16);
    std::cout << "size before: " << a.size() << std::endl;
    a.clear();
    a.assign(12, 100);
    std::cout << "size after: " << a.size() << std::endl;
    std::cout << "new capacity of vector : " << a.capacity() << std::endl;
    std_it = a.begin();
    a.insert(std_it, 42);
    std::cout << "value of first element : " << a.at(0) << std::endl;

    std::cout << "=====  my vector =====" << std::endl;
    ft::vector<int> b;
    ft::vector<int>::iterator ft_it;
    std::cout << "is it empty? : " << b.empty() << std::endl;
    std::cout << "size : " << b.size() << std::endl;
    std::cout << "max size : " << b.max_size() << std::endl;
    std::cout << "capacity of vector : " << b.capacity() << std::endl;
    b.reserve(15);
    b.resize(16);
    std::cout << "new capacity of vector : " << b.capacity() << std::endl;
    b.clear();
    b.assign(12, 100);
    std::cout << "size after: " << a.size() << std::endl;
    ft_it = b.begin();
    std::cout << "========================= DEBUG =========================" << std::endl;
    b.insert(ft_it, 42);
    std::cout << "value of first element : " << b.at(0) << std::endl;
    // std::cout << "capacity of vector : " << b.capacity() << std::endl;
}