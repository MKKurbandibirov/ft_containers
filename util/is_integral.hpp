#ifndef IS_INTEGRAL
# define IS_INTEGRAL

namespace ft
{
	
template<class T, T val>
struct integral_value {
	static const T value = val;
};

struct true_value: integral_value<bool, true> {};
struct false_value: integral_value<bool, false> {};

template<class>
struct is_integral: false_value{};

template<>struct is_integral<bool>: true_value{};
template<>struct is_integral<const bool>: true_value{};

template<>struct is_integral<char>: true_value{};
template<>struct is_integral<const char>: true_value{};
template<>struct is_integral<signed char>: true_value{};
template<>struct is_integral<const signed char>: true_value{};
template<>struct is_integral<unsigned char>: true_value{};
template<>struct is_integral<wchar_t>: true_value{};
template<>struct is_integral<const wchar_t>: true_value{};
template<>struct is_integral<char16_t>: true_value{};
template<>struct is_integral<const char16_t>: true_value{};
template<>struct is_integral<char32_t>: true_value{};
template<>struct is_integral<const char32_t>: true_value{};

template<>struct is_integral<short>: true_value{};
template<>struct is_integral<const short>: true_value{};
template<>struct is_integral<unsigned short>: true_value{};
template<>struct is_integral<const unsigned short>: true_value{};

template<>struct is_integral<int>: true_value{};
template<>struct is_integral<const int>: true_value{};
template<>struct is_integral<unsigned int>: true_value{};
template<>struct is_integral<const unsigned int>: true_value{};

template<>struct is_integral<long>: true_value{};
template<>struct is_integral<const long>: true_value{};
template<>struct is_integral<unsigned long>: true_value{};
template<>struct is_integral<const unsigned long>: true_value{};

template<>struct is_integral<long long>: true_value{};
template<>struct is_integral<const long long>: true_value{};
template<>struct is_integral<unsigned long long>: true_value{};
template<>struct is_integral<const unsigned long long>: true_value{};

template<>struct is_integral<__int128_t>: true_value{};
template<>struct is_integral<const __int128_t>: true_value{};
template<>struct is_integral<__uint128_t>: true_value{};
template<>struct is_integral<const __uint128_t>: true_value{};

} // namespace ft


#endif