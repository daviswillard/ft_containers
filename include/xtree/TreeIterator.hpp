/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:55:32 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:56:58 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_H
#define TREE_ITERATOR_H

#include "../iterator/iterator.hpp"
#include "tree.hpp"
#include "base.hpp"

namespace ft
{
	template <class TreeTraits>
	class Tree<TreeTraits>::iterator : public ft::iterator<bidirectional_iterator_tag, value_type,
			Dift, Tptr, Reft> {
	private:
		void Dec() {
			if (Isnil(current_))
				current_ = Right(current_);
			else if (!Isnil(Left(current_)))
				current_ = Max(Left(current_));
			else {
				Nodeptr P;
				while (!Isnil(P = Parent(current_)) && current_ == Left(P))
					current_ = P;
				if (!Isnil(P))
					current_ = P;
			}
		}

		void Inc() {
			if (Isnil(current_));
			else if (!Isnil(Right(current_)))
				current_ = Min(Right(current_));
			else {
				Nodeptr P;
				while (!Isnil(P = Parent(current_)) && current_ == Right(P))
					current_ = P;
				current_ = P;
			}
		}

	protected:
		Nodeptr current_;
	public:
		typedef ft::iterator<ft::bidirectional_iterator_tag, value_type,
				Dift, Tptr, Reft> Mybase;
		typedef typename Mybase::iterator_category iterator_category;
//			typedef typename Mybase::value_type				value_type;
		typedef typename Mybase::difference_type difference_type;
		typedef typename Mybase::pointer pointer;
		typedef typename Mybase::reference reference;

		iterator() : current_(0) {}

		explicit iterator(Nodeptr P) : current_(P) {}

		reference operator*() const {
			return Value(current_);
		}

		Tptr operator->() const {
			return &**this;
		}

		iterator operator++() {
			Inc();
			return *this;
		}

		iterator operator++(int) {
			iterator tmp = *this;
			++*this;
			return tmp;
		}

		iterator operator--() {
			Dec();
			return *this;
		}

		iterator operator--(int) {
			iterator tmp = *this;
			--*this;
			return tmp;
		}

		bool operator==(const iterator &X) const {
			return current_ == X.current_;
		}

		bool operator!=(const iterator &X) const {
			return !(*this == X);
		}

		Nodeptr Mynode() const {
			return current_;
		}
	};
}

#endif
