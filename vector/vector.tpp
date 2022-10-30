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

template<class value_type>
void vector<value_type>::assign(size_type n, const_reference u) {
	if (this->arr) {
		this->alloc.deallocate(this->arr, this->cap);
	}
	this->arr = this->alloc.allocate(n);
	this->sz = n;
	this->cap = n;
	for (size_type i = 0; i < this->sz; ++i) {
		this->arr[i] = u;
	}
}

// ------------------------ Iterators ------------------------ //
template<class value_type>
typename vector<value_type>::reverse_iterator
vector<value_type>::rbegin() {
	return reverse_iterator(this->end());
}

template<class value_type>
typename vector<value_type>::const_reverse_iterator
vector<value_type>::rbegin() const {
	return const_reverse_iterator(this->end());
}

template<class value_type>
typename vector<value_type>::reverse_iterator
vector<value_type>::rend() {
	// value_type tmp = this->begin();
	return reverse_iterator(this->begin());
}

template<class value_type>
typename vector<value_type>::const_reverse_iterator
vector<value_type>::rend() const {
	// value_type tmp = this->begin();
	return reverse_iterator(this->begin());
}


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
	return this->at(0);
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::front() const {
	return this->at(0);
}

template<class value_type>
typename vector<value_type>::reference
vector<value_type>::back() {
	return this->at(this->sz - 1);
}

template<class value_type>
typename vector<value_type>::const_reference
vector<value_type>::back() const {
	return this->at(this->sz - 1);
}

// ------------------- Modifiers ------------------- //
template<class value_type>
void vector<value_type>::push_back(const_reference x) {
	if (this->sz == 0) {
		this->reserve(1);
	}
	if (this->cap == this->sz) {
		this->reserve(2 * this->sz);
	}
	this->arr[this->sz] = x;
	++this->sz;
}

template<class value_type>
void vector<value_type>::pop_back() {
	--this->sz;
}

template<class value_type>
void vector<value_type>::clear() {
	this->sz = 0;
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::insert(iterator pos, const_reference x) {
	size_type ind = pos.base() - this->arr;
	iterator it_end = this->end();
	if (this->sz + 1 > this->cap) {
		reserve(this->cap * 2);
	}
	if (pos == it_end) {
		this->arr[this->sz] = x;
		++this->sz;
		return iterator(this->arr + ind);
	}
	++this->sz;
	value_type tmp = this->arr[ind];
	this->arr[ind] = x;
	for (size_type i = ind + 1; i < this->sz; ++i) {
		value_type temp = this->arr[i];
		this->arr[i] = tmp;
		tmp = temp;
	}
	return iterator(this->arr + ind);
}

template<class value_type>
void vector<value_type>::insert(iterator pos, size_type n, const_reference x) {
	if (n <= 0) {
		return;
	}
	size_type ind = pos.base() - this->arr;
	iterator it_end = this->end();
	if (this->sz + n > this->cap) {
		reserve(this->sz + n);
	}
	if (pos == it_end) {
		for (size_type i = 0; i < n; ++i) {
			this->arr[this->sz] = x;
			++this->sz;
		}
		return;
	}
	for (size_type i = 0; i < n; ++i) {
		++this->sz;
		value_type tmp = this->arr[ind];
		this->arr[ind] = x;
		for (size_type i = ind + 1; i < this->sz; ++i) {
			value_type temp = this->arr[i];
			this->arr[i] = tmp;
			tmp = temp;
		}
		++ind;
	}
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::erase(iterator pos) {
	size_type ind = pos.base() - this->arr;
	if (pos == --this->end()) {
		--this->sz;
		return this->end();
	}
	for (size_type i = ind + 1; i < this->sz; ++i) {
		this->arr[ind] = this->arr[i];
		++ind;
	}
	--this->sz;
	return pos;
}

template<class value_type>
typename vector<value_type>::iterator
vector<value_type>::erase(iterator first, iterator last) {
	if (first == last) {
		return last;
	}
	size_type f_ind = first.base() - this->arr, l_ind = last.base() - this->arr;
	size_type distance = l_ind - f_ind;
	while (last != this->end()) {
		this->arr[f_ind] = this->arr[l_ind];
		++f_ind;
		++l_ind;
		++last;
	}
	this->sz -= distance;
	return iterator(this->arr + (first.base() - this->arr));
}

template<class value_type>
void vector<value_type>::swap(vector<value_type>& other) {
	if (this->arr != other.arr) {
		std::swap(this->sz, other.sz);
		std::swap(this->cap, other.cap);
		std::swap(this->arr, other.arr);
	}
}

}