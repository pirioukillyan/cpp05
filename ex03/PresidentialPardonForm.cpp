/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:40:55 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 17:40:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: AForm("presidential pardon", 25, 5), _target(target)
{
	if (_target.empty())
		throw std::invalid_argument("Target must be specified");
}

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("presidential pardon", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: AForm(src), _target(src._target)
{
	if (_target.empty())
		throw std::invalid_argument("Target must be specified");
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		if (rhs._target.empty())
			throw std::invalid_argument("Target must be specified");
		_target = rhs._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
