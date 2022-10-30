#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>
#include <sstream>


#include "enable_if.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "red_black_tree/rb_tree.hpp"



class govno
{
private:
	/* data */
public:
	govno(/* args */);
	~govno();
};

govno::govno(/* args */)
{}

govno::~govno(){}

std::ostream& operator<<(std::ostream& out, govno& g) {
	(void)g;
	out << "Govnishe!";
	return out;
}

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

	// {
	// 	std::vector<int> v1(4, 4);
	// 	std::vector<int> v2(4, 3);
	// 	v1.pop_back();
	// 	v1.pop_back();

	// 	// std::cout << std::boolalpha << std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
	// 	std::cout << std::boolalpha << bool(v1 == v2) << std::endl;


	// 	std::cout << "---------------------------------------------------------------------\n";

	// 	ft::vector<int> ft_v1(4, 4);
	// 	ft::vector<int> ft_v2(4, 3);
	// 	ft_v1.pop_back();
	// 	ft_v1.pop_back();

	// 	// std::cout << std::boolalpha << bool(ft_v1 == ft_v1) << std::endl;
	// 	// std::cout << std::boolalpha << ft::lexicographical_compare(ft_v1.begin(), ft_v1.end(), ft_v2.begin(), ft_v2.end()) << std::endl;
	// 	std::cout << std::boolalpha << bool(ft_v1 == ft_v2) << std::endl;
	// }

	// {
	// 	ft::stack<int> s;

	// 	s.push(23);
	// 	s.push(24);
	// 	s.push(25);
	// 	s.push(26);

	// 	std::cout << s.size() << std::endl;

	// 	int tmp = 0;
	// 	try {
	// 		tmp = s.top();
	// 	} catch(...) {
	// 		std::cout <<"govno" << std::endl;
	// 	}

	// 	std::cout << tmp << std::endl;
	// }

	{
		ft::rb_tree<int> t(22);

		t.insert_node(12);
		t.insert_node(11);
		t.insert_node(9);
		t.insert_node(4);
		t.insert_node(1);

		


	}

	return 0;
}