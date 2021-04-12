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
					size_t			size;
					node() {}
					node(T d) : data(d){}
					~node() {}
			};
        public:
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
				tail->size = 0;
				//сделать итератор на tail
				//tail_it = iterator(tail);
			};
			explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
			{
				std::cout << "\nTwo parametrs constructor is called!\n";
				tail = new node;
				tail->prev = tail;
				tail->next = tail;
				tail->data = 0;
				tail->size = 0;
				for (int i = 0; i != n; i++)
					push_back(val);
				//как мы засовывваем именно копию?
				//each element is a copy of val
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
				tail->size = 0;
				std::cout << "\nIterator constructor is called!\n";
				//std::cout << first;
				// for (;first != last; first++)
				// 	push_back((*first));
			};
			list (const list& x)
			{
				std::cout << "\nCopy constructor is called!\n";
				tail = new node;
				tail->prev = tail;
				tail->next = tail;
				tail->data = 0;
				tail->size = 0;
				//удалить все, что было
				//обнулить tail
				node	*tmp = x.tail->next;
				for (;tmp != x.tail; tmp = tmp->next)
					push_back(tmp->data);
			};

			//DESTRUCTOR
			~list()
			{

			};
			//PUSHES

            void push_back (const T& val)
            {
                node	*tmp;

                tmp = new node;
                tmp->data = val;

                tmp->size = 0;
                if (tail->size == 0)
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
                tail->size = tail->size + 1;
            };			

			void push_front (const value_type& val)
			{
                node	*tmp;

                tmp = new node;
                tmp->data = val;
				if (tail->size == 0)
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
				tail->size = tail->size + 1;			
			};

			void pop_front()
			{
				if (tail->size != 0)
				{
					node *tmp = tail->next;
					tail->next = tmp->next;
					tmp->next->prev = tail;
					tail->size = tail->size - 1;
					delete tmp;
				}
			};
			void pop_back()
			{
				if (tail->size != 0)
				{
					node *tmp = tail->prev;
					tmp->prev->next = tail;
					tail->prev = tmp->prev;
					tail->size = tail->size - 1;
					delete tmp;
				}				
			};

			void swap (list& x)
			{
				node 	*first;
				node	*second;
				size_t	size;

				// first = this->tail->next;
				// second = this->tail->prev;
				// size = this->tail->size;
				this->tail->next = x.tail->next;
				this->tail->prev = x.tail->prev;
				this->tail->size = x.tail->size;
				// x.tail->next = first;
				// x.tail->prev = second;
				// x.tail->size = size;
			}

            void	print_all()
            {
                node *tmp = tail;
                std::cout << "\nSize of List is " << tail->size << "\n";
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
			class my_iterator
			{
				protected:
					node    *it_ptr;
				public:
					my_iterator(node	*tmp)
					{
						std::cout << "Constructor of my iterator is called!\n";
						it_ptr = tmp;
					};
					friend class list<T>;
			};
	};
}