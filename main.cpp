#include "vector.hpp"
#include <vector>

#include <stdio.h>

int main() {
	{
		std::vector<int> v;
		printf("Size: %lu\n", v.size());
		printf("Capacity: %lu\n", v.capacity());

		ft::vector<int> ft_v;
		printf("Size: %lu\n", ft_v.size());
		printf("Capacity: %lu\n", ft_v.capacity());
	}

	{
		std::vector<int> v(3);
		printf("Size: %lu\n", v.size());
		printf("Capacity: %lu\n", v.capacity());

		ft::vector<int> ft_v(3);
		printf("Size: %lu\n", ft_v.size());
		printf("Capacity: %lu\n", ft_v.capacity());
	}

	{
		std::vector<int> v(5, 123);
		std::cout << v[4] << " " << v.at(2) << " " << v.front() << " " << v.back() << "\n";
		try {
			v.at(9);
  		} catch(std::out_of_range& e) {
			std::cout << e.what() << "\n";
		}

		ft::vector<int> ft_v(5, 123);
		std::cout << ft_v[4] << " " << ft_v.at(2) << " " << ft_v.front() << " " << ft_v.back() << "\n";
		try {
			ft_v.at(9);
  		} catch(std::out_of_range& e) {
			std::cout << e.what()  << "\n";
		}
	}

	{
		std::vector<double> v;
		std::cout << v.max_size() << "\n";
		
		std::vector<double> ft_v;
		std::cout << ft_v.max_size() << "\n";
		v.data();
	}

	

	return 0;
}