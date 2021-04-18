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
				public:
					my_iterator(node *ptr)
					{
						it_ptr = ptr;
						std::cout << "Constructor of my_iterator is called!\n";
					};
					friend class list<T>;
			};

			typedef class iterator : public my_iterator
			{
                public:
                    iterator(node *ptr) : my_iterator(ptr)
                    {
                        std::cout << "Constructor of iterator is called!\n";
                    };
					T	operator*()
					{
						return(this->it_ptr->data);
					};
					iterator &operator++()
					{
						this->it_ptr = this->it_ptr->next;
						return (*this);
					};
					iterator &operator--()
					{
						this->it_ptr = this->it_ptr->next;
						return (*this);
					};
					iterator operator++(int)
					{
						iterator old( *this );
						++(*this);
						return old;
					}
					iterator operator--(int)
					{
						iterator old( *this );
						--(*this);
						return old;
					}
			}  		iterator;

      		iterator begin()
			{
				iterator it(tail->next);
				std::cout << "Ha-ha, iterator\n";
				return (it); 
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