#ifndef IS_INTEGRAL
# define IS_INTEGRAL

namespace ft
{
	
template<class T, T val>
struct integral_value {
	static const T value = val;
};

struct true_type: integral_value<bool, true> {};
struct false_type: integral_value<bool, false> {};

template<class>
struct is_integral: false_type{};

template<>struct is_integral<bool>: true_type{};
template<>struct is_integral<const bool>: true_type{};

template<>struct is_integral<char>: true_type{};
template<>struct is_integral<const char>: true_type{};
template<>struct is_integral<signed char>: true_type{};
template<>struct is_integral<const signed char>: true_type{};
template<>struct is_integral<unsigned char>: true_type{};
template<>struct is_integral<wchar_t>: true_type{};
template<>struct is_integral<const wchar_t>: true_type{};
template<>struct is_integral<char16_t>: true_type{};
template<>struct is_integral<const char16_t>: true_type{};
template<>struct is_integral<char32_t>: true_type{};
template<>struct is_integral<const char32_t>: true_type{};

template<>struct is_integral<short>: true_type{};
template<>struct is_integral<const short>: true_type{};
template<>struct is_integral<unsigned short>: true_type{};
template<>struct is_integral<const unsigned short>: true_type{};

template<>struct is_integral<int>: true_type{};
template<>struct is_integral<const int>: true_type{};
template<>struct is_integral<unsigned int>: true_type{};
template<>struct is_integral<const unsigned int>: true_type{};

template<>struct is_integral<long>: true_type{};
template<>struct is_integral<const long>: true_type{};
template<>struct is_integral<unsigned long>: true_type{};
template<>struct is_integral<const unsigned long>: true_type{};

template<>struct is_integral<long long>: true_type{};
template<>struct is_integral<const long long>: true_type{};
template<>struct is_integral<unsigned long long>: true_type{};
template<>struct is_integral<const unsigned long long>: true_type{};

template<>struct is_integral<__int128_t>: true_type{};
template<>struct is_integral<const __int128_t>: true_type{};
template<>struct is_integral<__uint128_t>: true_type{};
template<>struct is_integral<const __uint128_t>: true_type{};

} // namespace ft


#endif