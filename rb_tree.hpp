#pragma once

#include "utils.hpp"
#include <string>
#include <iostream>

#define RED 0b00000001
#define BLACK 0b00000000

#define color_red "\033[1;31m"
#define color_black "\033[1;36m"
#define reset "\033[0m\n"

namespace ft
{
	template <typename T>
	class Node
	{
		public:
			Node *parent;
			Node *right;
			Node *left;
			T data;
			unsigned char color;

			Node() : parent(NULL), right(NULL), left(NULL), data(), color(BLACK) {};
			Node (const Node &other) : parent(other.parent), right(other.right), left(other.left), \
										data(other.data), color(other.color) {};
			~Node() {};

			Node &operator = (const Node &other)
			{
				if (this != &other)
				{
					parent = other.parent;
					right = other.right;
					left = other.left;
					color = other.color;
				}
				return (*this);
			}
	};

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

		private:
			Node *root;
			Node *tnull;
			allocator_type __alloc_;
			Compare __cmp_;

			void print_tree(Node *node, std::string indent, bool right)
			{
				if (node == tnull)
					return;
				std::cout << indent;
				if (right && (node != this->root))
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

		public:

			// ========================== CONSTRUCTORS & DESTRUCTOR ========================== //

			explicit Rb_tree(const allocator_type &alloc = allocator_type(), const Compare &cmp = Compare()) : \
					__alloc_(alloc), __cmp_(cmp)
			{
				tnull = __alloc_.allocate(1);
				__alloc_.construct(Node<T>());
				root = tnull;
			}
	};
}
