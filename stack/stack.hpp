#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft
{
	
	template <class T>
	class stack: private vector<T>{
	public:
		typedef typename vector<T>::value_type value_type;
		typedef typename vector<T>::size_type size_type;
		typedef vector<T> container_type;
	private:
		container_type c;
	public:
		explicit stack(): c(){}

		bool empty() const { return this->c.empty(); }
		size_type size() const { return this->c.size(); }
		value_type& top() { return this->c.back(); }
		const value_type& top() const { return this->c.back(); }
		void push(const value_type& x) { this->c.push_back(x); }
		void pop() { this->c.pop_back(); }
	};

	template <class T>
	bool operator==(const stack<T>& x, const stack<T>& y) {
		return x.c == y.c;
	}

	template <class T>
	bool operator!=(const stack<T>& x, const stack<T>& y) {
		return x.c != y.c;
	}

	template <class T>
	bool operator<=(const stack<T>& x,  const stack<T>& y) {
		return x.c <= y.c;
	}

	template <class T>
	bool operator>=(const stack<T>& x,  const stack<T>& y) {
		return x.c >= y.c;
	}

	template <class T>
	bool operator<(const stack<T>& x,  const stack<T>& y) {
		return x.c < y.c;
	}

	template <class T>
	bool operator>(const stack<T>& x,  const stack<T>& y) {
		return x.c > y.c;
	}

} // namespace ft


#endif