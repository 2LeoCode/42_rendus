/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:14:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:13:04 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Trie.hpp"

class Karen {
	public:
	
	typedef void	(Karen::*ComplainFun)(void);
	
	Karen();
	~Karen();
	void	complain(std::string level);

	private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	bool	m_init_trie(void);

	static std::string					m_debugMsg, m_infoMsg,
										m_warningMsg, m_errorMsg;
	static Trie< Karen::ComplainFun >	m_data;
};
