/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 05:49:05 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/30 18:24:13 by emaugale         ###   ########.fr       */
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
    ft::vector<int>::reverse_iterator rev_ft_it;
    ft::vector<int>::const_reverse_iterator const_rev_ft_it;
    ft::vector<int>::const_iterator const_ft_it;
	
    c.assign(16, 42);
    b.reserve(15);
    b.resize(16);
    b.clear();
    b.assign(16, 100);
    
    std::cout << "====================== ITERATORS ======================" << std::endl;
    std::cout << "                     iterators check                   " << std::endl;
    std::cout << "====================== ITERATORS ======================" << std::endl;
    
    ft_it = b.begin(); 
    b.insert(ft_it, 42);
    ft_it = b.begin(); 
    const_ft_it = b.begin();   
    std::cout << "begin iterator : OK" << std::endl;
    std::cout << "value of my it (begin): " << *(ft_it) << std::endl;
    std::cout << "value of my const it (begin): " << *(const_ft_it) << std::endl;
    rev_ft_it = b.rbegin(); 
    const_rev_ft_it = b.rbegin();   
    std::cout << "value of my it (rbegin): " << *(rev_ft_it) << std::endl;
    std::cout << "value of my const it (rbegin): " << *(const_rev_ft_it) << std::endl;
    b.insert(ft_it, 666);
    ft_it = b.end(); 
    const_ft_it = b.end();   
    b.insert(ft_it, 666);
    rev_ft_it = b.rend(); 
    const_rev_ft_it = b.rend();   
    std::cout << "value of my it (rend): " << *(rev_ft_it) << std::endl;
    std::cout << "value of my const it (rend): " << *(const_rev_ft_it) << std::endl;
    std::cout << "end iterator : OK" << std::endl;
    std::cout << "value of my it : " << *(ft_it) << std::endl;
    std::cout << "value of my const it : " << *(const_ft_it) << std::endl;

    std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
    std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;

    std::cout << "====================== SIZE ======================" << std::endl;
    std::cout << "                     Size check                   " << std::endl;
    std::cout << "====================== SIZE ======================" << std::endl;
    
    ft::vector<bool> bool_vec;
    ft::vector<int> int_vec;
    ft::vector<char> char_vec;
    ft::vector<std::string> string_vec;
    
    bool_vec.insert(bool_vec.begin(), true);
    int_vec.insert(int_vec.begin(), 42);
    int_vec.insert(int_vec.begin(), 420);
    int_vec.insert(int_vec.begin(), 4200);
    char_vec.insert(char_vec.begin(), 'a');
    char_vec.insert(char_vec.begin(), 'b');
    string_vec.insert(string_vec.begin(), "bonjour");
    string_vec.insert(string_vec.begin(), "je suis");
    string_vec.insert(string_vec.begin(), "Olivier");
    string_vec.insert(string_vec.begin(), "De chez carglass");
    
    std::cout << "size of bool vector : " << bool_vec.size() << std::endl;
    std::cout << "size of char vector : " << char_vec.size() << std::endl;
    std::cout << "size of int vector : " << int_vec.size() << std::endl;
    std::cout << "size of string vector : " << string_vec.size() << std::endl;

    std::cout << "==================== MAX_SIZE ====================" << std::endl;
    std::cout << "                   Max_Size check                 " << std::endl;
    std::cout << "==================== MAX_SIZE ====================" << std::endl;
    
    std::cout << "max_size of bool vector : " << bool_vec.max_size() << std::endl;
    std::cout << "max_size of char vector : " << char_vec.max_size() << std::endl;
    std::cout << "max_size of int vector : " << int_vec.max_size() << std::endl;
    std::cout << "max_size of string vector : " << string_vec.max_size() << std::endl;
    
    std::cout << "===================== RESIZE =====================" << std::endl;
    std::cout << "                    Resize check                  " << std::endl;
    std::cout << "===================== RESIZE =====================" << std::endl;
    
    bool_vec.resize(42);
    char_vec.resize(420);
    int_vec.resize(4200);
    string_vec.resize(42000);
    
    std::cout << "resize of bool vector : " << bool_vec.size() << std::endl;
    std::cout << "resize of char vector : " << char_vec.size() << std::endl;
    std::cout << "resize of int vector : " << int_vec.size() << std::endl;
    std::cout << "resize of string vector : " << string_vec.size() << std::endl;

    std::cout << "==================== CAPACITY ====================" << std::endl;
    std::cout << "                   Capacity check                 " << std::endl;
    std::cout << "==================== CAPACITY ====================" << std::endl;
    
    std::cout << "capacity of bool vector : " << bool_vec.capacity() << std::endl;
    std::cout << "capacity of char vector : " << char_vec.capacity() << std::endl;
    std::cout << "capacity of int vector : " << int_vec.capacity() << std::endl;
    std::cout << "capacity of string vector : " << string_vec.capacity() << std::endl;


    std::cout << "===================== EMPTY =====================" << std::endl;
    std::cout << "                    Empty check                  " << std::endl;
    std::cout << "===================== EMPTY =====================" << std::endl;
    
    std::cout << "====== BEFORE CLEAR =====" << std::endl;
    
    std::cout << "empty of bool vector : " << bool_vec.empty() << std::endl;
    std::cout << "empty of char vector : " << char_vec.empty() << std::endl;
    std::cout << "empty of int vector : " << int_vec.empty() << std::endl;
    std::cout << "empty of string vector : " << string_vec.empty() << std::endl;
    
    bool_vec.clear();
    char_vec.clear();
    int_vec.clear();
    string_vec.clear();
    
    std::cout << std::endl;
    
    std::cout << "====== AFTER CLEAR =====" << std::endl;
    
    std::cout << "empty of bool vector : " << bool_vec.empty() << std::endl;
    std::cout << "empty of char vector : " << char_vec.empty() << std::endl;
    std::cout << "empty of int vector : " << int_vec.empty() << std::endl;
    std::cout << "empty of string vector : " << string_vec.empty() << std::endl;


    std::cout << "=================== RESERVE ===================" << std::endl;
    std::cout << "                  Reserve check                " << std::endl;
    std::cout << "=================== RESERVE ===================" << std::endl;
    
    std::cout << "====== BEFORE RESERVE =====" << std::endl;
    
    std::cout << "capacity of bool vector : " << bool_vec.capacity() << std::endl;
    std::cout << "capacity of char vector : " << char_vec.capacity() << std::endl;
    std::cout << "capacity of int vector : " << int_vec.capacity() << std::endl;
    std::cout << "capacity of string vector : " << string_vec.capacity() << std::endl;

    std::cout << std::endl;
    
    bool_vec.reserve(84);
    char_vec.reserve(840);
    int_vec.reserve(8400);
    string_vec.reserve(84000);
    
    std::cout << "====== AFTER RESERVE =====" << std::endl;
    
    std::cout << "capacity of bool vector : " << bool_vec.capacity() << std::endl;
    std::cout << "capacity of char vector : " << char_vec.capacity() << std::endl;
    std::cout << "capacity of int vector : " << int_vec.capacity() << std::endl;
    std::cout << "capacity of string vector : " << string_vec.capacity() << std::endl;

    std::cout << "================ OPERATOR[] ==================" << std::endl;
    std::cout << "                Operator[] check              " << std::endl;
    std::cout << "================ OPERATOR[] ==================" << std::endl;


    bool_vec.insert(bool_vec.begin(), true);
    char_vec.insert(char_vec.begin(), 'E');
    int_vec.insert(int_vec.begin(), 727);
    string_vec.insert(string_vec.begin(), "OWO");
    
    std::cout << "bool vector [0] : " << bool_vec[0] << std::endl;
    std::cout << "char vector [0] : " << char_vec[0] << std::endl;
    std::cout << "int vector [0] : " << int_vec[0] << std::endl;
    std::cout << "string vector [0] : " << string_vec[0] << std::endl;

    std::cout << "================      AT    ==================" << std::endl;
    std::cout << "               AT element check               " << std::endl;
    std::cout << "================      AT    ==================" << std::endl;

    std::cout << "====== BEFORE INSERT =====" << std::endl;

    std::cout << "bool vector [0] : " << bool_vec.at(0) << std::endl;
    std::cout << "char vector [0] : " << char_vec.at(0) << std::endl;
    std::cout << "int vector [0] : " << int_vec.at(0) << std::endl;
    std::cout << "string vector [0] : " << string_vec.at(0) << std::endl;

    bool_vec.insert(bool_vec.begin(), true);
    char_vec.insert(char_vec.begin(), 'A');
    int_vec.insert(int_vec.begin(), 222);
    string_vec.insert(string_vec.begin(), "Terry Crews - Old Spice Collab (TV Size)");
    
    std::cout << std::endl;
    std::cout << "====== AFTER INSERT =====" << std::endl;
    
    std::cout << "bool vector [0] : " << bool_vec.at(0) << std::endl;
    std::cout << "char vector [0] : " << char_vec.at(0) << std::endl;
    std::cout << "int vector [0] : " << int_vec.at(0) << std::endl;
    std::cout << "string vector [0] : " << string_vec.at(0) << std::endl;

    std::cout << "================      FRONT    ==================" << std::endl;
    std::cout << "               FRONT element check               " << std::endl;
    std::cout << "================      FRONT    ==================" << std::endl;

    std::cout << "bool vector front element : " << bool_vec.front() << std::endl;
    std::cout << "char vector front element : " << char_vec.front() << std::endl;
    std::cout << "int vector front element : " << int_vec.front() << std::endl;
    std::cout << "string vector front element : " << string_vec.front() << std::endl;


    std::cout << "================      BACK    ==================" << std::endl;
    std::cout << "               BACK element check               " << std::endl;
    std::cout << "================      BACK    ==================" << std::endl;

    std::cout << "bool vector back element : " << bool_vec.back() << std::endl;
    std::cout << "char vector back element : " << char_vec.back() << std::endl;
    std::cout << "int vector back element : " << int_vec.back() << std::endl;
    std::cout << "string vector back element : " << string_vec.back() << std::endl;


    std::cout << "================      ASSIGN    ==================" << std::endl;
    std::cout << "               ASSIGN element check               " << std::endl;
    std::cout << "================      ASSIGN    ==================" << std::endl;
    
    std::cout << "=========== BEFORE ASSIGN ===========" << std::endl;
    
    std::cout << "size of bool vector : " << bool_vec.size() << std::endl;
    std::cout << "size of char vector : " << char_vec.size() << std::endl;
    std::cout << "size of int vector : " << int_vec.size() << std::endl;
    std::cout << "size of string vector : " << string_vec.size() << std::endl;

    bool_vec.assign(42, true);
    char_vec.assign(42, 'o');
    int_vec.assign(42, 420);
    string_vec.assign(42, "awa");

    std::cout << "=========== AFTER ASSIGN ===========" << std::endl;

    std::cout << "size of bool vector : " << bool_vec.size() << std::endl;
    std::cout << "size of char vector : " << char_vec.size() << std::endl;
    std::cout << "size of int vector : " << int_vec.size() << std::endl;
    std::cout << "size of string vector : " << string_vec.size() << std::endl;

    std::cout << "===============      PUSH_BACK    =================" << std::endl;
    std::cout << "              PUSH_BACK element check              " << std::endl;
    std::cout << "===============      PUSH_BACK    =================" << std::endl;

    std::cout << "=========== BEFORE PUSH_BACK ===========" << std::endl;
    std::cout << "bool vector : " << bool_vec.at(bool_vec.size() - 1) << std::endl;
    std::cout << "char vector : " << char_vec.at(char_vec.size() - 1) << std::endl;
    std::cout << "int vector : " << int_vec.at(int_vec.size() - 1) << std::endl;
    std::cout << "string vector : " << string_vec.at(string_vec.size() - 1) << std::endl;


    std::cout << std::endl;
    bool_vec.push_back(false);
    char_vec.push_back('W');
    int_vec.push_back(666);
    string_vec.push_back("t+pazolite gud artist");

    std::cout << "=========== AFTER PUSH_BACK ===========" << std::endl;
    std::cout << "bool vector : " << bool_vec.at(bool_vec.size() - 1) << std::endl;
    std::cout << "char vector : " << char_vec.at(char_vec.size() - 1) << std::endl;
    std::cout << "int vector : " << int_vec.at(int_vec.size() - 1) << std::endl;
    std::cout << "string vector : " << string_vec.at(string_vec.size() - 1) << std::endl;


    std::cout << "===============      POP_BACK    =================" << std::endl;
    std::cout << "              POP_BACK element check              " << std::endl;
    std::cout << "===============      POP_BACK    =================" << std::endl;

    std::cout << "=========== BEFORE POP_BACK ===========" << std::endl;
    std::cout << "bool vector : " << bool_vec.at(bool_vec.size() - 1) << std::endl;
    std::cout << "char vector : " << char_vec.at(char_vec.size() - 1) << std::endl;
    std::cout << "int vector : " << int_vec.at(int_vec.size() - 1) << std::endl;
    std::cout << "string vector : " << string_vec.at(string_vec.size() - 1) << std::endl;


    std::cout << std::endl;
    bool_vec.pop_back();
    char_vec.pop_back();
    int_vec.pop_back();
    string_vec.pop_back();

    std::cout << "=========== AFTER POP_BACK ===========" << std::endl;
    std::cout << "bool vector : " << bool_vec.at(bool_vec.size() - 1) << std::endl;
    std::cout << "char vector : " << char_vec.at(char_vec.size() - 1) << std::endl;
    std::cout << "int vector : " << int_vec.at(int_vec.size() - 1) << std::endl;
    std::cout << "string vector : " << string_vec.at(string_vec.size() - 1) << std::endl;
   
    std::cout << "===============      INSERT    =================" << std::endl;
    std::cout << "              INSERT element check              " << std::endl;
    std::cout << "===============      INSERT    =================" << std::endl;

    std::cout << "=========== BEFORE INSERT ===========" << std::endl;
  
    std::cout << "bool vector : " << bool_vec.at(0) << std::endl;
    std::cout << "char vector : " << char_vec.at(0) << std::endl;
    std::cout << "int vector : " << int_vec.at(0) << std::endl;
    std::cout << "string vector : " << string_vec.at(0) << std::endl;

    bool_vec.insert(bool_vec.begin(), false);
    char_vec.insert(char_vec.begin(), 'C');
    int_vec.insert(int_vec.begin(), 42424242);
    string_vec.insert(string_vec.begin(), "ewe");


    std::cout << std::endl;
    std::cout << "=========== AFTER INSERT ===========" << std::endl;
    std::cout << "bool vector : " << bool_vec.at(0) << std::endl;
    std::cout << "char vector : " << char_vec.at(0) << std::endl;
    std::cout << "int vector : " << int_vec.at(0) << std::endl;
    std::cout << "string vector : " << string_vec.at(0) << std::endl;

    std::cout << "===============      ERASE    =================" << std::endl;
    std::cout << "              ERASE element check              " << std::endl;
    std::cout << "===============      ERASE    =================" << std::endl;
   
    std::cout << "size of bool vector : " << bool_vec.size() << std::endl;
    std::cout << "size of char vector : " << char_vec.size() << std::endl;
    std::cout << "size of int vector : " << int_vec.size() << std::endl;
    std::cout << "size of string vector : " << string_vec.size() << std::endl;

    bool_vec.erase(bool_vec.begin());
    char_vec.erase(char_vec.begin());
    int_vec.erase(int_vec.begin());
    string_vec.erase(string_vec.begin());

    std::cout << "size of bool vector : " << bool_vec.size() << std::endl;
    std::cout << "size of char vector : " << char_vec.size() << std::endl;
    std::cout << "size of int vector : " << int_vec.size() << std::endl;
    std::cout << "size of string vector : " << string_vec.size() << std::endl;

    std::cout << "=========================================================" << std::endl;
    std::cout << "                  before swapping values" << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
    std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "                  after swapping values" << std::endl;
    std::cout << "=========================================================" << std::endl;
    b.swap(c);
    std::cout << "value of last element of vector b: " << b.at(b.size() - 1) << std::endl;
    std::cout << "value of last element of vector c : " << c.at(c.size() - 1) << std::endl;
    
}
