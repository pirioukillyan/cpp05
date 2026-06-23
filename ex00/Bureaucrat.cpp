/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:52:42 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 10:52:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name) {
	//grade
}

Bureaucrat::Bureaucrat(void) : _name("Unamed"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name) {
	//grade
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

std::string	Bureaucrat::getName(void) const
{
	return _name;
}

int			Bureaucrat::getGrade(void) const
{
	return _grade;
}

void		Bureaucrat::upGrade(int up)
{
	//grade
}

void		Bureaucrat::downGrade(int down)
{
	//grade
}
