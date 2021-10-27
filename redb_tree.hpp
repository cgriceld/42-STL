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
			typedef Rb_tree_const_iterator<T> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			Rb_header<T> header;
			size_type __len_;
			allocator_type __alloc_;
			Compare __cmp_;

			void print_tree (Node<T> *node, std::string indent, bool right) const
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
				std::cout << (node->color ? color_red : color_black) << (node->data).first << res_color;
				print_tree(node->left, indent, false);
				print_tree(node->right, indent, true);
			}

			Node<T> *new_node (const T &value)
			{
				Node<T> *n = __alloc_.allocate(1);
				__alloc_.construct(n, Node<T>(header.tnull, value));
				return (n);
			}
			
			void rotate_left (Node<T> *x)
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

			void rotate_right (Node<T> *x)
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

			void insert_recolor (Node<T> *k, Node<T> *u)
			{
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
			}

			void insert_rebalance (Node<T> *k)
			{
				Node<T> *u;

				while (k != header.root && k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == RED)
							insert_recolor(k, u);
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
							insert_recolor(k, u);
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
				}
				header.root->color = BLACK;
			}

			void update_borders (Node<T> *node)
			{
				if (header.leftmost == header.tnull || __cmp_(node->data, header.leftmost->data))
					header.leftmost = node;
				if (header.rightmost == header.tnull || __cmp_(header.rightmost->data, node->data))
					header.rightmost = node;
			}

			void transplant (Node<T> *u, Node<T> *v)
			{
				if (u->parent == header.tnull)
					header.root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void delete_rebalance (Node<T> *x)
			{
				Node<T> *s;
				while (x != header.root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							rotate_left(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								rotate_right(s);
								s = x->parent->right;
							} 
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							rotate_left(x->parent);
							x = header.root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							rotate_right(x->parent);
							s = x->parent->left;
						}
						if (s->right->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								rotate_left(s);
								s = x->parent->left;
							} 
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							rotate_right(x->parent);
							x = header.root;
						}
					}
				}
				x->color = BLACK;
			}

			void init(void)
			{
				header.tnull = __alloc_.allocate(1);
				__alloc_.construct(header.tnull, Node<T>(NULL));
				header.root = header.tnull;
				header.leftmost = header.tnull;
				header.rightmost = header.tnull;
				__len_ = 0;
			}

		public:

			// ========================== CONSTRUCTORS & DESTRUCTOR ========================== //

			explicit Rb_tree (const Compare &cmp = Compare(), const allocator_type &alloc = allocator_type()) : \
					__alloc_(alloc), __cmp_(cmp)
			{
				init();
			}

			template <class InputIterator>
			Rb_tree (InputIterator first, InputIterator last, const Compare &cmp = Compare(), \
					const allocator_type &alloc = allocator_type()): __alloc_(alloc), __cmp_(cmp)
			{
				init();
				insert(first, last);
			}

			Rb_tree (const Rb_tree &other): __alloc_(other.__alloc_), __cmp_(other.__cmp_)
			{
				init();
				insert(other.begin(), other.end());
			}

			Rb_tree &operator = (const Rb_tree &copy)
			{
				if (this == &copy)
					return (*this);
				clear();
				__alloc_ = copy.__alloc_;
				__cmp_ = copy.__cmp_;
				insert(copy.begin(), copy.end());
				return (*this);
			}

			~Rb_tree ()
			{
				clear();
				__alloc_.destroy(header.tnull);
				__alloc_.deallocate(header.tnull, 1);
			}

			// ========================== ITERATORS ========================== //

			iterator begin(void) { return (iterator(header.leftmost, &header)); };
			const_iterator begin(void) const { return (const_iterator(header.leftmost, &header)); };

			reverse_iterator rbegin(void) { return (reverse_iterator(end())); };
			const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(end())); };

			iterator end(void) { return (iterator(header.tnull, &header)); };
			const_iterator end(void) const { return (const_iterator(header.tnull, &header)); };

			reverse_iterator rend(void) { return (reverse_iterator(begin())); };
			const_reverse_iterator rend(void) const { return (const_reverse_iterator(begin())); };

			// ========================== MEMBER FUNCTIONS ========================== //

			ft::pair<iterator, bool> insert (const T &value)
			{
				Node<T> *y = header.tnull;
				Node<T> *x = header.root;

				while (x != header.tnull)
				{
					if (x->data == value)
						return (ft::make_pair(iterator(x, &header), false));
					y = x;
					x = __cmp_(value, x->data) ? x->left : x->right;
				}
				Node<T> *node = new_node(value);
				node->parent = y;
				if (y == header.tnull)
					header.root = node;
				else if (__cmp_(node->data, y->data))
					y->left = node;
				else
					y->right = node;
				if (node->parent == header.tnull)
					node->color = BLACK;
				else
				{
					if (node->parent->parent != header.tnull)
						insert_rebalance(node);
				}
				update_borders(node);
				print_tree(header.root, "", true);
				__len_++;
				return (ft::make_pair(iterator(node, &header), true));
			}

			iterator insert (iterator position, const T &val)
			{
				ft::pair<iterator, bool> res = insert(val);
				return (res.first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*first++);
			}

			iterator find (const T &val)
			{
				Node<T> *res = header.root;

				while (res != header.tnull && (res->data).first != val.first)
					res = __cmp_(val, res->data) ? res->left : res->right;
				return ((res->data).first == val.first ? iterator(res, &header) : end());
			}

			const_iterator find (const T &val) const
			{
				Node<T> *res = header.root;

				while (res != header.tnull && (res->data).first != val.first)
					res = __cmp_(val, res->data) ? res->left : res->right;
				return ((res->data).first == val.first ? const_iterator(res, &header) : end());
			}

			iterator lower_bound (const T &val)
			{
				iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (!__cmp_(*it, val))
						break;
				}
				return (it);
			}

			const_iterator lower_bound (const T &val) const
			{
				const_iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (!__cmp_(*it, val))
						break;
				}
				return (it);
			}

			iterator upper_bound (const T &val)
			{
				iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (__cmp_(val, *it))
						break;
				}
				return (it);
			}

			const_iterator upper_bound (const T &val) const
			{
				const_iterator it;

				for (it = begin(); it != end(); it++)
				{
					if (__cmp_(val, *it))
						break;
				}
				return (it);
			}

			size_type size (void) const
			{
				return (__len_);
			}

			void erase (iterator position)
			{
				Node<T> *pos = position.ptr();

				if (pos == header.leftmost)
					header.leftmost = (++position).ptr();
				if (pos == header.rightmost)
					header.rightmost = (--position).ptr();

				Node<T> *x, *y;
				y = pos;
				unsigned char y_original_color = y->color;
				if (pos->left == header.tnull)
				{
					x = pos->right;
					transplant(pos, pos->right);
				}
				else if (pos->right == header.tnull)
				{
					x = pos->left;
					transplant(pos, pos->left);
				}
				else
				{
					y = Node<T>::minimum(pos->right, header.tnull);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == pos)
						x->parent = y;
					else
					{
						transplant(y, y->right);
						y->right = pos->right;
						y->right->parent = y;
					}
					transplant(pos, y);
					y->left = pos->left;
					y->left->parent = y;
					y->color = pos->color;
				}
				__alloc_.destroy(pos);
				__alloc_.deallocate(pos, 1);
				if (y_original_color == BLACK)
					delete_rebalance(x);
				__len_--;
				print_tree(header.root, "", true);
			}

			void erase (iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			void clear (void)
			{
				erase(begin(), end());
			}
	};
}
