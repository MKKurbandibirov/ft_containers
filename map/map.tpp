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
	return iterator(tree.root->minimum());
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::begin() const {
	return iterator(tree.root->minimum());
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::end() {
	return iterator(++tree.root->maximum());
}

template<class key_type, class mapped_type>
typename map<key_type, mapped_type>::const_iterator
map<key_type, mapped_type>::end() const {
	return iterator(++tree.root->maximum());
}

// ------------ Modifiers ------------ //
// template<class key_type, class mapped_type>
// typename ft::pair<typename map<key_type, mapped_type>::iterator, bool>
// map<key_type, mapped_type>::insert(const value_type& value) {
// 	Node<ft::pair<key_type, mapped_type> >* tmp = tree.find_node(value);
// 	if (tmp) {
// 		return ft::pair<iterator(tmp), false>;
// 	}
// 	return pair<iterator(tree.insert_node(value)), true>;
// }


} // namespace ft
