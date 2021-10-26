#pragma once

#define RED 0b00000001
#define BLACK 0b00000000

#define color_red "\033[1;31m"
#define color_black "\033[1;36m"
#define res_color "\033[0m\n"

#include "iterator.hpp"

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

			Node(Node *n) : parent(n), right(n), left(n), color(BLACK) {};
			Node(Node *n, const T &d) : parent(n), right(n), left(n), data(d), color(RED) {};
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

			static Node *minimum(Node *node, Node *tnull)
			{
				while (node->left != tnull)
					node = node->left;
				return (node);
			}

			static Node *maximum(Node *node, Node *tnull)
			{
				while (node->right != tnull)
					node = node->right;
				return (node);
			}
	};

	template <typename T>
	struct Rb_header
	{
		Node<T> *root;
		Node<T> *tnull;
		Node<T> *leftmost;
		Node<T> *rightmost;
	};

	template <class T>
	class Rb_tree_iterator : public iterator <bidirectional_iterator_tag, T>
	{
		public:
			typedef ft::Node<T> Node;
			typedef typename Rb_tree_iterator<T>::pointer pointer;
			typedef typename Rb_tree_iterator<T>::reference reference;

		// ---------------- CONSTRUCTORS & DESTRUCTOR ---------------- //

			Rb_tree_iterator() : _ptr(NULL), _header(NULL) {}
			explicit Rb_tree_iterator(Node *ptr, Rb_header<T> *header) : _ptr(ptr), _header(header) {}
			Rb_tree_iterator(const Rb_tree_iterator &copy): _ptr(copy._ptr), _header(copy._header) {}

			Rb_tree_iterator &operator = (const Rb_tree_iterator &copy)
			{
				if (this != &copy)
				{
					_ptr = copy._ptr;
					_header = copy._header;
				}
				return (*this);
			}

			~Rb_tree_iterator() {}

		// ---------------- ACCESS ---------------- //

			reference operator * (void) const
			{
				return (_ptr->data);
			}

			pointer operator -> (void) const
			{
				return (&_ptr->data);
			}

		// ---------------- PLUS ---------------- //

			// ++ptr
			Rb_tree_iterator &operator ++ (void)
			{
				if (_ptr == _header->rightmost || _ptr == _header->tnull)
					_ptr = _ptr->right;
				else if (_ptr->right != _header->tnull)
					_ptr = Node::minimum(_ptr->right, _header->tnull);
				else
				{
					while (_ptr->parent != _header->tnull && _ptr == _ptr->parent->right)
						_ptr = _ptr->parent;
					_ptr = _ptr->parent;
				}
				return (*this);
			}

			// ptr++
			Rb_tree_iterator operator ++ (int)
			{
				Rb_tree_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

		// ---------------- MINUS ---------------- //

			// --ptr
			Rb_tree_iterator &operator -- (void)
			{
				if (_ptr == _header->leftmost)
					_ptr = NULL;
				else if (_ptr == _header->tnull)
					_ptr = _header->rightmost;
				else if (_ptr->left != _header->tnull)
					_ptr = Node::maximum(_ptr->left, _header->tnull);
				else
				{
					while (_ptr->parent != _header->tnull && _ptr == _ptr->parent->left)
						_ptr = _ptr->parent;
					_ptr = _ptr->parent;
				}
				return (*this);
			}

			// ptr--
			Rb_tree_iterator operator -- (int)
			{
				Rb_tree_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			// ---------------- COMPARE ---------------- //

			bool operator == (const Rb_tree_iterator &rhs) const
			{
				return (_ptr == rhs._ptr);
			}
			bool operator != (const Rb_tree_iterator &rhs) const 
			{
				return (_ptr != rhs._ptr);
			}

		private:
			Rb_header<T> *_header;
			Node *_ptr;
		};
}
