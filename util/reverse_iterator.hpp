#pragma once

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
template<class T>
class ReverseIterator {
private:
	T iter;
public:
	typedef typename iterator_traits<T>::reference reference;
	typedef typename iterator_traits<T>::pointer pointer;
	typedef typename iterator_traits<T>::value_type value_type;
	typedef typename iterator_traits<T>::difference_type difference_type;
	typedef typename iterator_traits<T>::iterator_category iterator_category;

	ReverseIterator(): iter(NULL) {}
	ReverseIterator(T iter): iter(iter) {}
	ReverseIterator(const ReverseIterator& other): iter(other.iter) {}
	~ReverseIterator() {}
	ReverseIterator& operator=(const ReverseIterator& other) {
		if (this != &other) {
			iter = other.iter;
		}
		return *this;
	}

	// ReverseIterator& operator++();
	// ReverseIterator& operator--();
	// reference operator*();
	// bool operator==(const ReverseIterator& other) const;
	// bool operator!=(const ReverseIterator& other) const;	


	ReverseIterator& operator++() {
		--this->iter;
		return *this;
	}

	ReverseIterator& operator++(int d) {
		(void) d;
		--this->iter;
		return *this;
	}

	ReverseIterator& operator--() {
		++this->iter;
		return *this;
	}

	ReverseIterator& operator--(int d) {
		(void)d;
		++this->iter;
		return *this;
	}

	reference operator*() {
		T tmp = this->iter;
		return *--tmp;
	}

	pointer operator->() {
		return this->iter;
	}

	bool operator==(const ReverseIterator& other) const {
		return this->iter == other.iter;
	}

	bool operator!=(const ReverseIterator& other) const {
		return this->iter != other.iter;
	}

};

} // namespace ft

#endif