/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:38:02 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/01 16:06:53 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <algorithm>
#include <memory>
#include "../utility/utility.hpp"
#include "../xtree/tree.hpp"
#include "set_traits.hpp"

namespace ft
{

	template<class Key, class Pred = std::less<Key>,
			class A = std::allocator<Key> >
	class set : public Tree <ft::Tset_traits<Key, Pred, A> >
	{
	public:
		typedef	set <Key, Pred, A>						Myt;
		typedef Tree <Tset_traits<Key, Pred, A> >		Mybase;
		typedef Key										key_type;
		typedef Pred									key_compare;
		typedef typename Mybase::value_type				value_type;
		typedef typename Mybase::value_compare			value_compare;
		typedef typename Mybase::allocator_type			allocator_type;
		typedef typename Mybase::size_type				size_type;
		typedef typename Mybase::difference_type		difference_type;
		typedef typename Mybase::pointer				pointer;
		typedef typename Mybase::const_pointer			const_pointer;
		typedef typename Mybase::reference				reference;
		typedef typename Mybase::const_reference		const_reference;
		typedef typename Mybase::iterator				iterator;
		typedef typename Mybase::const_iterator			const_iterator;
		typedef typename Mybase::reverse_iterator		reverse_iterator;
		typedef typename Mybase::const_reverse_iterator	const_reverse_iterator;


		set() : Mybase(key_compare(), allocator_type()) {}

		explicit set(const key_compare& pred) : Mybase(pred, allocator_type()) {}

		set(const key_compare& pred, const A& Al) : Mybase(pred, Al) {}

		template <class It>
			set(It F, It L) : Mybase(key_compare(), allocator_type())
		{
			for (; F != L; ++F)
				this->insert(*F);
		}

		template <class It>
			set(It first, It last, const key_compare& pred) : Mybase(pred, allocator_type())
		{
			for (; first != last; ++first)
				this->insert(*first);
		}

		template <class It>
			set(It F, It L, const key_compare& pred, const allocator_type& al)
			: Mybase(pred, al)
		{
			for (; F != L; ++F)
				this->insert(*F);
		}
	};
}

#endif
