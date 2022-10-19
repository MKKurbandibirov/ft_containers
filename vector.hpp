#pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <iterator>
# include <stdexcept>
# include <limits>

namespace ft
{
	template <typename T>
	class vector {
	private:
		T* arr;
		std::size_t sz;
		std::size_t cap;
		std::allocator<T> alloc;
		// std::iterator<T> iter;

	public:

		// ---------- Construtors ---------- //
		vector(): sz(0), cap(0) {}

		vector(std::size_t sz): sz(sz), cap(sz) {
			arr = alloc.allocate(sz);
		}

		vector(std::size_t sz, T value): sz(sz), cap(sz) {
			arr = alloc.allocate(sz);
			for (std::size_t i = 0; i < sz; i++) {
				arr[i] = value;
			}
		}

		// vector(const vector& other) {
		// 	this->sz = other.sz;
		// 	this->cap = other.cap;
			
		// }

		// vector(std::iterator first, std::iterator last) {
			
		// 	while (first != last) {
				
		// 		++first;
		// 	}
		// }


		// vector(const vector& other) {
			
		// }

		// ------------ Iterators ------------ //
		T* begin() {
			return arr;
		}

		const T* begin() const {
			return arr;
		}

		T* end() {
			return arr + (sz - 1);
		}

		const T* end() const {
			return arr + (sz - 1);
		}

		// ------------- Capacity ------------- //
		std::size_t size() const {
			return this->sz;
		}

		std::size_t capacity() const {
			return this->cap;
		}

		std::size_t max_size() const {
			return std::numeric_limits<T>::max();
		}

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

	};
}

#endif