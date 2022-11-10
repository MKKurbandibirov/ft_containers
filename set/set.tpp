namespace ft
{

template<class key_type>
set<key_type>::set(): tree() {}

template<class key_type>
template<class InputIterator>
set<key_type>::set(InputIterator first, InputIterator last,
	typename ft::enable_if<ft::is_iter<InputIterator>::value, InputIterator>::type*) {
	insert(first, last);
}

template<class key_type>
set<key_type>::set(const set& other) {
	const_iterator beg = other.begin();
	const_iterator end = other.end();
	while (beg != end) {
		insert(*beg);
		++beg;
	}
	tree.header = other.tree.header;
}

template<class key_type>
set<key_type>& set<key_type>::operator=(const set& other) {
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

// ------------ Modifiers ------------ //
template<class key_type>
typename ft::pair<typename set<key_type>::iterator, bool>
set<key_type>::insert(const value_type& value) {
	Node<key_type>* tmp = tree.find_node(value);
	if (tmp) {
		typename set<key_type>::iterator iter(tmp, tree);
		return ft::make_pair(iter, false);
	}
	typename set<key_type>::iterator iter(tree.insert_node(value), tree);
	return ft::make_pair(iter, true);
}

template<class key_type>
typename set<key_type>::iterator
set<key_type>::insert(iterator position, const value_type& value) {
	(void)position;
	return iterator(insert(value).first, tree);
}

template<class key_type>
template<class InputIterator>
void set<key_type>::insert(InputIterator first, InputIterator last,
	typename ft::enable_if<ft::is_iter<InputIterator>::value, InputIterator>::type*) {
	difference_type n = ft::distance(first, last);
	while (n--) {
		insert(*first);
		++first;
	}
}

template<class key_type>
void set<key_type>::erase(iterator position) {
	if (empty()) {
		return;
	}
	tree.delete_node(tree.find_node(*position));
}

template<class key_type>
typename set<key_type>::size_type
set<key_type>::erase(const key_type& x) {
	iterator it = find(x);
	if (it == end()) {
		return 0;
	}
	erase(it);
	return 1;
}

template<class key_type>
void set<key_type>::erase(iterator first, iterator last) {
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

template<class key_type>
void set<key_type>::swap(set<key_type>& other) {
	tree.swap(other.tree);
}

template<class key_type>
void set<key_type>::clear() {
	tree.clear_tree();
}

// ------------- Observers ------------- //
template<class key_type>
typename set<key_type>::key_compare
set<key_type>::key_comp() const {
	return key_compare();
}

template<class key_type>
typename set<key_type>::value_compare
set<key_type>::value_comp() const {
	return value_compare();
}

// ----------- Set Operations ----------- //
template<class key_type>
typename set<key_type>::iterator
set<key_type>::find(const key_type& val) const {
	Node<value_type>* node = tree.find_node(val);
	if (node == NULL) {
		return end();
	}
	return iterator(node, tree);
}

template<class key_type>
typename set<key_type>::size_type
set<key_type>::count(const key_type& val) const {
	Node<value_type>* node = tree.find_node(val);
	if (node == NULL) {
		return 0;
	}
	return 1;
}

template<class key_type>
typename set<key_type>::iterator
set<key_type>::lower_bound(const key_type& k) {
	iterator beg = begin();
	iterator end = this->end();
	key_compare comp = key_comp();
	while (beg != end) {
		if (!comp((*beg), k)) {
			return beg;
		}
		++beg;
	}
	return this->end();
}

template<class key_type>
typename set<key_type>::iterator
set<key_type>::upper_bound(const key_type& k) {
	iterator beg = begin();
	iterator end = this->end();
	key_compare comp = key_comp();
	while (beg != end) {
		if (comp(k, (*beg))) {
			return beg;
		}
		++beg;
	}
	return this->end();

}

template<class key_type>
typename ft::pair<typename set<key_type>::iterator,
	typename set<key_type>::iterator>
set<key_type>::equal_range(const key_type& k) const {
	const_iterator tmp = find(k);
	return ft::make_pair<const_iterator,const_iterator>(tmp, tmp);
}

} // namespace ft
