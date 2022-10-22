#pragma once

#ifndef VECTOR_BASE_HPP
# define VECTOR_BASE_HPP

# include <iostream>

namespace ft{

template<class T>
class vector_base {
protected:
	vector_base() {}
	T* arr;
	std::size_t sz;

public:
	typedef T value_type;
	typedef std::size_t size_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;

	class Const_Iterator {
	private:
		pointer curr;
	public:
		Const_Iterator(): curr(NULL) {}
		Const_Iterator(pointer p): curr(p) {}
		Const_Iterator(const Const_Iterator& other): curr(other.curr) {}
		~Const_Iterator() {}
		Const_Iterator& operator=(const Const_Iterator& other) {
			if (this != &other) {
				curr = other.curr;
			}
			return *this;
		}

		Const_Iterator& operator++();
		Const_Iterator& operator--();
		const_reference operator*();
		bool operator==(const Const_Iterator& other) const;
		bool operator!=(const Const_Iterator& other) const;

		pointer base();
	};
	class Iterator {
	private:
		pointer curr;
	public:
		Iterator(): curr(NULL) {}
		Iterator(pointer p): curr(p) {}
		Iterator(const Iterator& other): curr(other.curr) {}
		~Iterator() {}
		Iterator& operator=(const Iterator& other) {
			if (this != &other) {
				curr = other.curr;
			}
			return *this;
		}

		Iterator& operator++();
		Iterator& operator--();
		reference operator*();
		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;

		pointer base();
	};
	typedef Iterator iterator;
	typedef Const_Iterator const_iterator;
};

}

# include "vector_base.tpp"
#endif