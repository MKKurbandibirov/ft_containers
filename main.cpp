// #include "vector.hpp"
#include <vector>
#include <iostream>

#include <stdio.h>

#include "vector.hpp"

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
	// 	// std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << std::endl;
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


		// ft::vector<int> _v(6);
		// _v[5] = 12;
		// std::cout << _v.sz;

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

	// {
	// 	std::vector<uint64_t> v(4);
	// 	v[0] = 0;
	// 	v[1] = 1;
	// 	v[2] = 2;
	// 	v[3] = 3;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;

	// 	v.reserve(6);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;

	// 	v.reserve(3);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<uint64_t> ft_v(4);
	// 	ft_v[0] = 0;
	// 	ft_v[1] = 1;
	// 	ft_v[2] = 2;
	// 	ft_v[3] = 3;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << std::endl;

	// 	ft_v.reserve(6);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << std::endl;

	// 	ft_v.reserve(3);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << std::endl;
	// }

	// {
	// 	std::vector<uint64_t> v(4);
	// 	v[0] = 0;
	// 	v[1] = 1;
	// 	v[2] = 2;
	// 	v[3] = 3;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;

	// 	v.resize(6, 9);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << " " << v[5] << std::endl;
	// 	v.resize(8);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;

	// 	v.resize(3);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<uint64_t> ft_v(4);
	// 	ft_v[0] = 0;
	// 	ft_v[1] = 1;
	// 	ft_v[2] = 2;
	// 	ft_v[3] = 3;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << std::endl;

	// 	ft_v.resize(6, 9);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << " " << ft_v[5] << std::endl;
	// 	ft_v.resize(8);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;

	// 	ft_v.resize(3);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << std::endl;
	// }

	// {
		// std::vector<uint64_t> v;
		// v.push_back(0);
		// v.push_back(1);
		// v.push_back(2);
		// v.push_back(3);
		// v.push_back(4);
		// std::cout << v.size() << " " << v.capacity() << std::endl;
		// std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;

		// std::cout << "---------------------------------------------------------------------\n";

		// ft::vector<uint64_t> ft_v;
		// ft_v.push_back(0);
		// ft_v.push_back(1);
		// ft_v.push_back(2);
		// ft_v.push_back(3);
		// ft_v.push_back(4);
		// std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
		// std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4]<< std::endl;
	// }

	// {
	// 	std::vector<uint64_t> v;
	// 	v.push_back(0);
	// 	v.push_back(1);
	// 	v.push_back(2);
	// 	v.push_back(3);
	// 	v.push_back(4);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;

	// 	v.pop_back();
	// 	v.pop_back();
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<uint64_t> ft_v;
	// 	ft_v.push_back(0);
	// 	ft_v.push_back(1);
	// 	ft_v.push_back(2);
	// 	ft_v.push_back(3);
	// 	ft_v.push_back(4);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4]<< std::endl;

	// 	ft_v.pop_back();
	// 	ft_v.pop_back();
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << std::endl;
	// }
	
	// {
	// 	std::vector<uint64_t> v(4, 4);

	// 	v.clear();
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<uint64_t> ft_v(4, 4);

	// 	ft_v.clear();
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << std::endl;
	// }

	// {
	// 	std::vector<uint64_t> v(4, 4);

	// 	std::vector<uint64_t>::iterator it = v.begin();
	// 	// v.pop_back();
	// 	++it;
	// 	++it;
	// 	++it;
	// 	std::vector<uint64_t>::iterator res = v.insert(v.begin(), 3);
	// 	std::cout << v.size() << " " << v.capacity() << " " << *res << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<uint64_t> ft_v(4, 4);

	// 	ft::vector<uint64_t>::iterator ft_it = ft_v.begin();
	// 	// ft_v.pop_back();
	// 	++ft_it;
	// 	++ft_it;
	// 	++ft_it;
	// 	ft::vector<uint64_t>::iterator ft_res = ft_v.insert(ft_v.begin(), 3);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << " " << *ft_res << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << std::endl;
	// }


	// {
	// 	std::vector<uint64_t> v(2, 4);

	// 	std::vector<uint64_t>::iterator it = v.begin();
		// v.pop_back();
	// 	++it;
	// 	// ++it;
	// 	// ++it;
	// 	v.insert(it,3, 3);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<uint64_t> ft_v(2, 4);

	// 	ft::vector<uint64_t>::iterator ft_it = ft_v.begin();
		// ft_v.pop_back();
	// 	++ft_it;
	// 	// ++ft_it;
	// 	// ++ft_it;
	// 	ft_v.insert(ft_it,3, 3);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << std::endl;
	// }

	// {
	// 	std::vector<uint64_t> v(1, 4);

	// 	v.push_back(2);
	// 	v.push_back(3);
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;
		
	// 	std::vector<uint64_t>::iterator it = v.begin();
	// 	// v.pop_back();
	// 	// ++it;
	// 	++it;
	// 	// ++it;

	// 	std::vector<uint64_t>::iterator res_it = v.erase(it);
	// 	std::cout << v.size() << " " << v.capacity() << " " << *res_it << std::endl;
	// 	std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<uint64_t> ft_v(1, 4);

	// 	ft_v.push_back(2);
	// 	ft_v.push_back(3);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << std::endl;
		
	// 	ft::vector<uint64_t>::iterator ft_it = ft_v.begin();
	// 	// ft_v.pop_back();
	// 	// ++ft_it;
	// 	++ft_it;
	// 	// ++ft_it;
		
	// 	ft::vector<uint64_t>::iterator ft_res_it  = ft_v.erase(ft_it);
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << " " << *ft_res_it << std::endl;
	// 	std::cout << ft_v[0] << " " << ft_v[1] << " " << ft_v[2] << " " << ft_v[3] << " " << ft_v[4] << std::endl;

	// }


	{
		std::vector<uint64_t> v;
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << v.size() << " " << v.capacity() << std::endl;
		for (std::size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << "\n";
		
		// std::vector<uint64_t>::iterator it = v.begin();
		// ++it;

		// std::vector<uint64_t>::iterator it1 = v.begin();
		// ++it1;
		// ++it1;
		// ++it1;

		std::vector<uint64_t>::iterator res_it = v.erase(v.begin(), v.end());
		std::cout << v.size() << " " << v.capacity() << " " << *res_it << std::endl;
		for (std::size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << "\n";
		

		std::cout << "---------------------------------------------------------------------\n";

		ft::vector<uint64_t> ft_v;
		ft_v.push_back(0);
		ft_v.push_back(1);
		ft_v.push_back(2);
		ft_v.push_back(3);
		ft_v.push_back(4);
		ft_v.push_back(5);
		std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
		for (std::size_t i = 0; i < ft_v.size(); ++i) {
			std::cout << ft_v[i] << " ";
		}
		std::cout << "\n";

		// ft::vector<uint64_t>::iterator ft_it = ft_v.begin();
		// ++ft_it;

		// ft::vector<uint64_t>::iterator ft_it1 = ft_v.begin();
		// ++ft_it1;
		// ++ft_it1;
		// ++ft_it1;
		
		ft::vector<uint64_t>::iterator ft_res_it  = ft_v.erase(ft_v.begin(), ft_v.end());
		std::cout << ft_v.size() << " " << ft_v.capacity() << " " << *ft_res_it << std::endl;
		for (std::size_t i = 0; i < v.size(); ++i) {
			std::cout << ft_v[i] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}