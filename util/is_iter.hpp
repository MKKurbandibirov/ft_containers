#ifndef IS_ITER_HPP
# define IS_ITER_HPP

# include "is_integral.hpp"
# include <iterator>
# include "reverse_iterator.hpp"
# include <vector>

namespace ft
{
	
	template<typename T> struct is_iter: public false_value {};
	template<typename T> struct is_iter<const T>: public is_iter<T> {}; 
	template<typename T> struct is_iter<volatile const T>: public is_iter<T> {}; 
	template<typename T> struct is_iter<volatile T>: public is_iter<T> {}; 

	template<typename T> struct is_iter<typename std::iterator<std::random_access_iterator_tag, T*> >: public true_value {};
	template<typename T> struct is_iter<typename ft::ReverseIterator<T*> >: public true_value {};
	template<typename T> struct is_iter<__gnu_cxx::__normal_iterator<T*, std::vector<T> > >: public true_value {};

} // namespace ft


#endif