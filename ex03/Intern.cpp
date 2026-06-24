/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:34:09 by marvin            #+#    #+#             */
/*   Updated: 2026/06/24 15:34:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::Intern(Intern const & src) {
	*this = src;
}

Intern &	Intern::operator=(Intern const & rhs) {
	if (this != &rhs)
	{}
	return *this;
}

Intern::~Intern(void) {}

static AForm*	creatShubbery(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	creatRobotomy(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	creatPardon(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string const & formName, std::string const & target) const
{
	if (target.empty())
        throw std::invalid_argument("Target cannot be empty.");
}
