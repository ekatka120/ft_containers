#include <iostream>

namespace ft
{
	template < class T> class my_iterator
	{
		protected:
			T	*it_ptr;
	};
}

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class list
	{
		typedef	T												value_type;
		typedef	Alloc											allocator_type;
		typedef	ft::my_iterator<T>								iterator;

		// typedef	const_iterator;
		// typedef	reverse_iterator;
		// typedef	const_reverse_iterator;

		typedef	ptrdiff_t			difference_type;
		typedef	size_t				size_type;

		// typedef	std::allocator_type::reference					reference;
		// typedef	std::allocator_type::const_reference			const_reference;
		// typedef	std::allocator_type::pointer					pointer;
		// typedef	std::allocator_type::const_pointer				const_pointer;

		// STRUCTURE

		public: //Jiliet have public

			typedef struct s_node
			{
				T			data;
				iterator	next;
				iterator	prev;
			}				node;

			iterator 		tail;
		
		//	CONSTRUCTORS
		// MY PRINT CONSTRUCTOR
		// list()
		// {
		// 	std::cout << "HELLO!\n";
		// };

		// list()
		// {
		// 	std::cout << "Empty constructor is called!\n";
		// };
		explicit list (const allocator_type& alloc = allocator_type())
		{
			// tail = alloc();
			std::cout << "Empty constructor with alloc is called!\n";
		};
	};
}