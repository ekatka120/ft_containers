#include <iostream>
#include <unistd.h>
#include <list>
#include "list.hpp"

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

bool equal (int first, int second)
{ return ( first == second ); }

template <class T>
void    print_list(ft::list<T> my_list)
{
    int i = 1;
    std::cout << "Size: " << my_list.size() << std::endl;
    ft::list<int>::iterator it = my_list.begin();
    while (it != my_list.end())
    {
        std::cout << i << "\t" << *it << std::endl;
        i++;
        it++;
    }
}

template <class T>
void    print_list(std::list<T> my_list)
{
    int i = 1;
    std::cout << "Size: " << my_list.size() << std::endl;
    std::list<int>::iterator it = my_list.begin();
    while (it != my_list.end())
    {
        std::cout << i << "\t" << *it << std::endl;
        i++;
        it++;
    }
}

int main(void)
{
    std::cout << "\n\t\tCheck default constructor\n";
	ft::list<int>	first;
	first.push_back(12);
	first.push_back(16);
	first.push_back(121);
	print_list(first);

	std::cout << "\n\t\tCheck fill constructor\n";
	ft::list<int>	second(5,21);
    print_list(second);

    std::cout << "\n\t\tCheck range constructor\n";
    std::list<int>	check(4, 42);
    ft::list<int>	third(check.begin(), check.end());
    print_list(third);

	std::cout << "\n\t\tCheck copy constructor\n";
	ft::list<int>	forth(first);
    print_list(forth);

    std::cout << "\n\t\tCheck Operation =\n";

    std::cout << "first array;\n\n";
    print_list(first);
    std::cout << "second array\n\n";
    print_list(second);
    std::cout << "\nsecond = first;\n\n";
    second = first;
    std::cout << "first array;\n\n";
    print_list(first);
    std::cout << "second array\n\n";
    print_list(second);

    //Creation of original list 12/16/121
    std::list<int> original;
    original.push_back(12);
    original.push_back(16);
    original.push_back(121);

    std::cout << "\n\t\tCheck BEGIN/END\n";
    ft::list<int>::iterator begin = first.begin();
    std::cout << "first elem " << *begin << std::endl;
    begin = first.end();
    std::cout << "last  elem " << *begin << std::endl;

    std::cout << "\n\t\tOriginal BEGIN/END\n";
    std::list<int>::iterator or_begin = original.begin();
    std::cout << "first elem " << *or_begin << std::endl;
    or_begin = original.end();
    std::cout << "last  elem " << *or_begin << std::endl;

    std::cout << "\n\t\tCheck CONST BEGIN/END\n";
    ft::list<int>::const_iterator c_begin = first.begin();
    std::cout << "first elem " << *c_begin << std::endl;
    c_begin = first.end();
    std::cout << "last  elem " << *c_begin << std::endl;

    std::cout << "\n\t\tOriginal CONST BEGIN/END\n";
    std::list<int>::const_iterator c_or_begin = original.begin();
    std::cout << "first elem " << *c_or_begin << std::endl;
    c_or_begin = original.end();
    std::cout << "last  elem " << *c_or_begin << std::endl;

    print_list(first);

    std::cout << "\n\t\tCheck RBEGIN/REND\n";
    ft::list<int>::reverse_iterator rev_begin = first.rbegin();
    std::cout << "first elem " << *rev_begin << std::endl;
    rev_begin = first.rend();
    std::cout << "last  elem " << *rev_begin << std::endl;

    std::cout << "\n\t\tOriginal RBEGIN/REND\n";
    std::list<int>::reverse_iterator or_rev_begin = original.rbegin();
    std::cout << "first elem " << *or_rev_begin << std::endl;
    or_rev_begin = original.rend();
    std::cout << "last  elem " << *or_rev_begin << std::endl;

    std::cout << "\n\t\tCheck CONST RBEGIN/REND\n";
    ft::list<int>::const_reverse_iterator c_rev_begin = first.rbegin();
    std::cout << "first elem " << *c_rev_begin << std::endl;
    c_rev_begin = first.rend();
    std::cout << "last  elem " << *c_rev_begin << std::endl;

    std::cout << "\n\t\tOriginal CONST RBEGIN/REND\n";
    std::list<int>::const_reverse_iterator or_con_rev_begin = original.rbegin();
    std::cout << "first elem " << *or_con_rev_begin << std::endl;
    or_con_rev_begin = original.rend();
    std::cout << "last  elem " << *or_con_rev_begin << std::endl;


    //Check functionality of iterators


    std::cout << "\n\t\tCheck Iterators\n";
    std::cout << "\n\t\tCheck Iterator iter++\n";
    std::cout << "\n\tMy iterator\n";

    ft::list<int>::iterator iter;
    std::list<int>::iterator or_iter;
    for (iter = first.begin(); iter != first.end(); iter++)
        std::cout << *iter << std::endl;

    std::cout << "\n\tOriginal iterator\n";
    for (or_iter = original.begin(); or_iter != original.end(); or_iter++)
        std::cout << *or_iter << std::endl;


	std::cout << "\n\t\tCheck Iterator ++iter\n";
    std::cout << "\n\tMy iterator\n";
    for (iter = first.begin(); iter != first.end(); ++iter)
        std::cout << *iter << std::endl;

    std::cout << "\n\tOriginal iterator\n";
    for (or_iter = original.begin(); or_iter != original.end(); ++or_iter)
        std::cout << *or_iter << std::endl;

    std::cout << "\n\t\tCheck Iterator iter--\n";
    std::cout << "\n\tMy iterator\n";

    for (iter = first.end(); iter != first.begin(); iter--)
        std::cout << *iter << std::endl;

    std::cout << "\n\tOriginal iterator\n";
    for (or_iter = original.end(); or_iter != original.begin(); or_iter--)
        std::cout << *or_iter << std::endl;


    std::cout << "\n\t\tCheck Iterator --iter\n";
    std::cout << "\n\tMy iterator\n";
    for (iter = first.end(); iter != first.begin(); --iter)
        std::cout << *iter << std::endl;

    std::cout << "\n\tOriginal iterator\n";
    for (or_iter = original.end(); or_iter != original.begin(); --or_iter)
        std::cout << *or_iter << std::endl;

	
    
    std::cout << "\n\t\tCheck Iterator *iter++\n";
	iter = first.begin();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list begin " << *iter << std::endl;
	std::cout << "non-original list begin " << *iter++ << std::endl;
	std::cout << "non-original list begin " << *iter << std::endl;
	or_iter = original.begin();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list begin " << *or_iter << std::endl;
	std::cout << "original list begin " << *or_iter++ << std::endl;
	std::cout << "original list begin " << *or_iter << std::endl;

	std::cout << "\n\t\tCheck Iterator *iter--\n";
	iter = first.end();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list end " << *iter << std::endl;
	std::cout << "non-original list end " << *iter-- << std::endl;
	std::cout << "non-original list end " << *iter << std::endl;
	or_iter = original.end();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list end " << *or_iter << std::endl;
	std::cout << "original list end " << *or_iter-- << std::endl;
	std::cout << "original list end " << *or_iter << std::endl;

    

    std::cout << "\n\t\tCheck Const Iterator *iter++\n";
	c_begin = first.begin();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list begin " << *c_begin << std::endl;
	std::cout << "non-original list begin " << *c_begin++ << std::endl;
	std::cout << "non-original list begin " << *c_begin << std::endl;
	c_or_begin = original.begin();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list begin " << *c_or_begin << std::endl;
	std::cout << "original list begin " << *c_or_begin++ << std::endl;
	std::cout << "original list begin " << *c_or_begin << std::endl;

	std::cout << "\n\t\tCheck Iterator *iter--\n";
	c_begin = first.end();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list end " << *c_begin << std::endl;
	std::cout << "non-original list end " << *c_begin-- << std::endl;
	std::cout << "non-original list end " << *c_begin << std::endl;
	c_or_begin = original.end();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list end " << *c_or_begin << std::endl;
	std::cout << "original list end " << *c_or_begin-- << std::endl;
	std::cout << "original list end " << *c_or_begin << std::endl;


    std::cout << "\n\t\tCheck Reverse Iterator *iter++\n";
	rev_begin = first.rbegin();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list begin " << *rev_begin << std::endl;
	std::cout << "non-original list begin " << *rev_begin++ << std::endl;
	std::cout << "non-original list begin " << *rev_begin << std::endl;
	or_rev_begin = original.rbegin();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list begin " << *or_rev_begin << std::endl;
	std::cout << "original list begin " << *or_rev_begin++ << std::endl;
	std::cout << "original list begin " << *or_rev_begin << std::endl;

	std::cout << "\n\t\tCheck Iterator *iter--\n";
	rev_begin = first.rend();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list end " << *rev_begin << std::endl;
	std::cout << "non-original list end " << *rev_begin-- << std::endl;
	std::cout << "non-original list end " << *rev_begin << std::endl;
	or_rev_begin = original.rend();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list end " << *or_rev_begin << std::endl;
	std::cout << "original list end " << *or_rev_begin-- << std::endl;
	std::cout << "original list end " << *or_rev_begin << std::endl;

    std::cout << "\n\t\tCheck Reverse Const Iterator *iter++\n";
	c_rev_begin = first.rbegin();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list begin " << *c_rev_begin << std::endl;
	std::cout << "non-original list begin " << *c_rev_begin++ << std::endl;
	std::cout << "non-original list begin " << *c_rev_begin << std::endl;
	or_con_rev_begin = original.rbegin();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list begin " << *or_con_rev_begin << std::endl;
	std::cout << "original list begin " << *or_con_rev_begin++ << std::endl;
	std::cout << "original list begin " << *or_con_rev_begin << std::endl;

	std::cout << "\n\t\tCheck Iterator *iter--\n";
	c_rev_begin = first.rend();
    std::cout << "\n\tMy iterator\n";
	std::cout << "non-original list end " << *c_rev_begin << std::endl;
	std::cout << "non-original list end " << *c_rev_begin-- << std::endl;
	std::cout << "non-original list end " << *c_rev_begin << std::endl;
	or_con_rev_begin = original.rend();
    std::cout << "\n\tOriginal iterator\n";
	std::cout << "original list end " << *or_con_rev_begin << std::endl;
	std::cout << "original list end " << *or_con_rev_begin-- << std::endl;
	std::cout << "original list end " << *or_con_rev_begin << std::endl;

	std::cout << "\n\t\tCheck for usual iter == AND != \n";
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

	std::cout << "\n\t\tCheck for const iter == AND != \n";
	std::cout << "\nif (iter==iter) -> ";
	if (c_begin==c_begin)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";
	std::cout << "if (iter!=iter) -> ";
	if (c_begin!=c_begin)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

    std::cout << "\n\t\tCheck for rev iter == AND != \n";
	std::cout << "\nif (iter==iter) -> ";
	if (rev_begin==rev_begin)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";
	std::cout << "if (iter!=iter) -> ";
	if (rev_begin!=rev_begin)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

    std::cout << "\n\t\tCheck for const rev iter == AND != \n";
	std::cout << "\nif (iter==iter) -> ";
	if (c_rev_begin==c_rev_begin)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";
	std::cout << "if (iter!=iter) -> ";
	if (c_rev_begin!=c_rev_begin)
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

                                //Check basic functions!!!!!!!!

	std::cout << "\n\t\tCheck Empty\n";
    std::cout << "is my list empty? "<< first.empty() << std::endl;
    std::cout << "is original list empty? "<< original.empty() << std::endl;

    std::cout << "\n\t\tCheck Size\n";
    std::cout << "my list: "<< first.size() << std::endl;
    std::cout << "original list: "<< original.size() << std::endl;

    std::cout << "\n\t\tCheck Max Size\n";
    std::cout << "is my list emppty? "<< first.max_size() << std::endl;
    std::cout << "is original list emppty? "<< original.max_size() << std::endl;

    std::cout << "\n\t\tCheck Reference\n";
    std::cout << "my reference to front " << first.front() << std::endl;
    std::cout << "original reference to front " << original.front() << std::endl;
    std::cout << "my reference to back " << first.back() << std::endl;
    std::cout << "original reference to back " << original.back() << std::endl;



	std::cout << "\n\t\tCheck Assign\n";
    std::list<int> assign_list(2, 42);
    std::cout << "\n\tMy assign range\n" << std::endl;
    first.assign(assign_list.begin(), assign_list.end());
    print_list(first);
    std::cout << "\n\tOriginal assign range\n";
	original.assign(assign_list.begin(), assign_list.end());
	print_list(original);

    std::cout << "\n\tMy assign fill\n" << std::endl;
    first.assign(2, 21);
    print_list(first);
    std::cout << "\n\tOriginal assign fill\n";
	original.assign(2, 21);
	print_list(original);



    std::cout << "\n\t\tCheck PushBack and PushFront\n";
    std::cout << "\nPush front 1 and push back 5\n";
    first.push_back(5);
    first.push_front(1);
    print_list(first);
    std::cout << "\n\t\tCheck PopBack and PopFront\n";
    first.pop_back();
    first.pop_front();
    print_list(first);


	std::cout << "\n\t\tCheck Insert\n";
	first.push_back(3);
	iter = first.end();
	first.push_back(9);
	first.push_back(10);

    
    original.clear();
 	original.push_back(21);
	original.push_back(21);   
	original.push_back(3);
	or_iter = original.end();
	original.push_back(9);
	original.push_back(10);
    std::cout << "\n\tMy list\n";
    print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);

	std::cout << "\nIter points to element with content 3\n";



    std::cout << "\n\tCheck Insert of one elenent of value 21 after iter\n";
	ft::list<int>::iterator new_iter = first.insert(iter, 21);
    std::list<int>::iterator or_new_iter = original.insert(or_iter, 21);
    
    std::cout << "\n\tMy list\n";
	print_list(first);
	std::cout << "return of insert: " << *new_iter << std::endl;
    std::cout << "\n\tOriginal list\n";
	print_list(original);
	std::cout << "return of insert: " << *or_new_iter << std::endl;    



    std::cout << "\n\tCheck Insert of 2 elenents of value 7 after iter\n";
    first.insert(iter, 2, 7);
    original.insert(or_iter, 2, 7);
    std::cout << "\n\tMy list\n";
	print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);

    std::cout << "\n\tCheck Insert of elenents of assign_list(42, 42) after iter\n";
    first.insert(iter, assign_list.begin(), assign_list.end());
    original.insert(or_iter, assign_list.begin(), assign_list.end());
	std::cout << "\n\tMy list\n";
	print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);



	std::cout << "\n\t\tCheck Erase\n";
	std::cout << "\n\tRemove last iterator\n";
	first.erase(first.begin());
	original.erase(original.begin());
	std::cout << "\n\tMy list\n";
	print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);


    std::cout << "\n\tRemove elements from third to last iterator\n";
    new_iter = first.begin();
    new_iter++;
    new_iter++;
    or_new_iter = original.begin();
    or_new_iter++;
    or_new_iter++;

    first.erase(new_iter, first.end());
	original.erase(or_new_iter, original.end());
	std::cout << "\n\tMy list\n";
	print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);



	std::cout << "\n\t\tCheck Swap\n";
	std::cout << "\n\tfirst\n";
	print_list(first);
	std::cout << "\n\tsecond\n";
	print_list(second);
	first.swap(second);
	std::cout << "\n\tfirst\n";
	print_list(first);
	std::cout << "\n\tsecond\n";
	print_list(second);
    


	std::cout << "\n\t\tCheck Resize\n";
    original.clear();
    original.push_back(12);
    original.push_back(16);
    original.push_back(121);

    std::cout << "\n\tResize to 2, value = 10\n";
	first.resize(2,10);
    original.resize(2,10);
    std::cout << "\n\tMy list\n";
	print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);

    std::cout << "\n\tResize to 5, value = 42\n";
	first.resize(5,42);
    original.resize(5,42);
    std::cout << "\n\tMy list\n";
	print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);
    

	std::cout << "\n\t\tCheck Clear\n";
	first.clear();
    original.clear();
    std::cout << "\n\tMy list\n";
	print_list(first);
    std::cout << "\n\tOriginal list\n";
    print_list(original);
//
//	std::cout << "\n\t\tCheck PushBack and PushFront\n";
//	std::cout << "\nfirst.push_back(31);";
//	std::cout << "\nfirst.push_front(32);\n";
//	forth.push_back(31);
//	forth.push_front(32);
//	forth.print_all();
//
//	std::cout << "\n\t\tCheck PopFront\n";
//	forth.pop_front();
//	forth.print_all();
//
//	std::cout << "\n\t\tCheck PopBack\n";
//	forth.pop_back();
//	forth.print_all();
//
//	std::cout << "\n\t\tCheck Swap\n";
//	std::cout << "first\n";
//	first.print_all();
//	std::cout << "second\n";
//	second.print_all();
//	first.swap(second);
//	std::cout << "first\n";
//	first.print_all();
//	std::cout << "second\n";
//	second.print_all();
//	std::cout << "\n\t\tCheck Resize\n";
//	std::cout << "first.resize(5,42);\n";
//	first.resize(5,42);
//	first.print_all();
//	std::cout << "first.resize(3,42);\n";
//	first.resize(3,42);
//	first.print_all();
//	std::cout << "first.resize(5,42);\n";
//	first.resize(5,42);
//	first.print_all();
//	std::cout << "\n\t\tRemove Check\n";
//	std::cout << "first.remove(42);\n";
//	first.remove(42);
//	first.print_all();
//
//	std::cout << "\n\t\tRemove If Check\n";
//	first.push_back(2);
//	first.push_back(4);
//	first.push_back(6);
//	std::cout << "first.remove_if (is_odd());\n";
//	first.print_all();
//	first.remove_if (is_odd());
//	first.print_all();
//
//	std::cout << "\n\t\tCheck Clear\n";
//	std::cout << "first.clear();\n";
//	first.clear();
//	first.print_all();
//
//	std::cout << "\n\t\tCheck Max size\n";
//	std::cout << "\nMax size: " << first.max_size() << "\n";
//	std::list<int> original;
//
//	std::cout << "\nMax size: " << original.max_size() << "\n";
//
//	std::cout << "\n\t\tCheck Sort\n";
//	first.push_back(3);
//	first.push_back(2);
//	first.push_back(1);
//	first.push_back(0);
//	first.print_all();
///*	first.sort();
//	first.print_all();
//	first.push_back(200);
//	first.push_back(201);
//	std::cout << "\n\t\tCheck Merge\n";
//	first.print_all();
//	second.print_all();
//	first.merge(second);
//	first.print_all();
//	ft::list<int>	six;
//	six.push_back(300);
//	six.push_back(301);
//	six.push_back(302);
//	six.print_all();
//	first.merge(six);
//	first.print_all();
//	six.print_all();
//	six.push_back(1);
//	six.push_back(10);
//	six.push_back(100);
//	first.merge(six);
//	first.print_all();
//
//	std::list<int> original1;
//	std::list<int> original2;
//	original1.push_back(100);
//	original1.push_back(2);
//	original1.push_back(40);
//	original2.push_back(1);
//	original2.push_back(10);
//	original2.push_back(20);
//	original1.merge(original2);
//	for(std::list<int>::iterator it = original1.begin(); it != original1.end(); it++)
//		std::cout << *it << "\t";*/
//	// int i;
//	// while (1)
//	// 	i++;
//	std::cout << "\n\t\tCheck Reverse\n";
//	first.print_all();
//	first.reverse();
//	first.print_all();
//	std::cout << "\n\t\tCheck Iterator iter++\n";
//	ft::list<int>::iterator iter = first.begin();
////	ft::list<int>::iterator iter;
//	// iter = first.begin();
//	std::cout << *iter << std::endl;
//	iter++;
//	while (*iter != *first.begin())
//	{
//		std::cout << *iter << std::endl;
//		iter++;
//	}
//	std::cout << "\n\t\tCheck Iterator ++iter\n";
//	iter = first.begin();
//	std::cout << *iter << std::endl;
//	iter++;
//	while (*iter != *first.begin())
//	{
//		std::cout << *iter << std::endl;
//		++iter;
//	}
//	std::cout << "\n\t\tCheck Iterator --iter\n";
//	iter = first.begin();
//	iter--;
//	iter--;
//	while (*iter != *first.begin())
//	{
//		std::cout << *iter << std::endl;
//		iter--;
//	}
//	std::cout << *iter << std::endl;
//	std::cout << "\n\t\tCheck Iterator iter--\n";
//	iter = first.begin();
//	--iter;
//	iter--;
//	while (*iter != *first.begin())
//	{
//		std::cout << *iter << std::endl;
//		--iter;
//	}
//	std::cout << *iter << std::endl;
//	std::cout << "\n\t\tCheck Iterator *iter++\n";
//	iter = first.begin();
//	iter = first.begin();
//	//std::cout << "\nTwo iterators that compare equal, keep comparing equal after being both increased (*a++)\n";
//	std::cout << "non-original list begin " << *iter << std::endl;
//	std::cout << "non-original list begin " << *iter++ << std::endl;
//	std::cout << "non-original list begin " << *iter << std::endl;
//	original.clear();
//	original.push_back(0);
//	original.push_back(1);
//	original.push_back(2);
//	original.push_back(3);
//	std::list<int>::iterator list_iter_original = original.begin();
//	std::cout << "original list begin " << *list_iter_original << std::endl;
//	std::cout << "original list begin " << *list_iter_original++ << std::endl;
//	std::cout << "original list begin " << *list_iter_original << std::endl;
//
//	std::cout << "\n\t\tCheck == AND != \n";
//	std::cout << "\nif (iter==iter) -> ";
//	if (iter==iter)
//		std::cout << "TRUE\n";
//	else
//		std::cout << "FALSE\n";
//	std::cout << "if (iter!=iter) -> ";
//	if (iter!=iter)
//		std::cout << "TRUE\n";
//	else
//		std::cout << "FALSE\n";
//
//	std::cout << "\n\t\tCheck Const Iterator\n";
//	ft::list<int>::const_iterator const_iter = first.begin();
//	std::cout << "\n*const_iter\n";
//	std::cout << *const_iter << std::endl;
//	std::cout << "const_iter++ && *const_iter\n";
//	const_iter++;
//	std::cout << *const_iter << std::endl;
//
//	std::cout << "\n\t\tCheck BEGIN/END\n";
//	ft::list<int>::iterator begin = first.begin();
//	std::cout << "first elem " << *begin << std::endl;
//	begin = first.end();
//	std::cout << "last  elem " << *begin << std::endl;
//
//	std::cout << "\n\t\tCheck CONST BEGIN/END\n";
//	ft::list<int>::const_iterator c_begin = first.begin();
//	std::cout << "first elem " << *c_begin << std::endl;
//	c_begin = first.end();
//	std::cout << "last  elem " << *c_begin << std::endl;
//
//	std::cout << "\n\t\tCheck Reverse Iterator\n";
//	first.print_all();
//	std::cout << "\nCycle with plusing reverse iterator\n";
//	ft::list<int>::reverse_iterator rev_iter = first.rbegin();
//	while (*rev_iter != *(first.begin()))
//	{
//		std::cout << *rev_iter << "\t";
//		rev_iter++;
//	}
//	std::cout << *rev_iter << std::endl;
//	std::cout << "\n\t\tCheck Erase\n";
//	std::cout << "remove last iterator\n";
//	first.print_all();
//	first.erase(first.end());
//	std::cout << "first.erase(first.end());\n";
//	first.print_all();
//	std::cout << "remove all, except last\n";
//	first.erase(first.begin(), first.end());
//	std::cout << "\n\t\tCheck Insert\n";
//	first.push_back(3);
//	first.push_back(4);
//	first.push_back(5);
//	iter = first.end();
//	first.push_back(9);
//	first.push_back(10);
//	first.print_all();
//	std::cout << "iter points to element with content 5\n";
//	std::cout << "\nft::list<int>::iterator new_iter = first.insert(iter, 21);\n";
//	ft::list<int>::iterator new_iter = first.insert(iter, 21);
//	first.print_all();
//	std::cout << "return of insert: " << *new_iter << std::endl;
//	std::cout << "\nfirst.insert(iter, 2, 42);\n";
//	first.insert(iter, 2, 42);
//	first.print_all();
//	std::cout << "first.insert(new_iter, 2, 43);\n";
//	first.insert(new_iter, 2, 43);
//	first.print_all();
//	std::cout << "content of original list: ";
//	for (std::list<int>::iterator it1 = original.begin(); it1 != original.end(); it1++)
//		std::cout << *it1 << "\t";
//	std::cout << "\n";
//	std::cout << "\nfirst.insert(new_iter, original.begin(), original.end());\n";
//	first.insert(new_iter, original.begin(), original.end());
//	first.print_all();

//	std::cout << "\n\t\tCheck Reference\n";
//	std::cout << "\nreference to front\t" << first.front() << std::endl;
//	std::cout << "reference to back\t" << first.back() << std::endl;
//	std::cout << "\n\t\tCheck Slice 1\n";
//	first.print_all();
//	second.print_all();
//	first.splice(first.end(), second);
//	std::cout << "\nfirst.splice(first.end(), second);\n";
//	first.print_all();
//	second.print_all();
//	std::cout << "\n\t\tCheck Slice 2\n";
//	second.push_back(23);
//	second.push_back(24);
//	second.push_back(25);
//	first.print_all();
//	second.print_all();
//	first.splice(first.end(), second, second.begin());
//	first.print_all();
//	second.print_all();
//	std::cout << "\n\t\tCheck Slice 3\n";
//	first.print_all();
//	second.print_all();
//	first.splice(first.end(), second, second.begin(), second.end());
//	first.print_all();
//	second.print_all();
//	std::cout << "\n\t\tCheck Merge\n";
//	first.clear();
//	second.clear();
//
//	first.push_back(0);
//	first.push_back(1);
//	first.push_back(3);
//	first.push_back(5);
//	first.push_back(9);
//
//	second.push_back(2);
//	second.push_back(4);
//	second.push_back(6);
//	second.push_back(7);
//	second.push_back(8);
//	first.print_all();
//	second.print_all();
//	first.merge(second);
//    std::cout << "merged: \n";
//	first.print_all();
//	second.print_all();
//
//	std::cout << "\n\t\tCheck Sort\n";
//	first.clear();
//
//	first.push_back(0);
//	first.push_back(3);
//	first.push_back(9);
//	first.push_back(5);
//	first.push_back(1);
//	first.print_all();
//	first.sort();
//	first.print_all();
//	std::cout << "\n\t\tCheck Unique\n";
//	first.push_back(9);
//	first.push_back(9);
//	first.push_back(9);
//	first.push_back(5);
//	first.push_back(5);
//	first.push_back(9);
//	first.push_back(5);
//	first.push_back(5);
//	first.push_back(5);
//	first.print_all();
//	first.unique(equal);
//	first.print_all();
//	std::cout << "\n\t\tCheck Operation =\n";
//	std::cout << "first.print_all();\n";
//	first.print_all();
//	std::cout << "second.print_all();\n";
//	second.print_all();
//	second = first;
//	std::cout << "second = first;\n\n";
//	std::cout << "first.print_all();\n";
//	first.print_all();
//	std::cout << "second.print_all();\n";
//	second.print_all();
	// return (0);	
}