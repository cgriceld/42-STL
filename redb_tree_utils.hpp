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

			Node() {};
			Node(Node *t) : parent(t), right(t), left(t), data(), color(BLACK) {};
			Node(Node *p, Node *r, Node *l, const T &d) : parent(p), right(r), left(l), data(d), color(RED) {};
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

	template <typename T>
	struct Rb_header
	{
		Node<T> *root;
		Node<T> *tnull;
		Node<T> *leftmost;
		Node<T> *rightmost;

		// Rb_header()
		// {
		// 	tnull = new Node<T>();
		// 	root = tnull;
		// 	leftmost = tnull;
		// 	rightmost = tnull;
		// }
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
				if (_ptr->right != _header->tnull)
				{
					_ptr = _ptr->right;
					while (_ptr->left != _header->tnull)
						_ptr = _ptr->left;
					return (*this);
				}
				Node *_y = _ptr->parent;
				while (_y != _header->tnull && _ptr == _y->right)
				{
					_ptr = _y;
					_y = _y->parent;
				}
				_ptr = _y;
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

			// // --ptr
			// Rb_tree_iterator &operator -- (void)
			// {
			// 	if (_ptr == _header->tnull)
			// 	{
			// 		_ptr = _header->rightmost;
			// 		return (*this);
			// 	}
			// 	if (_ptr->left != _header->tnull)
			// 	{
			// 		_ptr = _ptr->left;
			// 			while (_ptr != _header->tnull && _ptr->right != _header->tnull)
			// 				_ptr = _ptr->right;
			// 		return (*this);
			// 	}
			// 	Node *_y = _ptr;
			// 	_ptr = _ptr->parent;
			// 	while (_ptr != _header->tnull && _ptr->left == _y)
			// 	{
			// 		_y = _ptr;
			// 		_ptr = _ptr->parent;
			// 	}
			// 	return (*this);
			// }

			// --ptr
			Rb_tree_iterator &operator -- (void)
			{
				if (_ptr == _header->tnull)
				{
					_ptr = _header->rightmost;
					return (*this);
				}
				if (_ptr->left != _header->tnull)
				{
					_ptr = _ptr->left;
						while (_ptr != _header->tnull && _ptr->right != _header->tnull)
							_ptr = _ptr->right;
					return (*this);
				}
				Node *_y = _ptr->parent;
				while (_y != _header->tnull && _ptr == _y->left)
				{
					_ptr = _y;
					_y = _y->parent;
				}
				_ptr = _y;
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
