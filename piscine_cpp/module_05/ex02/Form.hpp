/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:34 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:19:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucracy.hpp"

class Bureaucrat;

class Form : public Bureaucracy {
	public:
		Form();
		Form(std::string, std::string, int, int, void (*)(std::string));
		Form(const Form &other);
		virtual ~Form() = 0;

		Form	&operator =(const Form&);

		const std::string	&getName(void) const;
		int					gradeToSign(void) const;
		int					gradeToExec(void) const;
		bool				isSigned(void) const;

		Form		&beSigned(const Bureaucrat&);
		const Form	&execute(const Bureaucrat&) const;


	private:
		const std::string	m_name, m_target;
		const int			m_gradeToSign, m_gradeToExec;
		void				(*m_action)(std::string);
		bool				m_signed;
};

std::ostream	&operator<<(std::ostream &out, Form &f);
