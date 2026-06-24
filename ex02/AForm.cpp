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

#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(void) : _name("unamed Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(AForm const & src) : _name(src._name), _isSigned(src._isSigned),
		_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm&	AForm::operator=(AForm const & rhs) {
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return *this;
}

AForm::~AForm(void) {}

std::string const &	AForm::getName(void) const
{
	return _name;
}

int const &	AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int const &	AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

bool	AForm::getIsSigned(void) const
{
	return _isSigned;
}

void	AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::checkExecution(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

std::ostream &	operator<<(std::ostream& out, AForm const & f)
{
	out << f.getName() << ", grade to sign " << f.getGradeToSign()
		<< ", grade to execute " << f.getGradeToExecute() << ", is ";
	if (!f.getIsSigned())
		out << "NOT ";
	out << "signed." << std::endl;
	return out;
}
