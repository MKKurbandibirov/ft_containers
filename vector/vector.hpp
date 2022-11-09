#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <stdexcept>
# include <limits>

# include "../util/reverse_iterator.hpp"
# include "../util/equal.hpp"
# include "../util/lexicographical_compare.hpp"
# include "../util/enable_if.hpp"
# include "../util/distance.hpp"
# include "../util/iterator_traits.hpp"
# include "../util/distance.hpp"
# include "../util/is_integral.hpp"
# include "../util/iterator.hpp"

namespace ft
{
template<class T>
class vector {
public:
	typedef T 														value_type;
	typedef std::size_t 											size_type;
	typedef T* 														pointer;
	typedef const T* 												const_pointer;
	typedef T& 														reference;
	typedef const T& 												const_reference;
	typedef ft::Iterator<T>											iterator;
	typedef ft::Const_Iterator<T>									const_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef std::allocator<T> 										allocator_type;
	typedef ft::ReverseIterator<iterator> 							reverse_iterator;
	typedef ft::ReverseIterator<const_iterator>						const_reverse_iterator;

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
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
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

private:
	T* arr;
	std::size_t sz;
	size_type cap;
	allocator_type alloc;
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