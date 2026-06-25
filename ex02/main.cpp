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
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << GREEN << "[TEST PASSED] " << NC << message << std::endl; } \
	else { std::cout << RED << "[TEST FAILED] " << NC << message << std::endl; }

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
	std::srand(std::time(NULL));

    /**************************************************/
    std::cout << "\n===== TEST 1 - SHRUBBERY =====\n";

	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("home");

		boss.signForm(form);
		boss.executeForm(form);

		std::ifstream file("home_shrubbery");

		ASSERT_TEST(form.getIsSigned() == true,
			"Shrubbery should be signed");

		ASSERT_TEST(file.good(),
			"Shrubbery file should be created");
	}

	/**************************************************/

	std::cout << "\n===== TEST 2 - NOT SIGNED EXECUTION =====\n";

	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("error_test");

		boss.executeForm(form);

		ASSERT_TEST(form.getIsSigned() == false,
			"Form should still be unsigned");

		std::ifstream file("error_test_shrubbery");

		ASSERT_TEST(file.good() == false,
			"File should NOT be created");
	}

	/**************************************************/

	std::cout << "\n===== TEST 3 - LOW GRADE SIGN =====\n";

	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm form("garden");

		intern.signForm(form);

		ASSERT_TEST(form.getIsSigned() == false,
			"Low grade bureaucrat should NOT sign form");
	}

	/**************************************************/

	std::cout << "\n===== TEST 4 - ROBOTOMY =====\n";

	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm form("Bender");

		boss.signForm(form);
		boss.executeForm(form);

		ASSERT_TEST(form.getIsSigned() == true,
			"Robotomy should be signed (execution random)");
	}

	/**************************************************/

	std::cout << "\n===== TEST 5 - PRESIDENTIAL PARDON =====\n";

	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form("Arthur");

		boss.signForm(form);
		boss.executeForm(form);

		ASSERT_TEST(form.getIsSigned() == true,
			"Pardon form should be signed");
	}

	/**************************************************/

	std::cout << "\n===== TEST 6 - LOW GRADE EXECUTION =====\n";

	{
		Bureaucrat low("Low", 150);
		ShrubberyCreationForm form("fail_test");

		low.signForm(form);
		low.executeForm(form);

		ASSERT_TEST(form.getIsSigned() == false,
			"Low grade bureaucrat should not sign form");
	}

	/**************************************************/

	std::cout << "\n===== TEST 7 - POLYMORPHISM =====\n";

	{
		Bureaucrat boss("Boss", 1);

		AForm* f1 = new ShrubberyCreationForm("A");
		AForm* f2 = new RobotomyRequestForm("B");
		AForm* f3 = new PresidentialPardonForm("C");

		boss.signForm(*f1);
		boss.signForm(*f2);
		boss.signForm(*f3);

		boss.executeForm(*f1);
		boss.executeForm(*f2);
		boss.executeForm(*f3);

		ASSERT_TEST(f1->getIsSigned() == true &&
		            f2->getIsSigned() == true &&
		            f3->getIsSigned() == true,
			"All forms should be signed");

		delete f1;
		delete f2;
		delete f3;
	}

	return 0;
}
