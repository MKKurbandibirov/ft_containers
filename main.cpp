#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

#include "enable_if.hpp"

#include "vector/vector.hpp"

// struct crutches
// {
// 	typedef ft::enable_if_t< true ,It>
// };


// template <typename It, typename T = ft::enable_if_t< true ,It> >
// void foo(It) {
// 	std::cout << "chlen" << std::endl;
// };

int main() {

	// {
	// 	std::vector<std::string> v;
	// 	v.push_back("0");
	// 	v.push_back("1");
	// 	v.push_back("2");
	// 	v.push_back("3");
	// 	v.push_back("4");
		
	// 	std::cout << v.size() << " " << v.capacity() << std::endl;
	// 	for (std::size_t i = 0; i < v.size(); ++i) {
	// 		std::cout << v[i] << " "; 
	// 	}
	// 	std::cout << std::endl;

	// 	std::vector<std::string>::reverse_iterator r_it = v.rbegin();
	// 	std::cout << *r_it << std::endl;
	// 	std::vector<std::string>::reverse_iterator re_it = v.rend();
	// 	// std::cout << *(--re_it) << std::endl;
	// 	// std::cout << *(--re_it) << std::endl;
	// 	--re_it;
	// 	while (r_it != re_it) {
	// 		std::cout << *re_it;
	// 		--re_it;
	// 	}
	// 	// std::cout << *r_it << " " << *re_it << " DIST: " << std::distance(r_it, re_it)<< std::endl ;

	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<std::string> ft_v;
	// 	ft_v.push_back("0");
	// 	ft_v.push_back("1");
	// 	ft_v.push_back("2");
	// 	ft_v.push_back("3");
	// 	ft_v.push_back("4");
		
	// 	std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
	// 	for (std::size_t i = 0; i < ft_v.size(); ++i) {
	// 		std::cout << ft_v[i] << " "; 
	// 	}
	// 	std::cout << std::endl;

	// 	ft::vector<std::string>::reverse_iterator ft_r_it = ft_v.rbegin();
	// 	// std::cout << *ft_r_it << std::endl;
	// 	ft::vector<std::string>::reverse_iterator ft_re_it = ft_v.rend();
	// 	--ft_re_it;
	// 	while (ft_r_it != ft_re_it) {
	// 		std::cout << *ft_re_it;
	// 		--ft_re_it;
	// 	}
	// 	// std::cout << *ft_r_it << " " << *ft_re_it  << " DIST: " << std::distance(ft_r_it, ft_re_it)<< std::endl ;
	// }

	{
		std::vector<int> v1(5, 6);
		std::vector<int> v2(7, 6);
		v1.pop_back();
		v1.pop_back();

		std::cout << std::boolalpha << std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;


		std::cout << "---------------------------------------------------------------------\n";

		ft::vector<int> ft_v1(4, 3);
		ft::vector<int> ft_v2(4, 3);
		ft_v1.pop_back();
		ft_v1.pop_back();

		std::cout << std::boolalpha << bool(ft_v1 == ft_v1) << std::endl;
	}	

	return 0;
}