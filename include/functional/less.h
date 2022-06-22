/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:58:14 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/22 17:04:13 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "binary_function.h"

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
