#include <iostream>
#include <list>
#include "list.hpp"

int main(void)
{
	ft::list<int>	first;

	std::cout << "\n\t\tCheck 1 constructor\n";
	first.push_back(12);
	first.push_back(16);
	first.push_back(121);
	first.print_all();

	std::cout << "\n\t\tCheck 2 constructor\n";
	ft::list<int>	second(5,21);
	second.print_all();

	// std::cout << "\n\t\tCheck 3 constructor\n";
	// std::list<int>	check(4, 42);
	// ft::list<int>	third(check.begin(), check.end());

	std::cout << "\n\t\tCheck 4 constructor\n";
	ft::list<int>	forth(first);
	forth.print_all();

	std::cout << "\n\t\tCheck PushBack and PushFront\n";	
	std::cout << "\nfirst.push_back(31);";
	std::cout << "\nfirst.push_front(32);\n";
	forth.push_back(31);
	forth.push_front(32);
	forth.print_all();

	std::cout << "\n\t\tCheck PopFront\n";
	forth.pop_front();
	forth.print_all();

	std::cout << "\n\t\tCheck PopBack\n";
	forth.pop_back();
	forth.print_all();

	std::cout << "\n\t\tCheck Swap\n";
	std::cout << "first\n";
	first.print_all();
	std::cout << "second\n";
	second.print_all();
	first.swap(forth);
	std::cout << "first\n";
	first.print_all();
	std::cout << "second\n";
	second.print_all();
	return (0);
}