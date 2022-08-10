/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:58:14 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:53:45 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
#define LESS_HPP

#include "binary_function.hpp"

namespace ft
{
	template<class T>
		struct less : public binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y) const
		{
			return x < y;
		};
	};
}

#endif
