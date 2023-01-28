/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:00:28 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 20:41:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SPAN(a, b) ((a) < (b) ? (b) - (a) : (a) - (b))

Span::Span(unsigned N) : m_size(0), m_cap(N), m_data(new int[N]) { }

Span::Span(const Span &other)
:	m_size(other.m_size),
	m_cap(other.m_cap),
	m_data(new int[m_cap])
{ std::copy(other.m_data, other.m_data + m_size, m_data); }

Span::~Span() { delete[] m_data; }

Span	&Span::operator =(const Span &other) {
	delete[] m_data;
	m_data = new int[m_cap = other.m_cap];
	std::copy(other.m_data, other.m_data + (m_size = other.m_size), m_data);
	return *this;
}

void Span::addNumber(int n) {
	if (m_size == m_cap) throw ESpanFull();
	m_data[m_size++] = n;
}

unsigned Span::shortestSpan(void) const {
	if (m_size < 2) throw ENoSpan();
	unsigned current_span, shortest_span = ~0;

	for (unsigned i = 0; i < m_size; ++i)
		for (unsigned j = 0; j < m_size; ++j)
			if (i != j) {
				current_span = SPAN(m_data[i], m_data[j]);
				if (current_span < shortest_span)
					shortest_span = current_span;
			}
	return shortest_span;
}

unsigned Span::longestSpan(void) const {
	if (m_size < 2) throw ENoSpan();
	unsigned current_span, longest_span = 0;

	for (unsigned i = 0; i < m_size; ++i)
		for (unsigned j = 0; j < m_size; ++j)
			if (i != j) {
				current_span = SPAN(m_data[i], m_data[j]);
				if (current_span > longest_span)
					longest_span = current_span;
			}
	return longest_span;
}

unsigned	Span::size(void) const { return m_size; }
const int	*Span::begin(void) const { return m_data; }
const int	*Span::end(void) const { return m_data + m_size; }

const char *Span::ENoSpan::what() const throw ()
{ return "Not enough numbers"; }
const char *Span::ESpanFull::what() const throw () { return "Array is full"; }

std::ostream &operator <<(std::ostream &out, const Span &sp) {
	if (sp.size() > 20) {
		const int	*ptr = sp.begin();

		for (int i = 0; i < 3; ++i)
			out << '[' << ptr[i] << ']';
		out << "[...]";
		for (unsigned i = sp.size() - 4; i < sp.size(); ++i)
			out << '[' << ptr[i] << ']';
	} else for (const int *ptr = sp.begin(); ptr != sp.end(); ++ptr)
		out << '[' << *ptr << ']';
	return out;
}
