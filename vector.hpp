#pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <iterator>
# include <stdexcept>
# include <limits>

# include "vector_base.hpp"
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
		typedef std::allocator<T> allocator_type;
		// typedef ft::reverse_iterator<iterator> reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		size_type cap;
		allocator_type alloc;

	public:
		explicit vector();
		explicit vector(size_type n, const value_type& value = value_type());
		// template <class InputIterator>
			// vector(InputIterator first, InputIterator last);
		vector(const vector& other);
		~vector();
		vector &operator=(const vector& other);
		// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last);
		// void assign(size_type n, const T& u);
		allocator_type get_allocator() const;

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		size_type size() const;
		size_type max_size() const;
		void resize(size_type sz, T c = T());
		size_type capacity() const;
		bool empty() const;
		void reserve(size_type n);

		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		const_reference at(size_type n) const;
		reference at(size_type n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		void push_back(const T& x);
		void pop_back();
		iterator insert(iterator position, const T& x);
		void insert(iterator position, size_type n, const T& x);
		template <class InputIterator>
		void insert(iterator position,
		InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<T>&);
		void clear();
	};
}

# include "vector.tpp"

#endif