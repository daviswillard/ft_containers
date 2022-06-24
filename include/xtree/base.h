#pragma once

#include "TreeVal.h"
#include "../iterator/iterator.h"

namespace ft
{
	template <class TreeTraits>
	class Tree : public TreeVal<TreeTraits>
	{
	protected:
		typedef typename TreeNode<TreeTraits>::Genptr Genptr;
		typedef typename TreeNode<TreeTraits>::Node		Node;
		enum	Redbl {Red, Black};
		typedef typename allocator_type::template
				rebind<Node>::other::pointer				Nodeptr;
		typedef typename allocator_type::template
				rebind<Nodeptr>::other::reference			Noderef;
		typedef typename allocator_type::template
				rebind<key_type>::other::const_reference	Keyref;
		typedef typename allocator_type::template
				rebind<char>::other::reference				Charref;
		typedef typename allocator_type::template
				rebind<value_type>::other::reference		Vref;

		static Charref	Color(Nodeptr P)
		{
			return ((Charref)(*P).Color);
		}
		static Charref	Isnil(Nodeptr P)
		{
			return ((Charref)(*P).Isnil);
		}
		static Keyref Key(Nodeptr P)
		{
			return (TreeTraits::GetKey(Value(P)));
		}
		static Noderef	Left(Nodeptr P)
		{
			return ((Noderef)(*P).Left);
		}
		static Noderef	Right(Nodeptr P)
		{
			return ((Noderef)(*P).Right);
		}
		static Noderef	Parent(Nodeptr P)
		{
			return ((Noderef)(*P).Parent);
		}
		static Vref	Value(Nodeptr P)
		{
			return ((Vref)(*P).Value);
		}

	public:
		typedef Tree<TreeTraits>	Myt;
		typedef TreeVal<TreeTraits>	Mybase;
		typedef typename TreeTraits::key_type		key_type;
		typedef typename TreeTraits::key_compare	key_compare;
		typedef typename TreeTraits::value_compare	value_compare;
		typedef typename TreeTraits::value_type		value_type;
		typedef typename TreeTraits::allocator_type	allocator_type;


		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	Dift;
		typedef typename allocator_type::template
				rebind<value_type>::other::pointer			Tptr;
		typedef typename allocator_type::template
				rebind<value_type>::other::const_pointer	Ctptr;
		typedef typename allocator_type::template
				rebind<value_type>::other::reference		Reft;

		typedef typename allocator_type::template
			rebind<value_type>::other::const_reference		const_reference;

		typedef	Dift										difference_type;
		typedef Tptr										pointer;
		typedef Ctptr										const_pointer;
		typedef Reft										reference;

	};
}
