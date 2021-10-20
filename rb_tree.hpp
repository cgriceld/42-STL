#pragma once

#include "utils.hpp"
#include "rb_tree_utils.hpp"
#include <string>
#include <iostream>

namespace ft
{
	template < class T, class Compare, class Allocator = std::allocator<Node<T> > >
	class Rb_tree
	{
		public:
			typedef Allocator allocator_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;
			typedef Rb_tree_iterator<T> iterator;
			typedef Rb_tree_iterator<const T> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			Node *_root;
			Node *_tnull;
			allocator_type __alloc_;
			Compare __cmp_;

			void print_tree(Node *node, std::string indent, bool right) const
			{
				if (node == _tnull)
					return;
				std::cout << indent;
				if (right && (node != this->_root))
				{
					std::cout << "R----";
					indent += "     ";
				}
				else if (!right)
				{
					std::cout << "L----";
					indent += "|    ";
				}
				std::cout << (node->color ? color_red : color_black) << node->data << reset;
				print_tree(node->left, indent, false);
				print_tree(node->right, indent, true);
			}

			Node *minimum(Node *node) const
			{
				if (!node || node == _tnull)
					return (NULL);
				while (node->left != _tnull)
					node = node->left;
				return (node);
			}

			Node *maximum(Node *node) const
			{
				if (!node || node == _tnull)
					return (NULL);
				while (node->right != _tnull)
					node = node->right;
				return (node);
			}

			void base_insert()

		public:

			// ========================== CONSTRUCTORS & DESTRUCTOR ========================== //

			explicit Rb_tree(const allocator_type &alloc = allocator_type(), const Compare &cmp = Compare()) : \
					__alloc_(alloc), __cmp_(cmp)
			{
				_tnull = __alloc_.allocate(1);
				__alloc_.construct(_tnull, Node<T>());
				_root = _tnull;
			}

			// ========================== ITERATORS ========================== //

			iterator begin(void) { return (iterator(minimum(_root), _tnull)); };
			const_iterator begin(void) const { return (const_iterator(minimum(_root), _tnull)); };

			reverse_iterator rbegin(void) { return (reverse_iterator(end())); };
			const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(end())); };

			iterator end(void) { return (iterator(maximum(_root), _tnull)); };
			const_iterator end(void) const { return (const_iterator(maximum(_root), _tnull)); };

			reverse_iterator rend(void) { return (reverse_iterator(begin())); };
			const_reverse_iterator rend(void) const { return (const_reverse_iterator(begin())); };

			// ========================== MEMBER FUNCTIONS ========================== //

			std::pair<iterator, bool> insert (const value_type &value)
			{

			}

			iterator insert (iterator position, const value_type& val);

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);
	};
}
