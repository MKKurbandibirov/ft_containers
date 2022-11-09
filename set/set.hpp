#ifndef SET_HPP
# define SET_HPP

# include "../util/reverse_iterator.hpp"
# include "../util/iterator_traits.hpp"
# include <functional>
# include <memory>
# include "../red_black_tree/rb_tree.hpp"
# include "../util/equal.hpp"
# include "../util/lexicographical_compare.hpp"
# include "../util/distance.hpp"
# include "../util/enable_if.hpp"
# include "../util/is_iter.hpp"

namespace ft
{
	
template <class Key>
class set {
private:
	rb_tree<Key> tree;
public:
	// --------------------------------- Types --------------------------------- //
	typedef Key 													key_type;
	typedef Key 													value_type;
	typedef std::less<Key> 											key_compare;
	typedef std::less<Key> 											value_compare;
	typedef std::allocator<value_type> 								allocator_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typename ft::rb_tree<value_type>::iterator						iterator;
	typedef typename ft::rb_tree<value_type>::const_iterator		const_iterator;
	typedef std::size_t												size_type;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef typename allocator_type::pointer 						pointer;
	typedef typename allocator_type::const_pointer 					const_pointer;
	typedef ft::ReverseIterator<iterator>							reverse_iterator;
	typedef ft::ReverseIterator<const_iterator>						const_reverse_iterator;

	// -------------- Construct/Copy/Destroy -------------- //
	explicit set();
	// template <class InputIterator>
	// 	set(InputIterator first, InputIterator last,
	// 		typename ft::enable_if<ft::is_iter<InputIterator>::value, InputIterator>::type* = NULL);
	// set(const set<Key>& x);
	~set();
	// set<Key>& operator=(const set<Key>& x);

	// ------------- Iterators ------------- //
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	// ------------- Capacity ------------- //
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	// ------------ Modifiers ------------ //
	// pair<iterator,bool> insert(const value_type& x);
	// iterator insert(iterator position, const value_type& x);
	// template <class InputIterator>
	// 	void insert(InputIterator first, InputIterator last,
	// 		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
	// void erase(iterator position);
	// size_type erase(const key_type& x);
	// void erase(iterator first, iterator last);
	// void swap(set<Key>&);
	// void clear();

	// ------------- Observers ------------- //
	// key_compare key_comp() const;
	// value_compare value_comp() const;

	// ----------- Set Operations ----------- //
	// iterator find(const key_type& x) const;
	// size_type count(const key_type& x) const;
	// iterator lower_bound(const key_type& x) const;
	// iterator upper_bound(const key_type& x) const;
	// pair<iterator,iterator> equal_range(const key_type& x) const;
};

// template <class Key>
// bool operator==(const set<Key>& x,const set<Key>& y);

// template <class Key>
// bool operator!=(const set<Key>& x,const set<Key>& y);

// template <class Key>
// bool operator<=(const set<Key>& x,const set<Key>& y);

// template <class Key>
// bool operator>=(const set<Key>& x,const set<Key>& y);

// template <class Key>
// bool operator>(const set<Key>& x,const set<Key>& y);

// template <class Key>
// bool operator<(const set<Key>& x,const set<Key>& y);

// ---------- Specialized Algorithms ---------- //
// template <class Key>
// void swap(set<Key>& x,set<Key>& y);


} // namespace ft

#include "set.tpp"

#endif