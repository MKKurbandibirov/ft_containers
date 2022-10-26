#include <vector>
#include <iostream>

#include "vector/vector.hpp"

int main() {

	{
		std::vector<std::string> v;
		v.push_back("0");
		v.push_back("1");
		v.push_back("2");
		v.push_back("3");
		v.push_back("4");
		
		std::cout << v.size() << " " << v.capacity() << std::endl;
		for (std::size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " "; 
		}
		std::cout << std::endl;

		std::vector<std::string>::reverse_iterator r_it = v.rbegin();
		std::cout << *r_it << std::endl;
		std::vector<std::string>::reverse_iterator re_it = v.rend();
		// std::cout << *(--re_it) << std::endl;
		// std::cout << *(--re_it) << std::endl;
		--re_it;
		while (r_it != re_it) {
			std::cout << *re_it;
			--re_it;
		}
		// std::cout << *r_it << " " << *re_it << " DIST: " << std::distance(r_it, re_it)<< std::endl ;

		std::cout << "---------------------------------------------------------------------\n";

		ft::vector<std::string> ft_v;
		ft_v.push_back("0");
		ft_v.push_back("1");
		ft_v.push_back("2");
		ft_v.push_back("3");
		ft_v.push_back("4");
		
		std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
		for (std::size_t i = 0; i < ft_v.size(); ++i) {
			std::cout << ft_v[i] << " "; 
		}
		std::cout << std::endl;

		ft::vector<std::string>::reverse_iterator ft_r_it = ft_v.rbegin();
		// std::cout << *ft_r_it << std::endl;
		ft::vector<std::string>::reverse_iterator ft_re_it = ft_v.rend();
		--ft_re_it;
		while (ft_r_it != ft_re_it) {
			std::cout << *ft_re_it;
			--ft_re_it;
		}
		// std::cout << *ft_r_it << " " << *ft_re_it  << " DIST: " << std::distance(ft_r_it, ft_re_it)<< std::endl ;
	}
	
	return 0;
}