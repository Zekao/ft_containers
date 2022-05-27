#include <stack>
#include <map>
#include <vector>
#include "vector.hpp"
#include <iostream>
#include "stack.hpp"
#include "map.hpp"
#include "iterators/iterator.hpp"
#include "iterators/iterators_traits.hpp"
#include "iterators/random_access_iterator.hpp"
#include "iterators/bidirectionnal_iterator.hpp"
#include "utils/make_pair.hpp"
#include "utils/red_black_tree.hpp"

int	main(void)
{
	RedBlackTree rbt;

	rbt.insert(74);
	rbt.insert(28);
	rbt.insert(230);
	rbt.insert(234);
	rbt.insert(112);
	rbt.insert(4);
	rbt.insert(875);
	rbt.insert(14234);
	rbt.insert(2);
	rbt.printTree();

	ft::map<std::string, std::string> test;
	std::map<std::string, std::string> test2;
	test.begin();
	// std::cout << " is it empty? " << test2.empty() << std::endl;
	// std::cout << " is it empty? " << test.empty() << std::endl;
	// std::cout << "size of my container 	: " << test.size() << std::endl;
	// std::cout << "max size of my container 	: " << test.max_size() << std::endl;
	// std::cout << "size of real container : " << test2.size() << std::endl;
	// std::cout << "max size of real container 	: " << test2.max_size() << std::endl;
	// test.insert(42);
// 	ft::pair <int,int> foo;
// 	ft::pair <int,int> bar;

// 	foo = ft::make_pair (10,20);
// 	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

// 	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';	
// 	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

//   return 0;
	// ft::pair<std::string, std::string>("salut", "test");

	// ft::map <std::string, std::string>::iterator yo;
}

// int	main(void)
// {
//     std::cout << "===== real vector =====" << std::endl;
//     std::vector<int> a;
//     std::vector<int>::iterator  std_it;

//     std::cout << "is it empty? : " << a.empty() << std::endl;
//     std::cout << "size : " << a.size() << std::endl;
//     std::cout << "max size : " << a.max_size() << std::endl;
//     std::cout << "capacity of vector : " << a.capacity() << std::endl;
//     a.reserve(15);
//     a.resize(16);
//     std::cout << "size before: " << a.size() << std::endl;
//     a.clear();
//     a.assign(12, 100);
//     std::cout << "size after: " << a.size() << std::endl;
//     std::cout << "new capacity of vector : " << a.capacity() << std::endl;
//     std_it = a.begin();
//     std::cout << "value of first element : " << a.at(0) << std::endl;
//     a.insert(std_it, 42);
//     std::cout << "value of first element : " << a.at(0) << std::endl;

//     std::cout << "=====  my vector =====" << std::endl;
//     ft::vector<int> b;
//     ft::vector<int>::iterator ft_it;
//     std::cout << "is it empty? : " << b.empty() << std::endl;
//     std::cout << "size : " << b.size() << std::endl;
//     std::cout << "max size : " << b.max_size() << std::endl;
//     std::cout << "capacity of vector : " << b.capacity() << std::endl;
//     b.reserve(15);
//     b.resize(16);
//     std::cout << "new capacity of vector : " << b.capacity() << std::endl;
//     std::cout << "size before: " << b.size() << std::endl;
//     b.clear();
//     std::cout << "size before: " << b.size() << std::endl;
//     b.assign(16, 100);
//     std::cout << "size after: " << b.size() << std::endl;
//     std::cout << "value of first element : " << b.at(0) << std::endl;
//     ft_it = b.begin();
//     std::cout << "========================= DEBUG =========================" << std::endl;
//     b.insert(ft_it, 42);
//     ft_it = b.end();
//     b.insert(ft_it, 666);
//     std::cout << "value of first element : " << b.at(0) << std::endl;
//     std::cout << "value of last element : " << b.at(b.size() - 1) << std::endl;
//     std::cout << "========================= SWAP =========================" << std::endl;
//     std::cout << "now creating a new vector and fully asign it 42" << std::endl;
//     std::cout << "========================= SWAP =========================" << std::endl;
//     ft::vector<int> c;
//     c.assign(16, 42);
//     std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
//     std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;

//     std::cout << "=========================================================" << std::endl;
//     std::cout << "                      swapping values" << std::endl;
//     std::cout << "=========================================================" << std::endl;
//     b.swap(c);
//     std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
//     std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;

//  ft::vector<int> first;                                // empty vector of ints
//   ft::vector<int> second (4,100);                       // four ints with value 100
//   ft::vector<int> third (second.begin(),second.end());  // iterating through second
//   ft::vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// #define TESTED_TYPE int
// #define TESTED_NAMESPACE ft
// #define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

// template <typename T>
// void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
// {
// 	const T_SIZE_TYPE size = vct.size();
// 	const T_SIZE_TYPE capacity = vct.capacity();
// 	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
// 	// Cannot limit capacity's max value because it's implementation dependent

// 	std::cout << "size: " << size << std::endl;
// 	std::cout << "capacity: " << isCapacityOk << std::endl;
// 	std::cout << "max_size: " << vct.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
// 		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << *it << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }

// void	prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

// 	std::cout << "Pre inc" << std::endl;
// 	it_tmp = ++it;
// 	std::cout << *it_tmp << " | " << *it << std::endl;

// 	std::cout << "Pre dec" << std::endl;
// 	it_tmp = --it;
// 	std::cout << *it_tmp << " | " << *it << std::endl;

// 	std::cout << "Post inc" << std::endl;
// 	it_tmp = it++;
// 	std::cout << *it_tmp << " | " << *it << std::endl;

// 	std::cout << "Post dec" << std::endl;
// 	it_tmp = it--;
// 	std::cout << *it_tmp << " | " << *it << std::endl;
// 	std::cout << "###############################################" << std::endl;
// }

// template <typename Ite_1, typename Ite_2>
// void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
// {
// 	std::cout << (first < second) << std::endl;
// 	std::cout << (first <= second) << std::endl;
// 	std::cout << (first > second) << std::endl;
// 	std::cout << (first >= second) << std::endl;
// 	if (redo)
// 		ft_eq_ope(second, first, 0);
// }

// int		main(void)
// {
// const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;

// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

// 	for (int i = size; it_0 != it_1; --i)
// 		*it_0++ = i;
// 	printSize(vct, 1);
// 	it_0 = vct.rbegin();
// 	cit_1 = vct.rend();
// 	it_mid = it_0 + 3;
// 	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

// 	std::cout << std::boolalpha;
// 	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

// 	std::cout << "\t\tft_eq_ope:" << std::endl;
// 	// regular it
// 	ft_eq_ope(it_0 + 3, it_mid);
// 	ft_eq_ope(it_0, it_1);
// 	ft_eq_ope(it_1 - 3, it_mid);
// 	// const it
// 	ft_eq_ope(cit_0 + 3, cit_mid);
// 	ft_eq_ope(cit_0, cit_1);
// 	ft_eq_ope(cit_1 - 3, cit_mid);
// 	// both it
// 	ft_eq_ope(it_0 + 3, cit_mid);
// 	ft_eq_ope(it_mid, cit_0 + 3);
// 	ft_eq_ope(it_0, cit_1);
// 	ft_eq_ope(it_1, cit_0);
// 	ft_eq_ope(it_1 - 3, cit_mid);
// 	ft_eq_ope(it_mid, cit_1 - 3);

// 	return (0);
// }
