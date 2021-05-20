#include <iostream>

namespace ft
{
	
	template<bool B, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };
	
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		typedef	Alloc						allocator_type;
		typedef	T							value_type;
		typedef	ptrdiff_t					difference_type;
		typedef	size_t						size_type;
		typedef	typename allocator_type::reference					reference;
		// typedef T&	reference;
		typedef	typename allocator_type::const_reference			const_reference;

		private:
			class node
			{
				public:
					T				data;
					node			*next;
					node			*prev;
					node() {}
					node(T d) : data(d){}
					~node() {}
			};
			size_type			_size;

			static	bool	my_comp(value_type &first, value_type &second)
			{
				if (first < second)
					return (true);
				else
					return (false);
			};

			node 				*get_tail()
			{
				return (tail);
			};
			node 				*tail;
		public:
			//CONSTRUCTOR

			explicit list (const allocator_type& alloc = allocator_type())
			{
				std::cout << "\nEmpty constructor is called!\n";
				tail = new node;
				tail->prev = tail;
				tail->next = tail;
				tail->data = 0;
				_size = 0;
			};
			explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
			{
				std::cout << "\nTwo parametrs constructor is called!\n";
				tail = new node;
				tail->prev = tail;
				tail->next = tail;
				tail->data = 0;
				_size = 0;
				for (int i = 0; i != n; i++)
					push_back(val);
			};
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(), typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
			{
				//Проверяем перегружена ли зввездочка у обоих этих объектов, если перегружена у обох, то это итераторы
				tail = new node;
				tail->prev = tail;
				tail->next = tail;
				tail->data = 0;
				_size = 0;
				std::cout << "\nIterator constructor is called!\n";
			};
			list (const list& x)
			{
				std::cout << "\nCopy constructor is called!\n";
				tail = new node;
				tail->prev = tail;
				tail->next = tail;
				tail->data = 0;
				_size = 0;
				//удалить все, что было
				//обнулить tail
				node	*tmp = x.tail->next;
				for (;tmp != x.tail; tmp = tmp->next)
					push_back(tmp->data);
			};

			~list()
			{

			};

            void push_back (const T& val)
            {
                node	*tmp;

                tmp = new node;
                tmp->data = val;

                if (_size == 0)
                {
                    tmp->prev = tail;
                    tail->next = tmp;
                }
                else
                {
                    tmp->prev = tail->prev;
                    tail->prev->next = tmp;
                }
                tmp->next = tail;
                tail->prev = tmp;
                _size = _size + 1;
            };			

			void push_front (const value_type& val)
			{
                node	*tmp;

                tmp = new node;
                tmp->data = val;
				if (_size == 0)
				{
					tmp->next = tail;
					tail->prev = tmp;
				}
				else
				{
					tail->next->prev = tmp;
					tmp->next = tail->next;
				}
				tmp->prev = tail;
				tail->next = tmp;
				_size = _size + 1;			
			};

			void pop_front()
			{
				if (_size != 0)
				{
					node *tmp = tail->next;
					tail->next = tmp->next;
					tmp->next->prev = tail;
					_size = _size - 1;
					delete tmp;
				}
			};
			void pop_back()
			{
				if (_size != 0)
				{
					node *tmp = tail->prev;
					tmp->prev->next = tail;
					tail->prev = tmp->prev;
					_size = _size - 1;
					delete tmp;
				}				
			};

			void swap (list& x)
			{
				node 	*prev_tail_first;
				node	*next_tail_first;
				size_t	_size;


				next_tail_first = this->tail->next;
				prev_tail_first = this->tail->prev;
				_size = this->_size;

				//Work with this

				this->tail->next = x.tail->next;
				this->tail->prev = x.tail->prev;
				this->_size = x._size;
				x.tail->next->prev = this->tail;
				x.tail->prev->next = this->tail;

				//Work with x

				x.tail->next = next_tail_first;
				x.tail->prev = prev_tail_first;
				x._size = _size;
				next_tail_first->prev = x.tail;
				prev_tail_first->next = x.tail;
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					while (this->_size != n)
						pop_back();
				}
				else if (n > this->_size)
				{
					while (this->_size != n)
						push_back(val);
				}
			};

			void clear()
			{
				while (this->_size != 0)
					pop_back();
			};



			bool empty() const
			{
				if (_size == 0)
					return (true);
				else
					return (false);
			};

			size_type max_size() const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(node));
			};
			size_type size() const
			{
				return (_size);
			};

			void remove (const value_type& val)
			{
				node *tmp = tail->next;
				while (tmp != tail)
				{
					if (tmp->data == val)
					{
						node *next = tmp->next;
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						delete tmp;
						tmp = next;
						_size = _size - 1;
					}
					else
						tmp = tmp->next;
				}
			};
			template <class Predicate>
			void remove_if (Predicate pred)//Нужно проверить
			{
				node *tmp = tail->next;
				while (tmp != tail)
				{
					if (pred(tmp->data) == true)
					{
						node *next = tmp->next;
						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						delete tmp;
						tmp = next;
						_size = _size - 1;
					}
					else
						tmp = tmp->next;
				} 
			};
			void reverse()
			{
				node *tmp = tail->next;
				node *tmp_new_next;
				
				while (tmp != tail)
				{
					tmp_new_next = tmp->next;
					tmp->next = tmp->prev;
					tmp->prev = tmp_new_next;
					tmp = tmp->prev;
				}
				tmp_new_next = tail->next;
				tail->next = tail->prev;
				tail->prev = tmp_new_next;	
			};

		//ITERATORS

			class my_iterator
			{
				protected:
					node    *it_ptr;
					node	*get_node()
					{
						return (it_ptr);
					};
				public:
					my_iterator()
					{
						it_ptr = NULL;
					};
					my_iterator(node *ptr)
					{
						it_ptr = ptr;
					};
					T	&operator*() const
					{
						return(this->it_ptr->data);
					};
					T *operator->() const
					{
						return (&(this->it_ptr->_data));
					};
					bool operator==(const my_iterator &y)
					{
						return (*this).it_ptr == y.it_ptr;
					};
					bool operator!=(const my_iterator &y)
					{
						return !((*this).it_ptr == y.it_ptr);
					};
					friend class list<T>;
			};

			typedef class iterator : public my_iterator
			{
                public:
					// CONSTRUCTORS
					iterator() : my_iterator()
					{};
					iterator(node *ptr) : my_iterator(ptr)
					{};
					iterator(const iterator& it)
                    {
						this->it_ptr = it.it_ptr;
                    };
					// OVERLOADING
					iterator &operator++()
					{
						this->it_ptr = this->it_ptr->next;
						return (*this);
					};
					iterator &operator--()
					{
						this->it_ptr = this->it_ptr->prev;
						return (*this);
					};
					iterator operator++(int)
					{
						iterator old( *this );
						++(*this);
						return old;
					};
					iterator operator--(int)
					{
						iterator old( *this );
						--(*this);
						return old;
					};
					iterator& operator=(const iterator& rhs) {
						this->it_ptr = rhs.it_ptr;
						return *this;
					};
			}  		iterator;
			typedef class const_iterator : public iterator
			{
                public:
					// CONSTRUCTORS
					const_iterator() : my_iterator()
					{};
					const_iterator(node *ptr) : my_iterator(ptr)
					{};
					const_iterator(const iterator& it)
                    {
						this->it_ptr = it.it_ptr;
                    };

			}  		const_iterator;
			typedef class reverse_iterator : public my_iterator
			{
				public:
					// CONSTRUCTORS
					reverse_iterator() : my_iterator()
					{};
					reverse_iterator(node *ptr) : my_iterator(ptr)
					{};
					reverse_iterator(const iterator& it)
                    {
						this->it_ptr = it.it_ptr;
                    };
					// OVERLOADING
					reverse_iterator &operator++()
					{
						this->it_ptr = this->it_ptr->prev;
						return (*this);
					};
					reverse_iterator &operator--()
					{
						this->it_ptr = this->it_ptr->next;
						return (*this);
					};
					reverse_iterator operator++(int)
					{
						reverse_iterator old( *this );
						++(*this);
						return old;
					};
					reverse_iterator operator--(int)
					{
						reverse_iterator old( *this );
						--(*this);
						return old;
					};
					reverse_iterator& operator=(const reverse_iterator& rhs) {
						this->it_ptr = rhs.it_ptr;
						return *this;
					};
			}  		reverse_iterator;
			
			typedef class const_reverse_iterator : public reverse_iterator
			{
                public:
					// CONSTRUCTORS
					const_reverse_iterator() : my_iterator()
					{};
					const_reverse_iterator(node *ptr) : my_iterator(ptr)
					{};
					const_reverse_iterator(const iterator& it)
                    {
						this->it_ptr = it.it_ptr;
                    };

			}  		const_reverse_iterator;
      		
			iterator begin()
			{
				iterator it(tail->next);
				return (it); 
			};
			const_iterator begin() const
			{
				const_iterator it(tail->next);
				return (it); 				
			};
      		iterator end()
			{
				iterator it(tail->prev);
				return (it); 				
			};
			const_iterator end() const
			{
				const_iterator it(tail->prev);
				return (it); 				
			};
      		reverse_iterator rbegin()
			{
				reverse_iterator it(tail->prev);
				return (it); 				
			};
			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator it(tail->prev);
				return (it); 				
			};
			reverse_iterator rend()
			{
				reverse_iterator it(tail->next);
				return (it); 					
			};
			const_reverse_iterator rend() const
			{
				const_reverse_iterator it(tail->next);
				return (it); 				
			};
			iterator erase (iterator position)
			{
				node		*tmp;
				iterator	next_to_tmp;

				next_to_tmp = position;
				tmp = position.get_node();
				if (tmp != tail && tmp != NULL)
				{
					next_to_tmp = position++;
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					_size = _size - 1;
					delete tmp;
				}
				return (next_to_tmp);
			};
			iterator erase (iterator first, iterator last)
			{
				iterator tmp;
				for (tmp = first; tmp != last; tmp++)
				{
					//check for tail inside interval ->if it is, do nothing
					if (tmp.get_node() == tail)
						return (tmp);
				}
				for (tmp = first; tmp != last; tmp++)
					erase(tmp);
				return(tmp);
			};

			iterator insert (iterator position, const value_type& val)
			{
				node	*next = position.get_node();
				node	*new_node = new node;
				node	*prev = next->prev;
				iterator position_new = position;
				
				new_node->data = val;
				prev->next = new_node;
				new_node->prev = prev;
				new_node->next = next;
				next->prev = new_node;
				_size = _size + 1;
				position_new--;
				return (position_new);
			};
			void insert (iterator position, size_type n, const value_type& val)
			{
				iterator position_new;
				
				for (int i = 0; i != n; i++)
					position_new = insert (position, val);
			};
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
			{
				iterator tmp;
				last--;
				for (tmp = position; last != first; last--)
				{
					tmp = insert(tmp, *last);
				}
				tmp = insert(tmp, *last);
			};
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
			{
				this->clear();
				for (; first != last; first++)
					push_back(*first);
			};	
			void assign (size_type n, const value_type& val)
			{
				this->clear();
				for (size_type i = 0; i != n; i++)
					push_back(val);
			};
     		reference front()
			{
				return (tail->next->data);
			};
			const_reference front() const
			{
				return (tail->next->data);
			};
			reference back()
			{
				return (tail->prev->data);
			};
			const_reference back() const
			{
				return (tail->prev->data);
			};

			void splice (iterator position, list& x)
			{
				node *next = position.get_node();
				node *prev = next->prev;

				prev->next = x.begin().get_node();
				(x.begin()).get_node()->prev = prev;
				x.end().get_node()->next = next;
				next->prev = x.end().get_node();
				_size = _size + x.size();
				x._size = 0;
				x.tail->next = x.tail;
				x.tail->prev = x.tail;
			};
			//2) Transfers the element pointed to by it from other into *this. The element is inserted before the element pointed to by pos.
			void splice (iterator position, list& x, iterator i)
			{
				node *next = position.get_node();
				node *prev = next->prev;
				node *new_node = i.get_node();
				if (new_node != x.tail)
				{
					new_node->prev->next = new_node->next;
					new_node->next->prev = new_node->prev;
					prev->next = new_node;
					new_node->prev = prev;
					next->prev = new_node;
					new_node->next = next;
					_size = _size + 1;
					x._size = x._size - 1;
				}
			};
			//3) Transfers the elements in the range [first, last) from other into *this. 
			//The elements are inserted before the element pointed to by pos. The behavior is undefined if pos is an iterator in the range [first,last).
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				node *next = position.get_node();
				node *prev = next->prev;
				bool	stop = false;
				int		len = 0;

				for (iterator iter_first = first; iter_first != last; iter_first++)
					len++;
				
				node	*first_node = first.get_node();
				node	*last_node = (last.get_node())->prev;

				first_node->prev->next = last_node->next;
				last_node->next->prev = first_node->prev;
				prev->next = first_node;
				first_node->prev = prev;
				next->prev = first_node;
				first_node->next = next;
				_size = _size + len;
				x._size = x._size - len;
			};
			template <class Compare>
  			void merge (list& other, Compare comp)
			{
				if (&other != this)
				{
					iterator tail_other = other.end();
					iterator tail_my = this->end();
					iterator my_iter = this->begin();
					iterator other_iter = other.begin();
					iterator tmp;
					tail_other++;
					tail_my++;

					while (true)
					{
						if (comp(*my_iter, *other_iter) == true)
							my_iter++;
						else
						{
							tmp = other_iter;
							tmp++;
							this->splice(my_iter, other, other_iter);
							other_iter = tmp;
							if (other_iter == tail_other)
								break;
						}
					}
				}
			};
			void merge (list& other)
			{
				merge(other, my_comp);
			};
			template <class Compare>
			void sort (Compare comp)
			{
				node	*tmp = tail->next;
				bool	swapped = true;

				while (swapped)
				{
					tmp = tail->next;
					swapped = false;
					while (tmp != tail)
					{
						if (tmp->next != tail && comp(tmp->data, tmp->next->data) == false)
						{
							node *tmp2;
							tmp2 = tmp->next;
							tmp2->next->prev = tmp;
							tmp->prev->next = tmp2;
							tmp->next = tmp2->next;
							tmp2->next = tmp;
							tmp2->prev = tmp->prev;
							tmp->prev = tmp2;
							swapped = true;
						}
						else
							tmp = tmp->next;
					}
				}
			};
			void sort()
			{
				this->sort(my_comp);
			};
			void unique()
			{
				node	*tmp_next;
				node	*tmp = this->tail->next;
				node	*tail = this->tail;

				while (tmp->next != tail)
				{
					tmp_next = tmp->next;
					if (tmp->data == tmp_next->data)
					{
						_size = _size - 1;
						tmp->next = tmp_next->next;
						tmp_next->next->prev = tmp;
						delete tmp_next;
					}
					else
						tmp = tmp->next;
				}
			};
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				node	*tmp_next;
				node	*tmp = this->tail->next;
				node	*tail = this->tail;
				
				while (tmp->next != tail)
				{
					tmp_next = tmp->next;
					if (binary_pred(tmp->data, tmp_next->data))
					{
						_size = _size - 1;
						tmp->next = tmp_next->next;
						tmp_next->next->prev = tmp;
						delete tmp_next;
					}
					else
						tmp = tmp->next;
				}
			};
			list& operator= (const list& x)
			{
				while (this->_size > 0)
					this->pop_back();
				node *tmp = x.tail->next;
				while (tmp != x.tail)
				{
					this->push_back(tmp->data);
					tmp = tmp->next;
				}
				return (*this);
			};

            void	print_all()
            {
                node *tmp = tail;
                std::cout << "\nSize of List is " << _size << "\n";
                tmp = tmp->next;
                int i = 1;
                while (tmp != tail)
                {
                    std::cout << i << "\t-\t" << tmp->data << '\n';
                    i++;
                    tmp = tmp->next;
                }
                std::cout << "\n";
            };

	};
}