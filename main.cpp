#include <iostream>
#include <list>
#include "list.hpp"

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

bool equal (int first, int second)
{ return ( first == second ); }

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
	first.print_all();
	first.reverse();
	first.print_all();
	std::cout << "\n\t\tCheck Iterator iter++\n";
	ft::list<int>::iterator iter = first.begin();
//	ft::list<int>::iterator iter;
	// iter = first.begin();
	std::cout << *iter << std::endl;
	iter++;
	while (*iter != *first.begin())
	{
		std::cout << *iter << std::endl;
		iter++;
	}
	std::cout << "\n\t\tCheck Iterator ++iter\n";
	iter = first.begin();
	std::cout << *iter << std::endl;
	iter++;
	while (*iter != *first.begin())
	{
		std::cout << *iter << std::endl;
		++iter;
	}
	std::cout << "\n\t\tCheck Iterator --iter\n";
	iter = first.begin();
	iter--;
	iter--;
	while (*iter != *first.begin())
	{
		std::cout << *iter << std::endl;
		iter--;
	}
	std::cout << *iter << std::endl;
	std::cout << "\n\t\tCheck Iterator iter--\n";
	iter = first.begin();
	--iter;
	iter--;
	while (*iter != *first.begin())
	{
		std::cout << *iter << std::endl;
		--iter;
	}
	std::cout << *iter << std::endl;
	std::cout << "\n\t\tCheck Iterator *iter++\n";
	iter = first.begin();
	iter = first.begin();
	//std::cout << "\nTwo iterators that compare equal, keep comparing equal after being both increased (*a++)\n";
	std::cout << "non-original list begin " << *iter << std::endl;	
	std::cout << "non-original list begin " << *iter++ << std::endl;
	std::cout << "non-original list begin " << *iter << std::endl;
	original.clear();
	original.push_back(0);
	original.push_back(1);
	original.push_back(2);
	original.push_back(3);
	std::list<int>::iterator list_iter_original = original.begin();
	std::cout << "original list begin " << *list_iter_original << std::endl;
	std::cout << "original list begin " << *list_iter_original++ << std::endl;
	std::cout << "original list begin " << *list_iter_original << std::endl;

	std::cout << "\n\t\tCheck == AND != \n";
	std::cout << "\nif (iter==iter) -> ";
	if (iter==iter)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";
	std::cout << "if (iter!=iter) -> ";
	if (iter!=iter)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

	std::cout << "\n\t\tCheck Const Iterator\n";	
	ft::list<int>::const_iterator const_iter = first.begin();
	std::cout << "\n*const_iter\n";
	std::cout << *const_iter << std::endl;
	std::cout << "const_iter++ && *const_iter\n";
	const_iter++;
	std::cout << *const_iter << std::endl;

	std::cout << "\n\t\tCheck BEGIN/END\n";
	ft::list<int>::iterator begin = first.begin();
	std::cout << "first elem " << *begin << std::endl;
	begin = first.end();
	std::cout << "last  elem " << *begin << std::endl;

	std::cout << "\n\t\tCheck CONST BEGIN/END\n";
	ft::list<int>::const_iterator c_begin = first.begin();
	std::cout << "first elem " << *c_begin << std::endl;
	c_begin = first.end();
	std::cout << "last  elem " << *c_begin << std::endl;

	std::cout << "\n\t\tCheck Reverse Iterator\n";
	first.print_all();
	std::cout << "\nCycle with plusing reverse iterator\n";	
	ft::list<int>::reverse_iterator rev_iter = first.rbegin();
	while (*rev_iter != *(first.begin()))
	{
		std::cout << *rev_iter << "\t";
		rev_iter++;
	}
	std::cout << *rev_iter << std::endl;
	std::cout << "\n\t\tCheck Erase\n";
	std::cout << "remove last iterator\n";
	first.print_all();
	first.erase(first.end());
	std::cout << "first.erase(first.end());\n";
	first.print_all();
	std::cout << "remove all, except last\n";
	first.erase(first.begin(), first.end());
	std::cout << "\n\t\tCheck Insert\n";
	first.push_back(3);
	first.push_back(4);
	first.push_back(5);
	iter = first.end();
	first.push_back(9);
	first.push_back(10);	
	first.print_all();
	std::cout << "iter points to element with content 5\n";
	std::cout << "\nft::list<int>::iterator new_iter = first.insert(iter, 21);\n";	
	ft::list<int>::iterator new_iter = first.insert(iter, 21);
	first.print_all();
	std::cout << "return of insert: " << *new_iter << std::endl;
	std::cout << "\nfirst.insert(iter, 2, 42);\n";
	first.insert(iter, 2, 42);
	first.print_all();
	std::cout << "first.insert(new_iter, 2, 43);\n";
	first.insert(new_iter, 2, 43);
	first.print_all();
	std::cout << "content of original list: ";
	for (std::list<int>::iterator it1 = original.begin(); it1 != original.end(); it1++)
		std::cout << *it1 << "\t";
	std::cout << "\n";
	std::cout << "\nfirst.insert(new_iter, original.begin(), original.end());\n";
	first.insert(new_iter, original.begin(), original.end());
	first.print_all();
	std::cout << "\n\t\tCheck Assign\n";
	first.assign(5, 42);
	std::cout << "\nfirst.assign(5, 42);\n";
	first.print_all();
	std::cout << "first.assign(original.begin(), original.end());\n";
	first.assign(original.begin(), original.end());
	first.print_all();
	std::cout << "\n\t\tCheck Reference\n";
	std::cout << "\nreference to front\t" << first.front() << std::endl;
	std::cout << "reference to back\t" << first.back() << std::endl;
	std::cout << "\n\t\tCheck Slice 1\n";
	first.print_all();
	second.print_all();
	first.splice(first.end(), second);
	std::cout << "\nfirst.splice(first.end(), second);\n";
	first.print_all();
	second.print_all();
	std::cout << "\n\t\tCheck Slice 2\n";
	second.push_back(23);
	second.push_back(24);
	second.push_back(25);
	first.print_all();
	second.print_all();
	first.splice(first.end(), second, second.begin());
	first.print_all();
	second.print_all();
	std::cout << "\n\t\tCheck Slice 3\n";
	first.print_all();
	second.print_all();
	first.splice(first.end(), second, second.begin(), second.end());
	first.print_all();
	second.print_all();
	std::cout << "\n\t\tCheck Merge\n";
	first.clear();
	second.clear();

	first.push_back(0);
	first.push_back(1);
	first.push_back(3);
	first.push_back(5);
	first.push_back(9);

	second.push_back(2);
	second.push_back(4);
	second.push_back(6);
	second.push_back(7);
	second.push_back(8);
	first.print_all();
	second.print_all();
	first.merge(second);
    std::cout << "merged: \n";
	first.print_all();
	second.print_all();

	std::cout << "\n\t\tCheck Sort\n";
	first.clear();

	first.push_back(0);
	first.push_back(3);
	first.push_back(9);
	first.push_back(5);
	first.push_back(1);
	first.print_all();
	first.sort();
	first.print_all();
	std::cout << "\n\t\tCheck Unique\n";
	first.push_back(9);
	first.push_back(9);
	first.push_back(9);
	first.push_back(5);
	first.push_back(5);
	first.push_back(9);
	first.push_back(5);
	first.push_back(5);
	first.push_back(5);
	first.print_all();
	first.unique(equal);
	first.print_all();
	// return (0);	
}