/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:32:57 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/21 20:03:23 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <class InIt1, class InIt2>
    inline bool lexicographical_compare(InIt1 first, InIt1 last,
                                        InIt2 _first, InIt2 _last)
    {
        for (; _first != _last; ++first, ++_first)
        {
            if (*first < *_first)
                return true;
            else if (*_first < *first)
                return false;
        }
        return first == last && _first != _last;
    }

    template <class InIt1, class InIt2, class Compare>
    inline bool lexicographical_compare(InIt1 first, InIt1 last,
                                        InIt2 _first, InIt2 _last, Compare p)
    {
        for (; _first != _last; ++first, ++_first)
        {
            if (p(*first, *_first))
                return true;
            if (p(*_first, *first))
                return false;
        }
        return first == last && _first != _last;
    }
}
