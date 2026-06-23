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
#include "Form.hpp"
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
    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 1 - FORM CREATION VALID/INVALID" << NC << std::endl;

    try
    {
        Form f1("TaxForm", 50, 30);
        std::cout << f1 << std::endl;

        ASSERT_TEST(f1.getGradeToSign() == 50, "gradeToSign ok");
        ASSERT_TEST(f1.getGradeToExecute() == 30, "gradeToExecute ok");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    try
    {
        Form f2("BadForm", 0, 30);
        ASSERT_TEST(false, "grade 0 should throw");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(true, e.what());
    }

    try
    {
        Form f3("BadForm2", 50, 151);
        ASSERT_TEST(false, "grade 151 should throw");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(true, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 2 - SIGN SUCCESS" << NC << std::endl;

    try
    {
        Bureaucrat b("Alice", 10);
        Form f("FormA", 50, 20);

        b.signForm(f);

        ASSERT_TEST(f.getIsSigned() == true, "form should be signed");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 3 - SIGN FAIL (GRADE TOO LOW)" << NC << std::endl;

    try
    {
        Bureaucrat b("Bob", 100);
        Form f("FormB", 50, 20);

        b.signForm(f);

        ASSERT_TEST(f.getIsSigned() == false, "form should NOT be signed");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 4 - EDGE CASES" << NC << std::endl;

    try
    {
        Bureaucrat top("Top", 1);
        Bureaucrat low("Low", 150);

        Form f("EdgeForm", 1, 150);

        top.signForm(f);
        ASSERT_TEST(f.getIsSigned() == true, "top can sign");

        Form f2("EdgeForm2", 1, 150);

        low.signForm(f2);
        ASSERT_TEST(f2.getIsSigned() == false, "low cannot sign grade 1 form");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 5 - COPY / PRINT" << NC << std::endl;

    try
    {
        Form f("Original", 42, 20);
        Form copy(f);

        ASSERT_TEST(copy.getName() == f.getName(), "copy name");
        ASSERT_TEST(copy.getGradeToSign() == f.getGradeToSign(), "copy grade sign");
        ASSERT_TEST(copy.getGradeToExecute() == f.getGradeToExecute(), "copy grade exec");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }


	return 0;
}
