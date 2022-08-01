/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeCIterator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:55:20 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:56:52 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TREECITERATOR_H
#define FT_CONTAINERS_TREECITERATOR_H

#include "../iterator/iterator.h"
#include "tree.h"
#include "base.h"

namespace ft
{
	template <class TreeTraits>
	class Tree<TreeTraits>::const_iterator : public ft::iterator<bidirectional_iterator_tag, value_type,
			Dift, Ctptr, const_reference>
	{
	private:
		void Dec()
		{
			if (Isnil(current_))
				current_ = Right(current_);
			else if (!Isnil(Left(current_)))
				current_ = Max(Left(current_));
			else
			{
				Nodeptr P;
				while (!Isnil(P = Parent(current_)) && current_ == Left(P))
					current_ = P;
				if (!Isnil(P))
					current_ = P;
			}
		}
		void Inc()
		{
			if (Isnil(current_))
				;
			else if (!Isnil(Right(current_)))
				current_ = Min(Right(current_));
			else
			{
				Nodeptr P;
				while (!Isnil(P = Parent(current_)) && current_ == Right(P))
					current_ = P;
				current_ = P;
			}
		}
	protected:
		Nodeptr	current_;
	public:
		typedef	ft::iterator<ft::bidirectional_iterator_tag, value_type,
				Dift, Ctptr, const_reference>			Mybase;
		typedef typename Mybase::iterator_category		iterator_category;
//			typedef typename Mybase::value_type				value_type;
		typedef typename Mybase::difference_type			difference_type;
		typedef typename Mybase::pointer				pointer;
		typedef typename Mybase::reference				reference;

		const_iterator() : current_(0) {}
		explicit const_iterator(Nodeptr P) : current_(P) {}
		explicit const_iterator(const typename Tree<TreeTraits>::iterator& X): current_(X.Mynode()) {}

		const_reference   operator*() const
		{
			return Value(current_);
		}
		Ctptr    operator->() const
		{
			return &**this;
		}
		const_iterator&	operator++()
		{
			Inc();
			return *this;
		}
		const_iterator	operator++(int)
		{
			iterator    tmp = *this;
			++*this;
			return tmp;
		}
		const_iterator&	operator--()
		{
			Dec();
			return *this;
		}
		const_iterator	operator--(int)
		{
			iterator	tmp = *this;
			--*this;
			return tmp;
		}
		bool	operator==(const const_iterator& X) const
		{
			return current_ == X.current_;
		}
		bool	operator!=(const const_iterator& X) const
		{
			return !(*this == X);
		}
		Nodeptr	Mynode() const
		{
			return current_;
		}
	};
}

#endif
