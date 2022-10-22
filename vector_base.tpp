namespace ft {

// --------------- const iterator --------------- //
template<class value_type>
typename vector_base<value_type>::Const_Iterator& 
vector_base<value_type>::Const_Iterator::operator++() {
	curr++;
	return *this;
}

template<class value_type>
typename vector_base<value_type>::Const_Iterator& 
vector_base<value_type>::Const_Iterator::operator--() {
	curr--;
	return *this;
}

template<class value_type> 
bool vector_base<value_type>::Const_Iterator::operator==(const Const_Iterator& other) const {
	return curr == other.curr;
}

template<class value_type> 
bool vector_base<value_type>::Const_Iterator::operator!=(const Const_Iterator& other) const {
	return curr != other.curr;
}

template<class value_type>
typename vector_base<value_type>::const_reference
vector_base<value_type>::Const_Iterator::operator*() {
	return *curr;
}

template<class value_type>
typename vector_base<value_type>::pointer
vector_base<value_type>::Const_Iterator::base() {
	return curr;
}

// --------------- iterator --------------- //
template<class value_type>
typename vector_base<value_type>::Iterator& 
vector_base<value_type>::Iterator::operator++() {
	curr++;
	return *this;
}

template<class value_type>
typename vector_base<value_type>::Iterator& 
vector_base<value_type>::Iterator::operator--() {
	curr--;
	return *this;
}

template<class value_type> 
bool vector_base<value_type>::Iterator::operator==(const Iterator& other) const {
	return curr == other.curr;
}

template<class value_type> 
bool vector_base<value_type>::Iterator::operator!=(const Iterator& other) const {
	return curr != other.curr;
}

template<class value_type>
typename vector_base<value_type>::reference
vector_base<value_type>::Iterator::operator*() {
	return *curr;
}

template<class value_type>
typename vector_base<value_type>::pointer
vector_base<value_type>::Iterator::base() {
	return curr;
}

}