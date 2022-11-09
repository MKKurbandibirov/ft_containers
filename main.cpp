#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <type_traits>

#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "red_black_tree/rb_tree.hpp"
#include "util/is_integral.hpp"
#include "map/map.hpp"



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



class A {};
 
enum E : int {};

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
		std::cout << ft_v[2] << std::endl ;
	}

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

	// {
	// 	ft::rb_tree<int> t;

	// 	t.insert_node(13);
	// 	t.insert_node(12);
	// 	t.insert_node(11);
	// 	t.insert_node(10);
	// 	t.insert_node(9);
	// 	t.insert_node(8);
	// 	t.insert_node(7);
		

	// 	t.delete_node(t.find_node(10));

	// 	ft::Node<int>* r = t.get_root();

	// 	std::cout << r->value << std::endl;
	// 	std::cout << r->right->value << std::endl;
	// 	std::cout << r->left->value << std::endl;
	// 	std::cout << r->left->left->value << std::endl;
	
		
	// }

	// {
	// 	 std::cout << std::boolalpha;
 
	// 	std::cout << ft::is_integral<A>::value << std::endl;
	// 	std::cout << ft::is_integral<E>::value << std::endl;
	// 	std::cout << ft::is_integral<float>::value << std::endl;
	// 	std::cout << ft::is_integral<int>::value << std::endl;
	// 	std::cout << ft::is_integral<const int>::value << std::endl;
	// 	std::cout << ft::is_integral<bool>::value << std::endl;
	// 	std::cout << ft::is_integral<const bool>::value << std::endl;
	// }

	// {
	// 	ft::rb_tree<int> t;

	// 	t.insert_node(13);
	// 	t.insert_node(12);
	// 	t.insert_node(11);
	// 	t.insert_node(10);
	// 	t.insert_node(9);
	// 	t.insert_node(8);
	// 	t.insert_node(7);
		
	// 	t.delete_node(t.find_node(10));

	// 	ft::rb_tree<int>::RBT_iterator it1(t.minimum(t.root), t.root, t.header);
	
	// 	for (int i = 0; i < 6; ++i) {
	// 		std::cout << *it1 << std::endl;
	// 		++it1;
	// 	}

	// 	ft::rb_tree<int>::RBT_iterator it2(t.maximum(t.root), t.root, t.header);
	
	// 	for (int i = 0; i < 6; ++i) {
	// 		std::cout << *it2 << std::endl;
	// 		--it2;
	// 	}
	// }

	// {
	// 	ft::vector<int> ft_v(5, 5);
	// 	ft::vector<int> ft_v1(ft_v.begin(), ft_v.end());
		
	// 	std::cout << ft_v1[0] << std::endl;

	// 	std::vector<int> v(2, 2);
	// 	ft::vector<int> ft_v2(v.begin(), v.end());
	// 	ft::vector<int> as;
	// 	as.assign(ft_v1.begin(), ft_v1.end());
	// 	as.insert(as.begin(), ft_v2.begin(), ft_v2.end());
		
	// 	std::cout << as[3] << std::endl;
	// }

	// {
	// 	ft::map<int, std::string> m;
	// 	ft::pair<int, std::string> elem2(2, "Simon");
	// 	m.insert(elem2);
	// 	ft::pair<int, std::string> elem1(1, "John");
	// 	m.insert(elem1);

	// 	// ft::map<int, std::string> m2(m);

	// 	// ft::map<int, std::string> m3 = m2;

	// 	ft::map<int, std::string> m7;
	// 	ft::pair<int, std::string> elem4(2, "Alex");
	// 	m7.insert(elem4);
	// 	ft::pair<int, std::string> elem5(1, "Steven");
	// 	m7.insert(elem5);
	// 	ft::pair<int, std::string> elem6(3, "Frank");
	// 	m7.insert(elem6);

	// 	// ft::map<int, std::string> m6;

	// 	// std::cout << std::boolalpha << m.empty() << std::endl;
	// 	// std::cout << m.size() << std::endl;
	// 	// std::cout << m.max_size() << std::endl;

	// 	// m6.swap(m7);
	// 	// m3.erase(m3.begin(), m3.end());
	// 	// m3.erase(m3.begin());
	// 	// m3.erase(m3.begin());


	// 	// std::cout << std::boolalpha << m7.empty() << std::endl;
	// 	// std::cout << m7.size() << std::endl;
	// 	// std::cout << m7.max_size() << std::endl;

	// 	m.swap(m7);

	// 	std::cout << std::boolalpha << m.empty() << std::endl;
	// 	std::cout << m.size() << std::endl;
	// 	std::cout << m.max_size() << std::endl;

	// 	std::cout << std::boolalpha << m7.empty() << std::endl;
	// 	std::cout << m7.size() << std::endl;
	// 	std::cout << m7.max_size() << std::endl;

	// 	// ft::map<int, std::string>::iterator it_b = m3.begin();
	// 	// ft::map<int, std::string>::iterator it_e = m3.end();
	// 	// while (it_b != it_e) {
	// 	// 	std::cout << (*it_b).first << std::endl;
	// 	// 	++it_b;
	// 	// }
	// 	// std::cout << (*--m.end()).first << std::endl;

	// 	// m.erase()

	// 	// std::map<int, std::string> mm;
	// 	// mm.insert(std::make_pair<int, std::string>(11, "ahaha"));
	// 	// mm.insert(std::make_pair<int, std::string>(12, "hahah"));
	// 	// ft::map<int, std::string> m5(mm.begin(), mm.end());
	// 	// ft::map<int, std::string>::iterator it_b = m5.begin();
	// 	// ft::map<int, std::string>::iterator it_e = m5.end();
	// 	// while (it_b != it_e) {
	// 	// 	std::cout << (*it_b).first << std::endl;
	// 	// 	++it_b;
	// 	// }

	// 	// std::cout << m[3].second << std::endl;
	// 	// std::cout << m.erase(3) << m.count(3) << m.count(2) <<  std::endl;

	// 	ft::map<int, std::string>::key_compare kk = m.key_comp();
	// 	std::cout << std::boolalpha << kk(4, 2) << std::endl;

	// 	ft::map<int, std::string>::value_compare kv = m.value_comp();
	// 	std::cout << std::boolalpha << kv(ft::make_pair<int, std::string>(6, "John"), ft::make_pair<int, std::string>(4, "John")) << std::endl;
	
	// 	std::cout << "---------------------------------------------------\n";

	// 	ft::map<char, int> map;
	// 	map['a'] = 20;
	// 	map['b'] = 40;
	// 	map['c'] = 60;
	// 	map['d'] = 80;
	// 	map['e'] = 100;

	// 	ft::map<char, int>::iterator lb = map.lower_bound('b');
	// 	std::cout << (*lb).first << " - " << (*lb).second << std::endl;

	// 	ft::map<char, int>::iterator ub = map.upper_bound('d');
	// 	std::cout << (*ub).first << " - " << (*ub).second << std::endl;

	// 	// map.erase(lb, ub);
	// 	// for (ft::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it)
    // 	// 	std::cout << (*it).first << " => " << (*it).second << '\n';

	// 	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> p = map.equal_range('c');
	// 	std::cout << (*p.first).first << " - " << (*p.second).second << std::endl;
	
	// 	// std::cout << "---------------------------------------------------\n";

	// 	// std::map<char, int> m11;
	// 	// std::map<char, int> m22;

	// 	// m11['a'] = 10;
	// 	// m11['b'] = 20;
	// 	// m11['c'] = 30;
	// 	// m11['d'] = 40;


	// 	// m22['a'] = 110;
	// 	// m22['b'] = 120;
	// 	// m22['c'] = 130;
	// 	// m22['d'] = 140;

	// 	// m11 = m22;

	// 	// m11.erase('b');
	// 	// std::cout << m22['b'] << std::endl;
	// }

	return 0;
}

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "map/map.hpp"
// 	#include "stack/stack.hpp"
// 	#include "vector/vector.hpp"
// 	#include "util/pair.hpp"
// 	#include "util/distance.hpp"
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++){
// 		// std::cout << "Ha" << std::endl;
// 		iterable_stack.push(letter);
// 	}
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); ++it)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }