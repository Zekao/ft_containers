/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 05:49:05 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/29 07:54:52 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
int main(void)
{
	std::cout << "=========\t ft::vector \t=========" << std::endl;
	ft::vector<int>	a;
	ft::vector<int>::iterator	a_it;
	
	std::cout << "is it empty ? " << (a.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "size of ft::vector : " << a.size() << std::endl;
	std::cout << "max_size of ft::vector : " << a.max_size() << std::endl;
	std::cout << "capacity of ft::vector : " << a.capacity() << std::endl;
	std::cout << "=========================================================" << std::endl;
	std::cout << "using reserve on ft::vector : " << std::endl;
	a.reserve(918273645);
	std::cout << "capacity of ft::vector after reserve : " << a.capacity() << std::endl;
	std::cout << "using resize on ft::vector : " << std::endl;
	a.resize(16, 42);
	std::cout << "size of ft::vector after resize : " << a.size() << std::endl;
	std::cout << "capacity of ft::vector after resize : " << a.capacity() << std::endl;
	std::cout << "front value : " << a.front() << std::endl;
	std::cout << "back value : " << a.back() << std::endl;
	a_it = a.end();
	a.insert(a_it, 84);
	std::cout << "======\t inserting a new value \t=====" << std::endl;
	std::cout << "back value : " << a.back() << std::endl;
	++a_it;
	std::cout << "======\t inserting a new value \t=====" << std::endl;
	a.insert(a_it, 128);
	std::cout << "back value : " << a.back() << std::endl;
	std::cout << "trying to show before last value with [] operator (supposed to be 84)" << std::endl;
	std::cout << "value of vector[vector.size() - 2] : " << a[a.size() - 2] << std::endl;
    std::cout << "value of first element : " << a.at(0) << std::endl;
    std::cout << "value of last element : " << a.at(a.size() - 1) << std::endl;
	std::cout << "=====\t Testing all differents constructors" << std::endl;
    ft::vector<int> first;                                // empty vector of ints
    ft::vector<int> second (4,100);                       // four ints with value 100
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    ft::vector<int> fourth (third);                       // a copy of third
	std::cout << "all constructors correctly have been created." << std::endl;
    std::cout << "========================= SWAP =========================" << std::endl;
    std::cout << "now creating a new vector and fully asign it 42" << std::endl;
    std::cout << "========================= SWAP =========================" << std::endl;
    ft::vector<int> c;
    ft::vector<int> b;
    ft::vector<int>::iterator ft_it;
	c.assign(16, 42);
    b.reserve(15);
    b.resize(16);
    b.clear();
    b.assign(16, 100);
    ft_it = b.begin();
    b.insert(ft_it, 42);
    std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
    std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;

    std::cout << "=========================================================" << std::endl;
    std::cout << "                      swapping values" << std::endl;
    std::cout << "=========================================================" << std::endl;
    b.swap(c);
    std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
    std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;

  //   ft::vector<int> first;                                // empty vector of ints
  //   ft::vector<int> second (4,100);                       // four ints with value 100
  //   std::cout << "===== real vector =====" << std::endl;
  //   std::vector<int> a;
  //   std::vector<int>::iterator  std_it;

  //   std::cout << "is it empty? : " << a.empty() << std::endl;
  //   std::cout << "size : " << a.size() << std::endl;
  //   std::cout << "max size : " << a.max_size() << std::endl;
  //   std::cout << "capacity of vector : " << a.capacity() << std::endl;
  //   a.reserve(15);
  //   a.resize(16);
  //   std::cout << "size before: " << a.size() << std::endl;
  //   a.clear();
  //   a.assign(12, 100);
  //   std::cout << "size after: " << a.size() << std::endl;
  //   std::cout << "new capacity of vector : " << a.capacity() << std::endl;
  //   std_it = a.begin();
  //   std::cout << "value of first element : " << a.at(0) << std::endl;
  //   a.insert(std_it, 42);
  //   std::cout << "value of first element : " << a.at(0) << std::endl;

  //   std::cout << "=====  my vector =====" << std::endl;
  //   ft::vector<int> b;
  //   ft::vector<int>::iterator ft_it;
  //   std::cout << "is it empty? : " << b.empty() << std::endl;
  //   std::cout << "size : " << b.size() << std::endl;
  //   std::cout << "max size : " << b.max_size() << std::endl;
  //   std::cout << "capacity of vector : " << b.capacity() << std::endl;
  //   b.reserve(15);
  //   b.resize(16);
  //   std::cout << "new capacity of vector : " << b.capacity() << std::endl;
  //   std::cout << "size before: " << b.size() << std::endl;
  //   b.clear();
  //   std::cout << "size before: " << b.size() << std::endl;
  //   b.assign(16, 100);
  //   std::cout << "size after: " << b.size() << std::endl;
  //   std::cout << "value of first element : " << b.at(0) << std::endl;
  //   ft_it = b.begin();
  //   std::cout << "========================= DEBUG =========================" << std::endl;
  //   b.insert(ft_it, 42);
  //   ft_it = b.end();
  //   b.insert(ft_it, 666);
  //   std::cout << "value of first element : " << b.at(0) << std::endl;
  //   std::cout << "value of last element : " << b.at(b.size() - 1) << std::endl;
  //   std::cout << "========================= SWAP =========================" << std::endl;
  //   std::cout << "now creating a new vector and fully asign it 42" << std::endl;
  //   std::cout << "========================= SWAP =========================" << std::endl;
  //   ft::vector<int> c;
  //   c.assign(16, 42);
  //   std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
  //   std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;

  //   std::cout << "=========================================================" << std::endl;
  //   std::cout << "                      swapping values" << std::endl;
  //   std::cout << "=========================================================" << std::endl;
  //   b.swap(c);
  //   std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
  //   std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;

  //   ft::vector<int> first;                                // empty vector of ints
  //   ft::vector<int> second (4,100);                       // four ints with value 100
  //   ft::vector<int> third (second.begin(),second.end());  // iterating through second
  //   ft::vector<int> fourth (third);                       // a copy of third

  // // the iterator constructor can also be used to construct from arrays:
  //   int myints[] = {16,2,77,29};
  //   ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  //   std::cout << "The contents of fifth are:";
  //   for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
  //       std::cout << ' ' << *it;
  //   std::cout << '\n';
  //   return 0;
}
