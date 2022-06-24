#pragma once

#include "Node.h"

namespace ft
{
	template <class TreeTraits>
	class TreePtr : public TreeNode<TreeTraits>
	{
	protected:
		typedef typename TreeNode<TreeTraits>::Node	Node;
		typedef typename TreeTraits::allocator_type	allocator_type;
		typedef typename TreeTraits::key_compare	key_compare;
		typedef typename allocator_type::template
				rebind<Node>::other::pointer		Nodeptr;
		TreePtr(const key_compare& Parg, allocator_type Al):
				TreeNode<TreeTraits>(Parg, Al), Alptr(Al)
		{
		}
		typename allocator_type::template
				rebind<Nodeptr>::other	Alptr;
	};
}
