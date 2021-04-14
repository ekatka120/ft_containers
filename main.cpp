#include <iostream>
#include <list>
#include "list.hpp"

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

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
	first.swap(second);
	std::cout << "first\n";
	first.print_all();
	std::cout << "second\n";
	second.print_all();
	std::cout << "\n\t\tCheck Resize\n";
	std::cout << "first.resize(5,42);\n";
	first.resize(5,42);
	first.print_all();
	std::cout << "first.resize(3,42);\n";
	first.resize(3,42);
	first.print_all();
	std::cout << "first.resize(5,42);\n";
	first.resize(5,42);
	first.print_all();
	std::cout << "\n\t\tRemove Check\n";
	std::cout << "first.remove(42);\n";
	first.remove(42);
	first.print_all();

	std::cout << "\n\t\tRemove If Check\n";
	first.push_back(2);
	first.push_back(4);
	first.push_back(6);
	std::cout << "first.remove_if (is_odd());\n";
	first.print_all();
	first.remove_if (is_odd());
	first.print_all();

	std::cout << "\n\t\tCheck Clear\n";
	std::cout << "first.clear();\n";
	first.clear();
	first.print_all();

	std::cout << "\n\t\tCheck Max size\n";
	std::cout << "\nMax size: " << first.max_size() << "\n";
	std::list<int> original;
	std::cout << "\nMax size: " << original.max_size() << "\n";

	std::cout << "\n\t\tCheck Sort\n";
	first.push_back(3);
	first.push_back(2);	
	first.push_back(1);
	first.push_back(0);
	first.print_all();
/*	first.sort();
	first.print_all();
	first.push_back(200);
	first.push_back(201);
	std::cout << "\n\t\tCheck Merge\n";
	first.print_all();
	second.print_all();
	first.merge(second);
	first.print_all();
	ft::list<int>	six;
	six.push_back(300);
	six.push_back(301);
	six.push_back(302);
	six.print_all();
	first.merge(six);
	first.print_all();
	six.print_all();
	six.push_back(1);
	six.push_back(10);
	six.push_back(100);
	first.merge(six);
	first.print_all();

	std::list<int> original1;
	std::list<int> original2;
	original1.push_back(100);
	original1.push_back(2);
	original1.push_back(40);
	original2.push_back(1);
	original2.push_back(10);
	original2.push_back(20);
	original1.merge(original2);
	for(std::list<int>::iterator it = original1.begin(); it != original1.end(); it++)
		std::cout << *it << "\t";*/
	// int i;
	// while (1)
	// 	i++;
	std::cout << "\n\t\tCheck Reverse\n";
	first.reverse();
	first.print_all();
	return (0);
}