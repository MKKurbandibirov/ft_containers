#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

template<class T>
class Iterator {
public:
	typedef T												value_type;
	typedef T*												pointer;
	typedef T&												reference;
	typedef typename iterator_traits<T*>::difference_type	difference_type;
	typedef typename iterator_traits<T*>::iterator_category	iterator_category;

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

	Iterator& operator++() {
		curr++;
		return *this;
	}

	Iterator& operator++(int d) {
		(void)d;
		curr++;
		return *this;
	}

	Iterator& operator--() {
		curr--;
		return *this;
	}

	Iterator& operator--(int d) {
		(void)d;
		curr--;
		return *this;
	}

	reference operator*() {
		return *curr;
	}

	bool operator==(const Iterator& other) const {
		return curr == other.curr;
	}

	bool operator!=(const Iterator& other) const {
		return curr != other.curr;
	}

	bool operator>(const Iterator& other) const {
		return curr > other.curr;
	}

	bool operator>=(const Iterator& other) const {
		return curr > other.curr || curr == other.curr;
	}

	bool operator<(const Iterator& other) const {
		return curr < other.curr;
	}

	bool operator<=(const Iterator& other) const {
		return curr < other.curr || curr == other.curr;
	}
	
	// Iterator& operator-(const Iterator& other);

	pointer base();
private:
	pointer curr;
};

template<class T>
class Const_Iterator {
public:
	typedef T												value_type;
	typedef T*												pointer;
	typedef T&												reference;
	typedef typename iterator_traits<T*>::difference_type	difference_type;
	typedef typename iterator_traits<T*>::iterator_category	iterator_category;

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

	Const_Iterator& operator++() {
		curr++;
		return *this;
	}

	Const_Iterator& operator++(int d) {
		(void)d;
		curr++;
		return *this;
	}

	Const_Iterator& operator--() {
		curr--;
		return *this;
	}

	Const_Iterator& operator--(int d) {
		(void)d;
		curr--;
		return *this;
	}

	reference operator*() {
		return *curr;
	}

	bool operator==(const Const_Iterator& other) const {
		return curr == other.curr;
	}

	bool operator!=(const Const_Iterator& other) const {
		return curr != other.curr;
	}

	bool operator>(const Const_Iterator& other) const {
		return curr > other.curr;
	}

	bool operator>=(const Const_Iterator& other) const {
		return curr > other.curr || curr == other.curr;
	}

	bool operator<(const Const_Iterator& other) const {
		return curr < other.curr;
	}

	bool operator<=(const Const_Iterator& other) const {
		return curr < other.curr || curr == other.curr;
	}

	// Iterator& operator-(const Iterator& other);

	pointer base();
private:
	pointer curr;
};


} // namespace ft


#endif