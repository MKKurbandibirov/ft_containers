#include "vector.hpp"
#include <vector>
#include <list>

#include <stdio.h>
int main() {
	// {
	// 	std::vector<int> v;
	// 	printf("Size: %lu\n", v.size());
	// 	printf("Capacity: %lu\n", v.capacity());

	// 	ft::vector<int> ft_v;
	// 	printf("Size: %lu\n", ft_v.size());
	// 	printf("Capacity: %lu\n", ft_v.capacity());
	// }

	// {
	// 	std::vector<int> v(3);
	// 	printf("Size: %lu\n", v.size());
	// 	printf("Capacity: %lu\n", v.capacity());

	// 	ft::vector<int> ft_v(3);
	// 	printf("Size: %lu\n", ft_v.size());
	// 	printf("Capacity: %lu\n", ft_v.capacity());
	// }

	// {
	// 	std::vector<int> v(5, 123);
	// 	std::cout << v[4] << " " << v.at(2) << " " << v.front() << " " << v.back() << "\n";
	// 	try {
	// 		v.at(9);
  	// 	} catch(std::out_of_range& e) {
	// 		std::cout << e.what() << "\n";
	// 	}

	// 	ft::vector<int> ft_v(5, 123);
	// 	std::cout << ft_v[4] << " " << ft_v.at(2) << " " << ft_v.front() << " " << ft_v.back() << "\n";
	// 	try {
	// 		ft_v.at(9);
  	// 	} catch(std::out_of_range& e) {
	// 		std::cout << e.what()  << "\n";
	// 	}
	// }

	// {
	// 	std::vector<double> v;
	// 	std::cout << v.max_size() << "\n";
		
	// 	std::vector<double> ft_v;
	// 	std::cout << ft_v.max_size() << "\n";
	// 	v.data();
	// }

	// {
	// 	ft::vector<int> ft_v(6);

	// 	ft::vector<int>::iterator beg = ft_v.begin();

	// 	ft::vector<int>::iterator end = ft_v.end();

	// 	ft_v[5] = 12;

	// 	std::cout << bool(beg == end) << " " << bool(beg != end) << " " << *beg << " " << *end << std::endl;


		ft::vector<int> _v(6);
		_v[5] = 12;
		std::cout << _v.sz;

		std::vector<int> sv(6);
		sv[5] = 5;
		std::cout << sv._Vector_base 
		// std::vector<int>::iterator _beg = _v.begin();

		// std::vector<int>::iterator _end = _v.end();


	// 	std::cout << bool(_beg == _end) << " " << bool(_beg != _end) << " " << *beg << " " << *end << std::endl;
	// }

	// {
	// 	ft::vector<double> ft_v(5);
	// 	ft_v[0] = 1.0;
	// 	ft_v[1] = 1.1;
	// 	ft_v[2] = 1.2;
	// 	ft_v[3] = 1.3;
	// 	ft_v[4] = 1.4;

	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << std::endl;
		
	// 	ft::vector<double> ft_c(ft_v);

	// 	std::cout << ft_c[0] << " " << ft_c[1] << " " << ft_c[2] << " " << ft_c[3] << " " << ft_c[4] << std::endl;

	// 	ft::vector<double> ft_a;
	// 	ft_a = ft_c;

	// 	std::cout << ft_a[0] << " " << ft_a[1] << " " << ft_a[2] << " " << ft_a[3] << " " << ft_a[4] << std::endl;
		
	// 	ft::vector<double> ft_i(ft_a.begin(), ft_a.end());

	// 	std::cout << ft_i.size() << std::endl;
	// }
	return 0;
}