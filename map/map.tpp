namespace ft
{
	
template<class key_type, class mapped_type>
map<key_type, mapped_type>::map(): tree() {}



template<class key_type, class mapped_type>
map<key_type, mapped_type>::~map() {}

// ------------- Iterators ------------- //
template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::begin() {
	return iterator(tree.root->minimum(tree.root));
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::begin() const {
	return iterator(tree.root->minimum(tree.root));
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::end() {
	Node<ft::pair<key_type, mapped_type> >* node = tree.root->maximum(tree.root);
	iterator iter(node);
	return ++iter;
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::end() const {
	Node<ft::pair<key_type, mapped_type> >* node = tree.root->maximum(tree.root);
	return ++iterator(node);
}

// ------------ Modifiers ------------ //
template<class key_type, class mapped_type>
typename ft::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert(const value_type& value) {
	Node<ft::pair<key_type, mapped_type> >* tmp = tree.find_node(value);
	if (tmp) {
		typename map<key_type, mapped_type>::iterator iter(tmp);
		return ft::make_pare(iter, false);
	}
	typename map<key_type, mapped_type>::iterator iter(tree.insert_node(value));
	return ft::make_pare(iter, true);
}

// template<class key_type, class mapped_type>
// typename map<key_type, mapped_type>::iterator
// map<key_type, mapped_type>::insert(iterator position, const value_type& value) {
// 	void(position);
// 	return 
// }


} // namespace ft
