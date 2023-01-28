/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:01:02 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 14:55:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <
	class T
> class List {
	public:
		struct node {
			node() : data(), next(NULL) { }
			node(T &data) : data(data), next(NULL) { }
			node(const node &other) : data(other.data), next(NULL) { }
			~node() { }

			node	&operator =(const node &other) {
				data = other.data;
				return *this;
			}

			T		data;
			node	*next;
		};

		List() : m_head(NULL), m_tail(NULL), m_size(0) { }
		List(const List &other) {
			node	**ptr = &m_head;
			node	**start = ptr;
			for (node *n = other.m_head; n != other.m_tail; n = n->next) {
				*ptr = new node(n);
				ptr = &(*ptr)->next;
			}
			*ptr = new node(other.m_tail);
			m_head = *start;
			m_tail = *ptr;
		}
		~List() { clear(); }

		List	&operator =(const List &other) {
			clear();
			node	**ptr = &m_head;
			node	**start = ptr;
			for (node *n = other.m_head; n != other.m_tail; n = n->next) {
				*ptr = new node(n);
				ptr = &(*ptr)->next;
			}
			*ptr = new node(other.m_tail);
			m_head = *start;
			m_tail = *ptr;
		}

		void	push_back(T data) {
			if (!m_head)
				m_tail = m_head = new node(data);
			else {
				m_tail->next = new node(data);
				m_tail = m_tail->next;
			}
		}
		void	push_front(T data) {
			node	*ptr = new node(data);
			ptr->next = m_head;
			m_head = ptr;
		}

		void	clear(void) {
			node	*ptr = m_head;
			node	*backup;

			while (ptr) {
				backup = ptr->next;
				delete ptr;
				ptr = backup;
			}
			m_head = m_tail = NULL;
		}

		node	*head(void) { return m_head; }
		node	*tail(void) { return m_tail; }

	private:
		node		*m_head, *m_tail;
		std::size_t	m_size;
};
