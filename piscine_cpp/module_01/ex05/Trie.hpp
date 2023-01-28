/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trie.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:12:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 18:02:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

#include <cstddef>
#include <cstring>
#include <climits>

#include "utils.hpp"

template <
	class T
> class Trie {
	public:
		Trie() : m_root(NULL) { }
		~Trie() { clear(); }

		struct node {
			node() : terminal(false), data() {
				ft::fill(
					children,
					children + UCHAR_MAX,
					reinterpret_cast< node* >(NULL)
				);
			}

			bool	has_children(void) {
				for (int i = 0; i < UCHAR_MAX; ++i)
					if (children[i])
						return true;
				return false;
			}

			node	*children[UCHAR_MAX];
			bool	terminal;
			T		data;
		};

		bool	insert(const char *ref, const T &data) {
			const unsigned char	*text
				= reinterpret_cast< const unsigned char* >(ref);
			node				**ptr;
		
			if (!m_root)
				m_root = new node;
			ptr = &m_root;
			while (*text)
				if (!*(ptr = &(*ptr)->children[*text++]))
					*ptr = new node;
			if ((*ptr)->terminal)
				return false;
			(*ptr)->data = data;
			return (*ptr)->terminal = true;
		}

		T		&search(const char *ref) {
			const unsigned char	*text
				= reinterpret_cast< const unsigned char* >(ref);
			node				*ptr = m_root;

			if (!ptr)
				throw std::out_of_range("Trie::search");
			while (*text)
				if (!(ptr = ptr->children[*text++]))
					throw std::out_of_range("Trie::search");
			if (!ptr->terminal)
				throw std::out_of_range("Trie::search");
			return ptr->data;
		}

		bool	remove(const char *ref) {
			const unsigned char	*text
				= reinterpret_cast< const unsigned char* >(ref);
			bool				result = false;

			if (m_root)
				m_root = m_remove_rec(m_root, text, &result);
			return result;
		}

		void	clear(void) {
			if (m_root)
				m_clear_rec(m_root);
		}

	private:
		node	*m_remove_rec(
			node *cur_node, const unsigned char *ref, bool *result
		) {
			node	**ptr;

			if (!*ref) {
				if (cur_node->terminal) {
					cur_node->terminal = false;
					*result = true;
					if (!cur_node->has_children()) {
						delete cur_node;
						cur_node = NULL;
					}
				}
				return cur_node;
			}
			ptr = &cur_node->children[*ref];
			*ptr = m_remove_rec(*ptr, ref + 1, result);
			if (*result && !cur_node->terminal && !cur_node->has_children()) {
				delete cur_node;
				cur_node = NULL;
			}
			return cur_node;
		}

		void	m_clear_rec(node *node) {
			for (int i = 0; i < UCHAR_MAX; ++i) {
				if (node->children[i])
					m_clear_rec(node->children[i]);
			}
			delete node;
		}

		node	*m_root;
};
