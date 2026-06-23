/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:14:22 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 14:14:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(void) : _name("unamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(Form const & src) : _name(src._name), _isSigned(src._isSigned),
		_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form&	Form::operator=(Form const & rhs) {
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return *this;
}

Form::~Form(void) {}

std::string const &	Form::getName(void) const
{
	return _name;
}

int const &	Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int const &	Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

bool	Form::getIsSigned(void) const
{
	return _isSigned;
}

void	Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &	operator<<(std::ostream& out, Form const & f)
{
	out << f.getName() << ", grade to sign " << f.getGradeToSign()
		<< ", grade to execute " << f.getGradeToExecute()
		<< ", is ";
	if (!f.getIsSigned())
		out << "NOT ";
	out << "signed." << std::endl;
	return out;
}
