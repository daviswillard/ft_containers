/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_traits.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:54:14 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:54:15 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TRAITS_HPP
#define MAP_TRAITS_HPP

#include "../utility/utility.hpp"
#include <functional>

namespace ft
{
	template <class Key, class T, class Pred, class Ax>
	class	Tmap_traits
	{
	public:
		Pred	comp;

		typedef Key						key_type;
		typedef ft::pair<const Key, T>	value_type;
		typedef Pred					key_compare;
		typedef typename Ax::template
		rebind<value_type>::other	allocator_type;

		Tmap_traits() : comp()
		{
		}

		explicit Tmap_traits(Pred Parg) : comp(Parg)
		{
		}

		class value_compare:
				public std::binary_function<value_type, value_type, bool>
		{
			friend class Tmap_traits<Key, T, Pred, Ax>;

		protected:
			key_compare comp;

		public:
			bool operator()(const value_type &X,
							const value_type &Y) const
			{
				return comp(X.first, Y.first);
			}

			value_compare(key_compare Pr) : comp(Pr)
			{
			}
		};

		const static Key &GetKey(const value_type &V)
		{
			Kfn	ret;
			return ret(V);
		}

		struct Kfn
		{
			const Key& operator()(const value_type& X) const
			{
				return X.first;
			}
		};
	};
}

#endif
