#ifndef DISTANCE_HPP
# define DISTANCE_HPP

# include "iterator_traits.hpp"

namespace ft
{
	
template<class It>
typename ft::iterator_traits<It>::difference_type
distance(It first, It last) {
	typename ft::iterator_traits<It>::difference_type result = 0;
    while (first != last) {
        ++first;
        ++result;
    }
    return result;
}

} // namespace ft


# endif