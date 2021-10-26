#pragma once

#include <functional>
#include "redb_tree.hpp"

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
				friend class map<Key, T, Compare, Alloc>;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
					
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator() (const value_type &x, const value_type &y) const
					{
						return (comp(x.first, y.first));
					}
			};

			private:
				ft::Rb_tree<ft::pair<const Key, T>, value_compare> __tree;
				allocator_type __alloc_;
				Compare __cmp_;

			public:
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef Rb_tree_iterator<value_type> iterator;
				typedef Rb_tree_iterator<const value_type> const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef std::size_t size_type;
				typedef std::ptrdiff_t difference_type;

				// ========================== CONSTRUCTORS & DESTRUCTOR ========================== //

				explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : \
								__cmp_(comp), __alloc_(alloc), __tree(value_compare(comp)) {};

				template<class InputIt>
				map(InputIt first, InputIt last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : \
								__cmp_(comp), __alloc_(alloc), __tree(first, last, value_compare(comp)) {};

				map(const map &other) : __cmp_(other.__cmp_), __alloc_(other.__alloc_), __tree(other.__tree) {};

				// ========================== ITERATORS ========================== //

				iterator begin(void) { return (__tree.begin()); };
				const_iterator begin(void) const { return (__tree.begin()); };

				reverse_iterator rbegin(void) { return (__tree.rbegin()); };
				const_reverse_iterator rbegin(void) const { return (__tree.rbegin()); };

				iterator end(void) { return (__tree.end()); };
				const_iterator end(void) const { return (__tree.end()); };

				reverse_iterator rend(void) { return (__tree.rend()); };
				const_reverse_iterator rend(void) const { return (__tree.rend()); };

				// ========================== MEMBER FUNCTIONS ========================== //

				ft::pair<iterator, bool> insert (const value_type &val)
				{
					return (__tree.insert(val));
				}

				iterator insert (iterator position, const value_type &val)
				{
					return (__tree.insert(position, val));
				}

				template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
				{
					__tree.insert(first, last);
				}

				mapped_type &operator[] (const key_type &k)
				{
					return (__tree.insert(ft::make_pair(k, T())).first->second);
				}
	};
}
