#pragma once

#include <memory>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		protected:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
		
			pointer __begin_;
			pointer __end_;
			pointer __end_cap_;
			allocator_type __alloc_;

		public:
			explicit vector (const allocator_type &alloc = allocator_type())
			: __begin_(NULL), __end_(NULL), __end_cap_(NULL), __alloc_(alloc) {};

			explicit vector (size_type n, const value_type &val = value_type(),
			const allocator_type& alloc = allocator_type()) : __alloc_(alloc)
			{
				__begin_ = __end_ = alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
					alloc.construct(__end_++, val);
				__end_cap_ = --__end_;
			}

			// template <class InputIterator> vector (InputIterator first, InputIterator last,
			// const allocator_type& alloc = allocator_type());

			// vector (const vector& x);

			~vector() 
			{
				//clear()

				// // if _begin
				// while (__begin_ != __end_)
				// 	alloc.destroy(__begin_);
				
			}

			reference operator[] (size_type n)
			{
				return (*(__begin_ + n));
			}

			const_reference operator[] (size_type n) const
			{
				return (*(__begin_ + n));
			}

			void clear(void)
			{
				
			}

			reference at (size_type n)
			{
				if (n < 0 || n >= size())
					throw std::out_of_range("index is out of range");
				return (*(__begin_ + n));
			}

			const_reference at (size_type n) const
			{
				if (n < 0 || n >= size())
					throw std::out_of_range("index is out of range");
				return (*(__begin_ + n));
			}

			size_type capacity(void) const
			{
				return (static_cast<size_type>(__end_cap_ - __begin_));
			}

			bool empty(void) const
			{
				return (__begin_ == __end_);
			}

			size_type size(void) const
			{
				return (static_cast<size_type>(__end_ - __begin_));
			}

			size_type max_size(void) const
			{
				return (__alloc_.max_size());
			}

			reference front(void)
			{
				return (*__begin_);
			}

			const_reference front(void) const
			{
				return (*__begin_);
			}

			reference back(void)
			{
				return (*(__end_ - 1));
			}

			const_reference back(void) const
			{
				return (*(__end_ - 1));
			}

			allocator_type get_allocator(void) const
			{
				return (__alloc_);
			}

			// operator = {assign(begin, end)}
	};
}