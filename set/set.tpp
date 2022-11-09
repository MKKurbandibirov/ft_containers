namespace ft
{

template<class key_type>
set<key_type>::set(): tree() {}

// template<class key_type>
// template<class InputIterator>
// set<key_type>::set(InputIterator first, InputIterator last,
// 	typename ft::enable_if<ft::is_iter<InputIterator>::value, InputIterator>::type*) {
	
// }

template<class key_type>
set<key_type>::~set() {}


// ------------- Iterators ------------- //
template<class key_type>
typename set<key_type>::iterator
set<key_type>::begin() {
	return iterator(tree.minimum(tree.root), tree);
}

template<class key_type>
typename set<key_type>::const_iterator
set<key_type>::begin() const {
	return const_iterator(tree.minimum(tree.root), tree);
}

template<class key_type>
typename set<key_type>::iterator
set<key_type>::end() {
	return iterator(tree.header.header, tree);
}

template<class key_type>
typename set<key_type>::const_iterator
set<key_type>::end() const {
	return const_iterator(tree.header.header, tree);
}

template<class key_type>
typename set<key_type>::reverse_iterator
set<key_type>::rbegin() {
	return reverse_iterator(end());
}

template<class key_type>
typename set<key_type>::const_reverse_iterator
set<key_type>::rbegin() const {
	return const_reverse_iterator(end());
}

template<class key_type>
typename set<key_type>::reverse_iterator
set<key_type>::rend() {
	return reverse_iterator(begin());
}

template<class key_type>
typename set<key_type>::const_reverse_iterator
set<key_type>::rend() const {
	return const_reverse_iterator(begin());
}

// ------------- Capacity ------------- //
template<class key_type>
bool set<key_type>::empty() const {
	if (tree.header.node_count <= 0) {
		return true;
	}
	return false;
}

template<class key_type>
typename set<key_type>::size_type
set<key_type>::size() const {
	return tree.header.node_count;
}

template<class key_type>
typename set<key_type>::size_type
set<key_type>::max_size() const {
	return tree.alloc.max_size();
}

} // namespace ft
