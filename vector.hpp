#include <iostream>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		typedef	Alloc										allocator_type;
		typedef	T											value_type;
		typedef	ptrdiff_t									difference_type;
		typedef	size_t										size_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	T*											pointer;
		//const_pointer
		//iterator
		//const_iterator
		//reverse_iterator
		//const_reverse_iterator
		private:
			pointer 	_arr;
			int 		_capacity;
			int 		_size;
			Alloc		_alloc;
		
		public:
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_arr = NULL;
				_size = 0;
				_capacity = 0;
			};
			explicit vector (size_type n, const value_type& val = value_type(),
            	const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_capacity = n;
				pointer p = alloc.allocate(n);
				_arr = p;
				while (_size != n + 1)
				{
					alloc.construct(p, val);
					_size = _size + 1;
					p = p + 1;
				}
			};
			template <class InputIterator>
        	vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type())
			{
				int n = 0;

				for (InputIterator tmp = first; tmp != last; tmp++)
					n = n + 1;
				_size = n;
				pointer p = alloc.allocate(n);
						
			};
	};
}