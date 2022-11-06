namespace ft
{
	
template<class key_type, class mapped_type>
map<key_type, mapped_type>::map(): tree() {}

template<class key_type, class mapped_type>
map<key_type, mapped_type>::map(const map& other) {
	const_iterator beg = other.begin();
	const_iterator end = other.end();
	while (beg != end) {
		insert(*beg);
		++beg;
	}
	tree.header = other.tree.header;
}

// template<class key_type, class mapped_type>
// template<class InputIterator>
// map<key_type, mapped_type>::map(InputIterator first, InputIterator last,
// 	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
// 	// if (first > last) {
// 	// 	throw std::length_error("map");
// 	// }
// 	// while (first != last) {
// 		insert(first, last);
// 		// ++first;
// 	// }
// }

template<class key_type, class mapped_type>
map<key_type, mapped_type>& map<key_type, mapped_type>::operator=(const map& other) {
	if (this == &other) {
		return *this;
	}
	const_iterator beg = other.begin();
	const_iterator end = other.end();
	while (beg != end) {
		insert(*beg);
		++beg;
	}
	tree.header = other.tree.header;
	return *this;
}

template<class key_type, class mapped_type>
map<key_type, mapped_type>::~map() {}

// ------------- Iterators ------------- //
template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::begin() {
	return iterator(tree.minimum(tree.root), tree.root, tree.header);
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::begin() const {
	return const_iterator(tree.minimum(tree.root), tree.root, tree.header);
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::end() {
	return iterator(tree.header.header, tree.root, tree.header);
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::end() const {
	return const_iterator(tree.header.header, tree.root, tree.header);
}

// ------------- Capacity ------------- //
template<class key_type, class mapped_type>
bool map<key_type, mapped_type>::empty() const {
	if (tree.header.node_count <= 0) {
		return true;
	}
	return false;
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::size_type
map<key_type, mapped_type>::size() const {
	return tree.header.node_count;
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::size_type
map<key_type, mapped_type>::max_size() const {
	return tree.alloc.max_size();
}

// ------------ Modifiers ------------ //
template<class key_type, class mapped_type>
typename ft::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert(const value_type& value) {
	Node<ft::pair<key_type, mapped_type> >* tmp = tree.find_node(value);
	if (tmp) {
		typename map<key_type, mapped_type>::iterator iter(tmp, tree.root, tree.header);
		return ft::make_pare(iter, false);
	}
	typename map<key_type, mapped_type>::iterator iter(tree.insert_node(value), tree.root, tree.header);
	return ft::make_pare(iter, true);
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::insert(iterator position, const value_type& value) {
	(void)position;
	return iterator(insert(value).first, tree.root, tree.header);
}

// template<class key_type, class mapped_type>
// template<class InputIterator>
// void map<key_type, mapped_type>::insert(InputIterator first, InputIterator last,
// 	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
// 	difference_type n = ft::distance(first, last);
// 	while (n--) {
// 		insert(*(first++));
// 	}
// }

template<class key_type, class mapped_type>
void map<key_type, mapped_type>::erase(iterator position) {
	if (empty()) {
		return;
	}
	tree.delete_node(tree.find_node(*position));
}

template<class key_type, class mapped_type>
void map<key_type, mapped_type>::erase(iterator first, iterator last) {
	if (empty()) {
		return;
	}
	difference_type n = ft::distance(first, last);
	allocator_type allocator;
	value_type* arr = allocator.allocate(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = *first;
		++first;
	}
	for (int i = 0; i < n; ++i) {
		tree.delete_node(tree.find_node(arr[i]));
	}
	allocator.deallocate(arr, n);
}


} // namespace ft
