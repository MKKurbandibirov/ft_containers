#pragma once

#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft
{
	
template <class T>
class stack: public vector<T>{
public:
	typedef typename vector<T>::value_type value_type;
	typedef typename vector<T>::size_type size_type;
	typedef vector<T> container_type;
private:
	container_type c;
public:
	explicit stack();
	bool empty() const { return c.empty(); }
	size_type size() const { return c.size(); }
	value_type& top() { return c.back(); }
	const value_type& top() const { return c.back(); }
	void push(const value_type& x) { c.push_back(x); }
	void pop() { c.pop_back(); }
};
	template <class T, class Container>
	bool operator==(const stack<T, Container>& x,
	const stack<T, Container>& y);
	template <class T, class Container>
	bool operator< (const stack<T, Container>& x,
	const stack<T, Container>& y);
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& x,
	const stack<T, Container>& y);
	template <class T, class Container>
	bool operator> (const stack<T, Container>& x,
	const stack<T, Container>& y);
	template <class T, class Container>
	bool operator>=(const stack<T, Container>& x,
	const stack<T, Container>& y);
	template <class T, class Container>
	bool operator<=(const stack<T, Container>& x,
	const stack<T, Container>& y);

} // namespace ft


#endif