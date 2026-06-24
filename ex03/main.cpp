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
	std::srand(std::time(NULL));

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 1 - SHRUBBERY" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);
            ShrubberyCreationForm form("home");

            boss.signForm(form);
            boss.executeForm(form);

            std::ifstream file("home_shrubbery");
            ASSERT_TEST(file.good(), "file should be created");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 2 - ROBOTOMY" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);
            RobotomyRequestForm form("Marvin");

            boss.signForm(form);

            for (int i = 0; i < 3; i++)
                boss.executeForm(form);

            ASSERT_TEST(true, "robotomy executed multiple times");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 3 - PRESIDENTIAL PARDON" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("President", 1);
            PresidentialPardonForm form("Alice");

            boss.signForm(form);
            boss.executeForm(form);

            ASSERT_TEST(true, "pardon executed");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 4 - UNSIGNED FORM EXECUTION" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);
            ShrubberyCreationForm form("error_test");

            boss.executeForm(form);

            ASSERT_TEST(true, "should not execute unsigned form");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 5 - LOW GRADE SIGN" << NC << std::endl;

    {
        try
        {
            Bureaucrat intern("Intern", 150);
            RobotomyRequestForm form("Marvin");

            intern.signForm(form);

            ASSERT_TEST(true, "intern should NOT sign");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 6 - LOW GRADE EXECUTE" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);
            RobotomyRequestForm form("Marvin");

            boss.signForm(form);

            Bureaucrat intern("Intern", 150);
            intern.executeForm(form);

            ASSERT_TEST(true, "intern should NOT execute");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 7 - POLYMORPHISM" << NC << std::endl;

    {
        try
        {
            Bureaucrat boss("Boss", 1);

            AForm* forms[3];

            forms[0] = new ShrubberyCreationForm("A");
            forms[1] = new RobotomyRequestForm("B");
            forms[2] = new PresidentialPardonForm("C");

            for (int i = 0; i < 3; i++)
            {
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
            }

            for (int i = 0; i < 3; i++)
                delete forms[i];

            ASSERT_TEST(true, "polymorphism works");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    /**************************************************/
    std::cout << std::endl;
    std::cout << MAGENTA << "TEST 8 - COPY FORM" << NC << std::endl;

    {
        try
        {
            ShrubberyCreationForm a("copy_test");
            ShrubberyCreationForm b(a);

            ASSERT_TEST(a.getName() == b.getName(), "copy name");
            ASSERT_TEST(a.getGradeToSign() == b.getGradeToSign(), "copy grade sign");
            ASSERT_TEST(a.getGradeToExecute() == b.getGradeToExecute(), "copy grade exec");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(false, e.what());
        }
    }

    std::cout << std::endl;
    std::cout << MAGENTA << "===== END TESTS =====" << NC << std::endl;

	return 0;
}
