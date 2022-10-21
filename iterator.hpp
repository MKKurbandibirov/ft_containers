#pragma once

#ifndef ITERATOR_HPP
# define ITERATOR HPP

namespace ft {
	template<typename T>
	class iterator
	{
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
	};

}

#endif