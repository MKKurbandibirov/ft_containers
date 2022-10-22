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
		this->alloc.construct(this->arr, value);
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
		this->alloc.construct(this->arr, other.arr[i]);
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
		this->alloc.construct(this->arr, other.arr[i]);
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
}