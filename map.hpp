#pragma once

#include <functional>
#include "rb_tree.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, \
				class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const Key, T> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map<Key, Tp, Compare, Alloc>;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
					
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator() (const value_type &x, const value_type & y) const
					{
						return (comp(x.first, y.first));
					}
			}

			private:
					Rb_tree __tree;

			public:
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef std::size_t size_type;
				typedef std::ptrdiff_t difference_type;
	};
}
