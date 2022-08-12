/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:54:45 by dwillard          #+#    #+#             */
/*   Updated: 2022/05/30 18:02:42 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include <iosfwd>

namespace ft
{
/*
 * class to pack two objects in one
 * it allows comparing two objects of identical types
*/
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

//	Constructors of class pair

		pair (): first(T1()), second(T2()) {}
		pair (const T1& value1, const T2& value2): first(value1), second(value2) {}
		template<class U1, class U2>
		pair (const pair<U1, U2>& X): first(X.first), second(X.second) {}
		T1 first;
		T2 second;

		pair& operator=(pair const& p) {
			first = p.first;
			second = p.second;
			return *this;
		}
	};

//Operators of class pair



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
			return X.first < Y.first || (!(Y.first < X.first) && X.second < Y.second);
		}
	template <class T1, class T2>
		inline
		bool operator>(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
			return Y < X;
		}
	template <class T1, class T2>
		inline
		bool operator>=(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
			return !(Y > X);
		}
	template <class T1, class T2>
		inline
		bool operator<=(const pair<T1, T2>& X, const pair<T1, T2>& Y) {
			return !(X > Y);
		}

	template <class T1, class T2> inline
//	pair<T1, T2> make_pair(const T1& X, const T2& Y) {
	pair<T1, T2> make_pair(T1 X, T2 Y) {
		return pair<T1, T2>(X, Y);
	}
}
#endif
