/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:13:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 17:54:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define ABSF(x) ((x) < 0 ? -1 * (x) : (x))

bool	bsp(const Point a, const Point b, const Point c, const Point p) {
	if (a == p || b == p || c == p) return true;
	const Point	ap(p.x() - a.x(), p.y() - a.y()),
				bp(p.x() - b.x(), p.y() - b.y()),
				ab(b.x() - a.x(), b.y() - a.y()),
				ac(c.x() - a.x(), c.y() - a.y()),
				bc(c.x() - b.x(), c.y() - b.y());

	bool	p_ab(ab.x() * ap.y() - ab.y() * ap.x() > 0),
			p_ac(ac.x() * ap.y() - ac.y() * ap.x() > 0),
			p_bc(bc.x() * bp.y() - bc.y() * bp.x() > 0);
	return p_ab != p_ac && p_bc == p_ab;
}
