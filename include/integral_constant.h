/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:17:43 by dwillard          #+#    #+#             */
/*   Updated: 2022/05/29 17:51:26 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_H
# define INTEGRAL_CONSTANT_H

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

	template <class T>
	struct is_integral:		public integral_constant<T, false> {};
}

#endif
