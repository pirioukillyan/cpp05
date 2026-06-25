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
#include "Intern.hpp"
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
	std::cout << "TEST 1 - CREATE SHRUBBERY" << std::endl;

	{
		Intern intern;

		AForm* form = intern.makeForm(
			"shrubbery creation",
			"garden"
		);

		ASSERT_TEST(
			form != NULL,
			"Intern should create ShrubberyCreationForm"
		);

		ASSERT_TEST(
			dynamic_cast<ShrubberyCreationForm*>(form) != NULL,
			"Returned type should be ShrubberyCreationForm"
		);

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 2 - CREATE ROBOTOMY" << std::endl;

	{
		Intern intern;

		AForm* form = intern.makeForm(
			"robotomy request",
			"Bender"
		);

		ASSERT_TEST(
			form != NULL,
			"Intern should create RobotomyRequestForm"
		);

		ASSERT_TEST(
			dynamic_cast<RobotomyRequestForm*>(form) != NULL,
			"Returned type should be RobotomyRequestForm"
		);

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 3 - CREATE PRESIDENTIAL PARDON" << std::endl;

	{
		Intern intern;

		AForm* form = intern.makeForm(
			"presidential pardon",
			"Arthur Dent"
		);

		ASSERT_TEST(
			form != NULL,
			"Intern should create PresidentialPardonForm"
		);

		ASSERT_TEST(
			dynamic_cast<PresidentialPardonForm*>(form) != NULL,
			"Returned type should be PresidentialPardonForm"
		);

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 4 - UNKNOWN FORM" << std::endl;

	{
		Intern intern;

		AForm* form = intern.makeForm(
			"unknown form",
			"target"
		);

		ASSERT_TEST(
			form == NULL,
			"Unknown form should return NULL"
		);

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 5 - SIGN CREATED FORM" << std::endl;

	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm* form = intern.makeForm(
			"robotomy request",
			"Bender"
		);

		boss.signForm(*form);

		ASSERT_TEST(
			form->getIsSigned(),
			"Created form should be signed by Boss"
		);

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 6 - EXECUTE CREATED FORM" << std::endl;

	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm* form = intern.makeForm(
			"shrubbery creation",
			"home"
		);

		boss.signForm(*form);

		try
		{
			boss.executeForm(*form);

			ASSERT_TEST(
				true,
				"Signed ShrubberyCreationForm should execute"
			);
		}
		catch (...)
		{
			ASSERT_TEST(
				false,
				"Signed ShrubberyCreationForm should execute"
			);
		}

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 7 - SHRUBBERY FILE CREATED" << std::endl;

	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm* form = intern.makeForm(
			"shrubbery creation",
			"test_tree"
		);

		boss.signForm(*form);
		boss.executeForm(*form);

		std::ifstream file("test_tree_shrubbery");

		ASSERT_TEST(
			file.good(),
			"Shrubbery file should exist"
		);

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 8 - LOW GRADE SIGN" << std::endl;

	{
		Intern intern;
		Bureaucrat internGrade("Intern", 150);

		AForm* form = intern.makeForm(
			"robotomy request",
			"Bender"
		);

		internGrade.signForm(*form);

		ASSERT_TEST(
			!form->getIsSigned(),
			"Low grade bureaucrat should not sign RobotomyRequestForm"
		);

		delete form;
	}

	/**************************************************/
	std::cout << "\nTEST 9 - POLYMORPHISM" << std::endl;

	{
		Intern intern;

		AForm* forms[3];

		forms[0] = intern.makeForm(
			"shrubbery creation",
			"A"
		);

		forms[1] = intern.makeForm(
			"robotomy request",
			"B"
		);

		forms[2] = intern.makeForm(
			"presidential pardon",
			"C"
		);

		ASSERT_TEST(
			forms[0] != NULL &&
			forms[1] != NULL &&
			forms[2] != NULL,
			"Intern should create all three form types"
		);

		for (int i = 0; i < 3; i++)
			delete forms[i];
	}

	/**************************************************/
	std::cout << "\nTEST 10 - SUBJECT TEST" << std::endl;

	{
		Intern someRandomIntern;

		AForm* rrf =
			someRandomIntern.makeForm(
				"robotomy request",
				"Bender"
			);

		ASSERT_TEST(
			rrf != NULL,
			"Subject example should create a form"
		);

		ASSERT_TEST(
			dynamic_cast<RobotomyRequestForm*>(rrf) != NULL,
			"Subject example should create RobotomyRequestForm"
		);

		delete rrf;
	}

	std::cout << "\n========== END TESTS ==========\n" << std::endl;

	return 0;
}
