#ifndef IS_ITER_HPP
# define IS_ITER_HPP

# include "is_integral.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "rbt_iterator.hpp"

namespace ft
{
	
template<typename T> struct is_iter: public false_type {};
template<typename T> struct is_iter<const T>: public is_iter<T> {};

template<typename T> struct is_iter<typename ft::Iterator<T> >: public true_type {};
template<typename T> struct is_iter<typename ft::ReverseIterator<T> >: public true_type {};
template<typename T> struct is_iter<typename ft::RBT_iterator<T> >: public true_type {};

} // namespace ft


#endif