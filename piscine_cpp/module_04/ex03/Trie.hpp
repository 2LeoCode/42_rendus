/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trie.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:40:21 by lsuardi           #+#    #+#             */
/*   Updated: 2022/01/25 16:43:11 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <climits>

#include "utils.hpp"

#define NULL_NODE static_cast< node* >(NULL)

template <
	class T
> class Trie {
	public:
		struct node {
			node() : data(NULL) {
				ft::fill(children, children + UCHAR_MAX + 1, NULL_NODE);
			}
			node(const node &other) {
				data = new T(*other.data);
				ft::fill(children, children + UCHAR_MAX + 1, NULL_NODE);
			}
			~node() { }

			node	&operator =(const node &other) {
				delete data;
				data = new T(*other.data);
			}

			bool	has_children(void) const {
				for (int i = 0; i <= UCHAR_MAX; ++i)
					if (children[i])
						return true;
				return false;
			}

			node	*children[UCHAR_MAX + 1];
			T		*data;
		};

		Trie() : m_root(NULL) { }
		Trie(const Trie &other) : m_root(NULL) {
			m_copy(m_root, other.m_root);
		}
		~Trie() { clear(); }

		Trie	&operator =(const Trie &other) {
			clear();
			m_copy(m_root, other.m_root);
		}

		void	clear(void) {
			if (m_root)
				m_clear(m_root), m_root = NULL;
		}

		bool	insert(const char *identifier, T *data) {
			const unsigned char	*utext
				= reinterpret_cast< const unsigned char* >(identifier);
			node	*ptr;

			if (!m_root)
				m_root = new node;
			ptr = m_root;
			while (*utext) {
				if (!ptr->children[*utext])
					ptr->children[*utext] = new node;
				ptr = ptr->children[*utext++];
			}
			if (ptr->data)
				return false;
			ptr->data = data;
			return true;
		}

		bool	erase(const char *identifier) {
			bool	result = false;

			if (!m_root)
				return false;
			m_root = m_erase(
				m_root,
				reinterpret_cast< const unsigned char* >(identifier),
				result
			);
			return result;
		}

		T		*search(const char *identifier) {
			const unsigned char	*utext
				= reinterpret_cast< const unsigned char* >(identifier);
			node	*node = m_root;

			if (!node)
				return NULL;
			while (*utext)
				if (!(node = node->children[*utext++]))
					throw std::out_of_range("Trie::search");
			if (!node->data)
				throw std::out_of_range("Trie::search");
			return node->data;
		}

		void	print(void) { m_print(m_root, NULL, 0); }

	private:
		void	m_copy(node* &dst, const node *src) {
			node	*ptr;

			if (src) {
				dst = new node(*src);
				for (int i = 0; i <= UCHAR_MAX; ++i)
					m_copy(dst->children[i], src->children[i]);
			}
		}

		void	m_clear(node *start) {
			for (int i = 0; i <= UCHAR_MAX; ++i)
				if (start->children[i])
					m_clear(start->children[i]);
			if (start->data)
				delete start->data;
			delete start;
		}

		node	*m_erase(
			node *cur_node, const unsigned char *id, bool &success
		) {
			if (!*id) {
				if (cur_node->data) {
					delete cur_node->data;
					cur_node->data = NULL;
					if (!cur_node->has_children()) {
						success = true;
						delete cur_node;
						cur_node = NULL;
					}
				}
				return cur_node;
			}
			if (
				cur_node->children[*id]
				&& !(
					cur_node->children[*id]
						= m_erase(cur_node->children[*id], id + 1, success)
				) && !cur_node->data && !cur_node->has_children()
			) {
				delete cur_node;
				cur_node = NULL;
			}
			return cur_node;
		}

		void	m_print(node *cur, const unsigned char *prefix, std::size_t len) {
			unsigned char	newPrefix[len + 2];

			ft::copy(prefix, prefix + len, newPrefix);
			newPrefix[len + 1] = 0;
			for (int i = 0; i <= UCHAR_MAX; ++i) {
				if (cur->children[i]) {
					newPrefix[len] = i;
					m_print(cur->children[i], newPrefix, len + 1);
				}
			}
			if (cur->data)
				std::cout << '{' << prefix << '}' << std::endl;
		}

		node	*m_root;
};
