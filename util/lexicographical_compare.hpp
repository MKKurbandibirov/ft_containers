#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{

template<class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
	for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
		if (*first1 > *first2) {
			return false;
		}
	}
	return true;
}

} // namespace ft

#endif