#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <stdexcept>
# include <limits>

# include "vector_base.hpp"
# include "../util/reverse_iterator.hpp"
# include "../util/equal.hpp"
# include "../util/lexicographical_compare.hpp"
# include "../util/enable_if.hpp"
# include "../util/distance.hpp"
# include "../util/iterator_traits.hpp"
# include "../util/distance.hpp"
# include "../util/is_integral.hpp"

namespace ft
{
	template<class T>
	class vector : public vector_base<T> {
	public:
		typedef typename vector_base<T>::value_type value_type;
		typedef typename vector_base<T>::size_type size_type;
		typedef typename vector_base<T>::pointer pointer;
		typedef typename vector_base<T>::const_pointer const_pointer;
		typedef typename vector_base<T>::reference reference;
		typedef typename vector_base<T>::const_reference const_reference;
		typedef typename vector_base<T>::iterator iterator;
		typedef typename vector_base<T>::const_iterator const_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef std::allocator<T> allocator_type;
		typedef ft::ReverseIterator<iterator> reverse_iterator;
		typedef ft::ReverseIterator<const_iterator> const_reverse_iterator;

	private:
		size_type cap;
		allocator_type alloc;

	public:
		explicit vector();
		explicit vector(size_type n, const value_type& value = value_type());
		template <class InputIterator>
			vector(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
		vector(const vector& other);
		~vector();
		vector &operator=(const vector& other);
		template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
		void assign(size_type n, const_reference u);
		allocator_type get_allocator() const;

		// ------------- Iterators ----------- //
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// ------------- Capacity ------------- //
		size_type size() const;
		size_type max_size() const;
		void resize(size_type sz, value_type c = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve(size_type n);

		// ---------- Element Access ---------- //
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		const_reference at(size_type n) const;
		reference at(size_type n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		// ------------- Modifiers ------------- //
		void push_back(const_reference x);
		void pop_back();
		iterator insert(iterator position, const_reference x);
		void insert(iterator position, size_type n, const_reference x);
		template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<value_type>&);
		void clear();
	};

	template <class T>
	bool operator==(const vector<T>& x,const vector<T>& y) {
		if (&x == &y) {
			return true;
		}	
		if (x.size() != y.size()) {
			return false;
		}
		if (x.capacity() == y.capacity()) {
			return false;
		}
		
		return ft::equal(x.begin(), x.end(), y.begin());
	}

	template <class T>
	bool operator!=(const vector<T>& x,const vector<T>& y) {
		if (x == y) {
			return false;
		}
		return true;
	}

	template <class T>
	bool operator<=(const vector<T>& x,const vector<T>& y) {
		return x == y || x < y;
	}

	template <class T>
	bool operator>=(const vector<T>& x,const vector<T>& y) {
		return !(x < y);
	}

	template <class T>
	bool operator>(const vector<T>& x,const vector<T>& y) {
		return !(x <= y);
	}

	template <class T>
	bool operator<(const vector<T>& x,const vector<T>& y) {
		return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T>
	void swap(vector<T>& x, vector<T>& y) {
		x.swap(y);
	}
}

# include "vector.tpp"

#endif