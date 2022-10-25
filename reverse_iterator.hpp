#pragma once

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
template<class T>
class ReverseIterator {
private:
	T iter;
public:
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

	ReverseIterator& operator++();
	ReverseIterator& operator--();
	const T& operator*();
	bool operator==(const ReverseIterator& other) const;
	bool operator!=(const ReverseIterator& other) const;	
};

template<class T>
ReverseIterator<T>& ReverseIterator<T>::operator++() {
	++this->iter;
	return *this;
}

template<class T>
ReverseIterator<T>& ReverseIterator<T>::operator--() {
	--this->iter;
	return *this;
}

template<class T>
const T& ReverseIterator<T>::operator*() {
	return *(this->iter);
}

template<class T>
bool ReverseIterator<T>::operator==(const ReverseIterator& other) const {
	return this->iter == other.iter;
}

template<class T>
bool ReverseIterator<T>::operator!=(const ReverseIterator& other) const {
	return this->iter != other.iter;
}

} // namespace ft

#endif