#include <stack>
#include <map>
#include <vector>
#include <iostream>
#include "stack.hpp"
// #include "vector.hpp"
int	main(void)
{
	// std::map <size_t, std::string> test;
	// std::map <size_t, std::string>::iterator map_iterator;
	// std::vector <int> v;
	// // test.insert("bonjour");
	// test.insert(std::pair<size_t, std::string>(42, "oui"));
	// map_iterator = test.begin();
	// std::cout << "value of first elem " << map_iterator->first << " second elem " << map_iterator->second << std::endl;
	// std::cout << "test : " << test.empty() << std::endl;
	
  std::deque<int> mydeque (3,100);          // deque with 3 elements
  std::vector<int> myvector (2,200);        // vector with 2 elements

  ft::stack<int> first;                    // empty stack
  std::stack<int> second (mydeque);         // stack initialized to copy of deque

  ft::stack<int,std::vector<int> > third;  // empty stack using vector
  std::stack<int,std::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}