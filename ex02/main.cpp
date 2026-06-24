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
#include <iostream>
#include <ctime>
#include <cstdlib>

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
	std::srand(std::time(NULL));

    std::cout << std::endl;
    std::cout << MAGENTA << "TEST ROBOTOMY REQUEST FORM" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);
            RobotomyRequestForm form("Marvin");

            std::cout << form << std::endl;

            boss.signForm(form);

            // On teste plusieurs exécutions pour voir le 50%
            for (int i = 0; i < 5; i++)
            {
                std::cout << "\nExecution " << i + 1 << ":\n";
                boss.executeForm(form);
            }

            ASSERT_TEST(form.getIsSigned() == true, "form should be signed");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    std::cout << std::endl;

    std::cout << MAGENTA << "TEST ROBOTOMY WITHOUT SIGNATURE" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);
            RobotomyRequestForm form("Marvin");

            boss.executeForm(form);

            ASSERT_TEST(false, "execution should fail (not signed)");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(true, e.what());
        }
    }

    std::cout << std::endl;

    std::cout << MAGENTA << "TEST ROBOTOMY LOW GRADE" << NC << std::endl;

    {
        try
        {
            Bureaucrat intern("Intern", 150);
            RobotomyRequestForm form("Marvin");

            intern.signForm(form);
            intern.executeForm(form);

            ASSERT_TEST(false, "low grade should fail");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(true, e.what());
        }
    }

    std::cout << std::endl;

    std::cout << MAGENTA << "TEST ROBOTOMY MULTIPLE TARGETS" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);

            RobotomyRequestForm a("Alice");
            RobotomyRequestForm b("Bob");
            RobotomyRequestForm c("Charlie");

            boss.signForm(a);
            boss.signForm(b);
            boss.signForm(c);

            boss.executeForm(a);
            boss.executeForm(b);
            boss.executeForm(c);

            ASSERT_TEST(true, "multiple robotomies executed");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

	
	return 0;
}
