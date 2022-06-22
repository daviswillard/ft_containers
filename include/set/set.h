/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:38:02 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/22 18:44:00 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterator/iterator.h"
#include "../functional/less.h"
#include <algorithm>
#include <memory>
#include "../iterator/reverse_iterator.h"
#include "../utils/pair.h"

namespace ft
{
	template<class Key, class Pred = std::less<Key>,
			class A = std::allocator<Key> >
	class set
	{
		typedef Key									key_type;
		typedef Pred								key_compare;
		typedef Key									value_type;
		typedef Pred								value_compare;
		typedef A									allocator_type;
		typedef typename A::pointer					pointer;
		typedef typename A::const_pointer			const_pointer;
		typedef typename A::reference				reference;
		typedef typename A::const_reference			const_reference;
//		typedef T0									iterator;
//		typedef T1									const_iterator;
//		typedef T2									size_type;
//		typedef T3									difference_type;
//		typedef reverse_iterator<iterator>			reverse_iterator;
//		typedef reverse_iterator<const_iterator>	const_reverse_iterator;


		set();
		explicit set(const Pred& comp);
		set(const Pred& comp, const A& al);
		set(const set& x);
		template <class InIt>
			set(InIt first, InIt last);
		template <class InIt>
			set(InIt first, InIt last, const Pred& comp);
		template <class InIt>
			set(InIt first, InIt last, const Pred& comp, const A& al);


//		const_iterator			begin() const;
//		const_iterator			end() const;
//		const_reverse_iterator	rbegin() const;
//		const_reverse_iterator	rend() const;


//		size_type				size() const;
//		size_type				max_size() const;
		bool					empty() const;
		A						get_allocator() const;


//		pair<iterator, bool>	insert(const value_type& x);
//		iterator				insert(iterator it, const value_type& x);
		template <class InIt>
		void					insert(InIt first, InIt last);


//		iterator	erase(iterator it);
//		iterator	erase(iterator first, iterator last);
//		size_type	erase(const Key& key);

		void			clear();
		void			swap(set& x);
		key_compare		key_comp() const;
		value_compare	value_comp() const;
//		const_iterator	find(const Keys& key) const;
//		size_type		count(const Key& key) const;
//		const_iterator	lower_bound(const Key& key) const;
//		const_iterator	upper_bound(const Key& key) const;
//		pair <const_iterator, const_iterator>
//			equal_range(const Key& key) const;
	};
}
