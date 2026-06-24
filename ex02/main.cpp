/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:18:21 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 11:18:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

#define ASSERT_TEST(passed, message) \
	if (passed) { std::cout << GREEN << "TEST PASSED" << NC << std::endl; } \
	else { std::cout << RED << "TEST FAILED: " << message << NC << std::endl; }

#define GREY		"\033[0;30m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"
#define BLUE		"\033[0;34m"
#define MAGENTA		"\033[0;35m"
#define CYAN		"\033[0;36m"
#define NC			"\033[0m"

int	main(void)
{
	/************************************/
	std::cout << std::endl;
	{
		std::cout << MAGENTA << "TEST SHRUBBERY CREATION FORM" << NC << std::endl;

		try
		{
			Bureaucrat boss("Boss", 1);
			ShrubberyCreationForm form("garden");

			std::cout << form << std::endl;

			boss.signForm(form);
			boss.executeForm(form);

			ASSERT_TEST(form.getIsSigned() == true,
				"ShrubberyCreationForm signed");
		}
		catch (std::exception &e)
		{
			ASSERT_TEST(false, e.what());
		}
	}

	return 0;
}
