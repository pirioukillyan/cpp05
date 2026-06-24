/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:41:21 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 17:41:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (_target.empty())
		throw std::invalid_argument("Target must be specified");
}

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
    : AForm(src), _target(src._target)
{
	if (_target.empty())
		throw std::invalid_argument("Target must be specified");
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
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

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);

	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed\n";
}
