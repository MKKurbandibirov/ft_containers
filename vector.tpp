namespace ft {

// --------------------- Construct/Copy/Destruct --------------------- //
template<class value_type>
vector<value_type>::vector() {
	this->sz = 0;
	this->cap = 0;
	this->arr = NULL;
}

template<class value_type>
vector<value_type>::vector(size_type n, const value_type& value) {
	// if (n > max_size()) {
	// 	throw std::length_error()
	// }
	this->sz = n;
	this->cap = n;
	this->alloc = alloc;
	this->arr = this->alloc.allocate(n);
	if (!this->arr) {
		throw std::bad_alloc();
	}
	for (size_type i = 0; i < n; ++i) {
		this->arr[i] = value;
	}	
}

template<class value_type>
vector<value_type>::vector(const vector& other) {
	this->sz = other.sz;
	this->cap = other.cap;
	this->arr = this->alloc.allocate(this->sz);
	if (!this->arr) {
		throw std::bad_alloc();
	}
	for (size_type i = 0; i < this->sz; ++i) {
		this->arr[i] = other.arr[i];
	}
}

template<class value_type>
vector<value_type> &vector<value_type>::operator=(const vector& other) {
	if (this == &other) {
		return *this;
	}
	this->sz = other.sz;
	this->cap = other.cap;
	this->arr = this->alloc.allocate(this->sz);
	if (!this->arr) {
		throw std::bad_alloc();
	}
	for (size_type i = 0; i < this->sz; ++i) {
		this->arr[i] = other.arr[i];
	}
	return *this;
}

template<class value_type>
vector<value_type>::~vector() {
	if (this->arr) {
		this->alloc.deallocate(this->arr, this->cap);
	}
}

template<class value_type>
typename vector<value_type>::allocator_type
vector<value_type>::get_allocator() const {
	return this->alloc;
}

// ------------------------ Iterators ------------------------ //


// ------------------------ Capacity ------------------------ //
template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::size() const {
	return this->sz;
}

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::max_size() const {
	return std::numeric_limits<value_type>::max();
}

template<class value_type>
typename vector<value_type>::size_type
vector<value_type>::capacity() const {
	return this->cap;
}

template<class value_type>
bool vector<value_type>::empty() const {
	return this->sz > 0 ? true : false;
}

template<class value_type>
void vector<value_type>::reserve(size_type n) {
	if (n <= this->cap) {
		return;
	}
	pointer newarr = alloc.allocate(n);
	if (!newarr) {
		throw std::bad_alloc();
	}
	for (size_type i = 0; i < this->sz; ++i) {
		newarr[i] = this->arr[i];
	}
	this->alloc.deallocate(this->arr, this->sz);
	this->arr = newarr;
	this->cap = n;
}

template<class value_type>
void vector<value_type>::resize(size_type n, value_type c) {
	if (n > this->cap) {
		reserve(cap * 2);
	}
	for (size_type i = this->sz; i < n; ++i) {
		this->arr[i] = c;
	}
	this->sz = n;
}

// -------------------- Element Access ------------------- //
template<class value_type>
typename vector<value_type>::reference
vector<value_type>::operator[](size_type pos) {
	return *(this->arr + pos);
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::operator[](size_type pos) const {
	return *(this->arr + pos);
}

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::at(size_type pos) {
	if (pos > this->sz) {
		throw std::out_of_range("vector");
	}
	return this->arr[pos];
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::at(size_type pos) const {
	if (pos > this->sz) {
		throw std::out_of_range("vector");
	}
	return this->arr[pos];
}

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::front() {
	return *this->arr;
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::front() const {
	return *this->arr;
}

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::back() {
	return *(this->arr+(this->sz - 1));
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::back() const {
	return *(this->arr+(this->sz - 1));
}

}