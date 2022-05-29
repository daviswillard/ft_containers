/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:54:45 by dwillard          #+#    #+#             */
/*   Updated: 2022/05/29 20:21:06 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

namespace ft
{
	template <class T1, class T2>
		struct pair
		{
			typedef T1 first_type;
			typedef T2 second_type;

			pair (): first(T1()), second(T2()) {}
			pair (const T1& value1, const T2& value2): first(value1), second(value2) {}
			template<class U1, class U2>
				pair (const pair<U1, U2>& X): first(X.first), second(X.second) {}
			T1 first;
			T2 second;
		};

		template <class T1, class T2>
			inline
			bool operator==(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
				return X.first == Y.first && X.second == Y.second;
			}
		template <class T1, class T2>
			inline
			bool operator!=(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
				return !(X == Y);
			}
		template <class T1, class T2>
			inline
			bool operator<(const pair<T1, T2>& X, const pair<T1, T2>& Y) {

			}
}

#endif
