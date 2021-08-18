#pragma once

#include <memory>
// assign
// at

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
		
		private:
			pointer _begin;
			pointer _end;
			size_t _capacity;
		
		public:
			explicit vector (const allocator_type &alloc = allocator_type())
			: _begin(NULL), _end(NULL), _capacity(0) {};

			explicit vector (size_type n, const value_type &val = value_type(),
			const allocator_type& alloc = allocator_type()) : _capacity(n)
			{
				_begin = alloc.allocate(n);
				pointer _end = _begin;
				for (size_t i = 0; i < n; i++)
					alloc.construct(_end++, val);
				_end--;
			}

			// template <class InputIterator> vector (InputIterator first, InputIterator last,
			// const allocator_type& alloc = allocator_type());

			// vector (const vector& x);

			~vector()
			{
				// if _begin
				while (_begin != _end)
					alloc.destroy(_begin);
				
			}
	};
}