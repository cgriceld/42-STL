#pragma once

#include "utils.hpp"
#include "redb_tree_utils.hpp"
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
			Rb_header<T> header;
			allocator_type __alloc_;
			Compare __cmp_;

			void print_tree(Node<T> *node, std::string indent, bool right) const
			{
				if (node == header.tnull)
					return;
				std::cout << indent;
				if (right && (node != header.root))
				{
					std::cout << "R----";
					indent += "     ";
				}
				else if (!right)
				{
					std::cout << "L----";
					indent += "|    ";
				}
				std::cout << (node->color ? color_red : color_black) << node->data << res_color;
				print_tree(node->left, indent, false);
				print_tree(node->right, indent, true);
			}

			// Node<T> minimum(Node<T> *node, Node<T> *tnull)
			// {
			// while (node->left != tnull)
			// 		node = node->left;
			// 	return (node);
			// }

			// Node<T> *maximum(Node<T> *node, Node<T> *tnull)
			// {
			// 	while (node->right != tnull)
			// 		node = node->right;
			// 	return (node);
			// }

			Node<T> *new_node(const T &value)
			{
				Node<T> *n = __alloc_.allocate(1);
				__alloc_.construct(n, Node<T>(header.tnull, header.tnull, header.tnull, value));
				return n;
			}
			
			void rotate_left(Node<T> *x)
			{
				Node<T> *y = x->right;

				x->right = y->left;
				if (y->left != header.tnull)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == header.tnull)
					header.root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void rotate_right(Node<T> *x)
			{
				Node<T> *y = x->left;

				x->left = y->right;
				if (y->right != header.tnull)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == header.tnull)
					header.root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			void fix_insert(Node<T> *k)
			{
				Node<T> *u;
				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								rotate_right(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							rotate_left(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;

						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;	
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								rotate_left(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							rotate_right(k->parent->parent);
						}
					}
					if (k == header.root)
						break;
				}
				header.root->color = BLACK;
			}

		public:

			// ========================== CONSTRUCTORS & DESTRUCTOR ========================== //

			explicit Rb_tree(const allocator_type &alloc = allocator_type(), const Compare &cmp = Compare()) : \
					__alloc_(alloc), __cmp_(cmp)
			{
				header.tnull = __alloc_.allocate(1);
				__alloc_.construct(header.tnull, Node<T>(header.tnull));
				header.root = header.tnull;
				header.leftmost = header.tnull;
				header.rightmost = header.tnull;
			}

			// ========================== ITERATORS ========================== //

			iterator begin(void) { return (iterator(header.leftmost, &header)); };
			const_iterator begin(void) const { return (const_iterator(header.leftmost, &header)); };

			// reverse_iterator rbegin(void) { return (reverse_iterator(end())); };
			// const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(end())); };

			iterator end(void) { return (iterator(header.tnull, &header)); };
			const_iterator end(void) const { return (const_iterator(header.tnull, &header)); };

			// reverse_iterator rend(void) { return (reverse_iterator(begin())); };
			// const_reverse_iterator rend(void) const { return (const_reverse_iterator(begin())); };

			// ========================== MEMBER FUNCTIONS ========================== //

			//std::pair<iterator, bool>
			void insert (const T &value)
			{
				Node<T> *node = new_node(value);
				Node<T> *y = header.tnull;
				Node<T> *x = header.root;

				while (x != header.tnull)
				{
					y = x;
					x = node->data < x->data ? x->left : x->right;
				}

				node->parent = y;
				if (y == header.tnull)
					header.root = node;
				else if (node->data < y->data)
				{
					y->left = node;
				}
				else
				{
					y->right = node;
				}

				if (node->parent == header.tnull)
				{
					node->color = BLACK;
					print_tree(header.root, "", true);
					if (header.leftmost == header.tnull || node->data < header.leftmost->data)
						header.leftmost = node;
					if (header.rightmost == header.tnull || node->data > header.rightmost->data)
						header.rightmost = node;
					return;
				}

				if (node->parent->parent == header.tnull)
				{
					print_tree(header.root, "", true);
					if (header.leftmost == header.tnull || node->data < header.leftmost->data)
						header.leftmost = node;
					if (header.rightmost == header.tnull || node->data > header.rightmost->data)
						header.rightmost = node;
					return;
				}
				
				fix_insert(node);
				if (header.leftmost == header.tnull || node->data < header.leftmost->data)
					header.leftmost = node;
				if (header.rightmost == header.tnull || node->data > header.rightmost->data)
					header.rightmost = node;
				print_tree(header.root, "", true);
			}

			iterator insert (iterator position, const T &val);

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);
	};
}
