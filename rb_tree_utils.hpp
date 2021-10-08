#pragma once

#define RED 0b00000001
#define BLACK 0b00000000

#define color_red "\033[1;31m"
#define color_black "\033[1;36m"
#define reset "\033[0m\n"

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

	template <class T>
	class Rb_tree_iterator : public iterator <bidirectional_iterator_tag, T>
	{
		public:
			typedef ft::Node<T> Node;
			typedef typename Rb_tree_iterator<T>::pointer pointer;
			typedef typename Rb_tree_iterator<T>::reference reference;

		// ---------------- CONSTRUCTORS & DESTRUCTOR ---------------- //

			Rb_tree_iterator() : _ptr(NULL), _tnull(NULL) {}
			explicit Rb_tree_iterator(Node *ptr, Node *tnull) : _ptr(ptr), _tnull(tnull) {}
			Rb_tree_iterator(const Rb_tree_iterator &copy): _ptr(copy._ptr), _tnull(copy._tnull) {}

			Rb_tree_iterator &operator = (const Rb_tree_iterator &copy)
			{
				if (this != &copy)
					_ptr = copy._ptr;
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
				if (_ptr && _ptr != _tnull)
				{
					if (_ptr->right != _tnull)
					{
						_ptr = _ptr->right;
						while (_ptr != _tnull && _ptr->left != _tnull)
							_ptr = _ptr->left;
					}
					else
					{
						Node *_y = _ptr;
						_ptr = _ptr->parent;
						while (_ptr != _tnull && _ptr->right == _y)
						{
							_y = _ptr;
							_ptr = _ptr->parent;
						}
					}
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

			Rb_tree_iterator &operator -- (void)
			{
				if (_ptr && _ptr != _tnull)
				{
					if (_ptr->left != _tnull)
					{
						_ptr = _ptr->left;
						while (_ptr != _tnull && _ptr->right != _tnull)
							_ptr = _ptr->right;
					}
					else
					{
						Node *_y = _ptr;
						_ptr = _ptr->parent;
						while (_ptr != _tnull && _ptr->left == _y)
						{
							_y = _ptr;
							_ptr = _ptr->parent;
						}
					}
				}
				return (*this);
			}

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
			Node *_tnull;
			Node *_ptr;
		};
}
