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
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const & name, int grade) :
	_name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(void) :
	_name("Unamed"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const & src) :
	_name(src._name), _grade(src._grade) {}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

std::string const &	Bureaucrat::getName(void) const
{
	return _name;
}

int				Bureaucrat::getGrade(void) const
{
	return _grade;
}

void		Bureaucrat::incrementGrade(int increment)
{
	if (_grade - increment < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade - increment > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade -= increment;
}

void		Bureaucrat::decrementGrade(int decrement)
{
	if (_grade + decrement < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade + decrement > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += decrement;
}

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " 
					<< form.getName()
					<< " because " << e.what()
					<< std::endl;
	}
	
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat const & b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
