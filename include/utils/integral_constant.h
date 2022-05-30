/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:17:43 by dwillard          #+#    #+#             */
/*   Updated: 2022/05/30 18:01:12 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_H
# define INTEGRAL_CONSTANT_H
/*
 * class to check whether our value is of integral data type or not
*/
namespace ft
{
	template<class T, bool v>
	struct integral_constant {
		static const bool value = v;

	    typedef T					value_type;
		typedef integral_constant	type;
		operator value_type() const throw() {
			return value;
		}
	};

	template <class T>	struct is_integral:						public integral_constant<T, false> {};

	template <>			struct is_integral<bool>:				public integral_constant<bool, true> {};
	template <>			struct is_integral<char>:				public integral_constant<bool, true> {};
	template <>			struct is_integral<signed char>:		public integral_constant<bool, true> {};
	template <>			struct is_integral<unsigned char>:		public integral_constant<bool, true> {};
	template <>			struct is_integral<wchar_t>:			public integral_constant<bool, true> {};
	template <>			struct is_integral<short>:				public integral_constant<bool, true> {};
	template <>			struct is_integral<unsigned short>:		public integral_constant<bool, true> {};
	template <>			struct is_integral<int>:				public integral_constant<bool, true> {};
	template <>			struct is_integral<unsigned int>:		public integral_constant<bool, true> {};
	template <>			struct is_integral<long>:				public integral_constant<bool, true> {};
	template <>			struct is_integral<unsigned long>:		public integral_constant<bool, true> {};
	template <>			struct is_integral<long long>:			public integral_constant<bool, true> {};
	template <>			struct is_integral<unsigned long long>:	public integral_constant<bool, true> {};
}

#endif

/*
*#include <iostream>
*
*class A {};
*
*int	main()
*{
*	std::cout << ft::is_integral<bool>::value << std::endl;
*	std::cout << ft::is_integral<A>::value << std::endl;
*	std::cout << ft::is_integral<float>::value << std::endl;
*	std::cout << ft::is_integral<int>::value << std::endl;
*	return 0;
*}
*/
