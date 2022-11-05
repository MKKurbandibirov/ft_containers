#ifndef MAP_HPP
# define MAP_HPP

# include "../util/pair.hpp"
# include "../util/reverse_iterator.hpp"
# include "../util/iterator_traits.hpp"
# include <functional>
# include <memory>
# include "../red_black_tree/rb_tree.hpp"


namespace ft
{
	
	template <class Key, class T>
	class map {
	private:
		rb_tree<ft::pair<Key, T> > tree;
	public:
		// types:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<key_type, mapped_type>							value_type;
		typedef std::less<Key> 											key_compare;
		typedef std::allocator<value_type> 								allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename ft::rb_tree<value_type>::iterator				iterator;
		typedef typename ft::rb_tree<value_type>::const_iterator		const_iterator;
		typedef std::size_t												size_type;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename allocator_type::pointer 						pointer;
		typedef typename allocator_type::const_pointer 					const_pointer;
		typedef ft::ReverseIterator<iterator>							reverse_iterator;
		typedef ft::ReverseIterator<const_iterator>						const_reverse_iterator;
		
	class value_compare {
    	friend class map;
    protected:
    	key_compare comp;
      	value_compare(key_compare c) : comp(c) {}
    public:
      	bool operator()(const value_type& x, const value_type& y) const {
        	return comp(x.first, y.first);
      	}
    };

	explicit map();
	template <class InputIterator>
		map(InputIterator first, InputIterator last);
	map(const map<Key,T>& other);
	~map();
	map<Key,T>& operator=(const map<Key,T>& other);

	// ------------- Iterators ------------- //
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	// // capacity:
	// bool empty() const;
	// size_type size() const;
	// size_type max_size() const;
	// // 23.3.1.2 element access:
	// T& operator[](const key_type& x);
	
	// ------------ Modifiers ------------ //
	pair<iterator, bool> insert(const value_type& x);
	iterator insert(iterator position, const value_type& x);
	template <class InputIterator>
		void insert(InputIterator first, InputIterator last);
	void erase(iterator position);
	size_type erase(const key_type& x);
	void erase(iterator first, iterator last);
	void swap(map<Key,T>&);
	void clear();

	// // observers:
	// key_compare key_comp() const;
	// value_compare value_comp() const;
	// // 23.3.1.3 map operations:
	// iterator find(const key_type& x);
	// const_iterator find(const key_type& x) const;
	// size_type count(const key_type& x) const;
	// iterator lower_bound(const key_type& x);
	// const_iterator lower_bound(const key_type& x) const;
	// iterator upper_bound(const key_type& x);
	// const_iterator upper_bound(const key_type& x) const;
	// pair<iterator,iterator>
	// equal_range(const key_type& x);
	// pair<const_iterator,const_iterator>
	// equal_range(const key_type& x) const;
	// };
	// template <class Key, class T, class Compare, class Allocator>
	// bool operator==(const map<Key,T,Compare,Allocator>& x,
	// const map<Key,T,Compare,Allocator>& y);
	// template <class Key, class T, class Compare, class Allocator>
	// bool operator< (const map<Key,T,Compare,Allocator>& x,
	// const map<Key,T,Compare,Allocator>& y);
	// template <class Key, class T, class Compare, class Allocator>
	// bool operator!=(const map<Key,T,Compare,Allocator>& x,
	// const map<Key,T,Compare,Allocator>& y);
	// template <class Key, class T, class Compare, class Allocator>
	// bool operator> (const map<Key,T,Compare,Allocator>& x,
	// const map<Key,T,Compare,Allocator>& y);
	// template <class Key, class T, class Compare, class Allocator>
	// bool operator>=(const map<Key,T,Compare,Allocator>& x,
	// const map<Key,T,Compare,Allocator>& y);
	// template <class Key, class T, class Compare, class Allocator>
	// bool operator<=(const map<Key,T,Compare,Allocator>& x,
	// const map<Key,T,Compare,Allocator>& y);
	// // specialized algorithms:
	// template <class Key, class T, class Compare, class Allocator>
	// void swap(map<Key,T,Compare,Allocator>& x,
	// map<Key,T,Compare,Allocator>& y);
	
	};
} // namespace ft

#include "map.tpp"

#endif