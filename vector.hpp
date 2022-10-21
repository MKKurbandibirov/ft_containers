#pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector>

# include <iostream>
# include <memory>
# include <iterator>
# include <stdexcept>
# include <limits>

namespace ft
{
	template <typename T>
	class vector {
	public:
		T* arr;
		std::size_t sz;
		std::size_t cap;
		std::allocator<T> alloc;

	public:
		class iterator {
		private:
			T* curr;
		
		public:
			iterator(T* p): curr(p) {}

			iterator& operator++() {
				curr++;
				return *this;
			}

			iterator& operator--() {
				curr--;
				return *this;
			}

			T& operator*() {
				return *curr;
			}

			bool operator==(const iterator& other) const {
				return *curr == *other.curr;
			}

			bool operator!=(const iterator& other) const {
				return *curr != *other.curr;
			}

			T* base() {
				return curr;
			}
		};

		// ---------- Construtors ---------- //
		vector(): sz(0), cap(0) {
			arr = NULL;
		}

		vector(std::size_t sz): sz(sz), cap(sz) {
			arr = alloc.allocate(sz);
		}

		vector(std::size_t sz, T value): sz(sz), cap(sz) {
			arr = alloc.allocate(sz);
			for (std::size_t i = 0; i < sz; ++i) {
				arr[i] = value;
			}
		}

		vector(const vector& other) {
			sz = other.sz;
			cap = other.cap;
			arr = alloc.allocate(sz);
			for (std::size_t i = 0; i < sz; ++i) {
				arr[i] = other.arr[i];
			}
		}

		vector& operator=(const vector& other) {
			if (this == &other) {
				return *this;
			}
			sz = other.sz;
			cap = other.cap;
			arr = alloc.allocate(sz);
			for (std::size_t i = 0; i < sz; ++i) {
				arr[i] = other.arr[i];
			}
			return *this;
		}

		vector(typename ft::vector<T>::iterator first, typename ft::vector<T>::iterator last) {
			sz = last.base() - first.base() ;
			cap = sz;
			arr = alloc.allocate(sz);
			for (std::size_t i = 0; first != last; ++i) {
				arr[i] = *first;
				++first;
			}
		}

		~vector() {
			if (arr != NULL) {
				alloc.deallocate(arr, cap);
			}
		}

		// ------------ Iterators ------------ //
		iterator begin() {
			return iterator(arr);
		}

		const iterator cbegin() const {
			return iterator(arr);
		}

		iterator end() {
			return iterator(arr + (sz - 1));
		}

		const iterator cend() const {
			return iterator(arr + (sz - 1));
		}

		// ------------- Capacity ------------- //
		std::size_t size() const {
			return sz;
		}

		std::size_t capacity() const {
			return cap;
		}

		std::size_t max_size() const {
			return std::numeric_limits<T>::max();
		}

		// void resize(std::size_t new_sz) {
		// 	if (cap < new_sz) {
		// 		try {
		// 			arr = alloc.allocate(new_sz - cap);
		// 		} catch(...) {
		// 			T* tmp = alloc.allocate(new_sz);
		// 			for (std::size_t i = 0; i < sz; ++i) {
		// 				tmp[i] = arr[i];
		// 			}
		// 			alloc.deallocate(arr, cap);
		// 			arr = tmp;
		// 		}
		// 		cap = new_sz;
		// 	} //else {
		// 	// 	alloc.deallocate(arr, cap - new_sz);
		// 	// }
		// 	sz = new_sz;
		// 	// cap = new_sz;
		// }

		// void resize(std::size_t new_sz, const T& value) {
			
		// }

		// ---------- Element Access ---------- //
		T& at(std::size_t pos) {
			if (pos > sz) {
				throw std::out_of_range("vector");
			}
			return *(arr + pos);
		}

		const T& at(std::size_t pos) const {
			if (pos > sz) {
				throw std::out_of_range("vector");
			}
			return *(arr + pos);
		}

		T& operator[](std::size_t pos) {
			return *(arr + pos);
		}

		const T& operator[](std::size_t pos) const {
			return *(arr + pos);
		}

		T& front() {
			return *(arr);
		}

		const T& front() const {
			return *(arr);
		}

		T& back() {
			return *(arr + (sz - 1));
		}

		const T& back() const {
			return *(arr + (sz - 1));
		}

		// -------------- Data Access -------------- //
		T* data() {
			return arr;
		}

		const T* data() const {
			return arr;
		}

		// --------------- Modifiers --------------- //
		// void push_back(const T& x) {

		// }

	};
}

#endif