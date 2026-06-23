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
    std::cout << MAGENTA << "TEST 1 - VALID CREATION" << NC << std::endl;
    try
    {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
        ASSERT_TEST(a.getGrade() == 42, "valid creation");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 2 - INVALID CREATION" << NC << std::endl;

    try
    {
        Bureaucrat a("Alice", 0);
        ASSERT_TEST(false, "grade 0 should throw");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(true, e.what());
    }

    try
    {
        Bureaucrat b("Bob", 151);
        ASSERT_TEST(false, "grade 151 should throw");
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(true, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 3 - COPY CONSTRUCTOR" << NC << std::endl;

    try
    {
        Bureaucrat a("Alice", 10);
        Bureaucrat copy(a);

        ASSERT_TEST(copy.getName() == a.getName(), "name copy");
        ASSERT_TEST(copy.getGrade() == a.getGrade(), "grade copy");

        std::cout << "original: " << a << std::endl;
        std::cout << "copy:     " << copy << std::endl;
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 4 - OPERATOR =" << NC << std::endl;

    try
    {
        Bureaucrat a("Alice", 10);
        Bureaucrat b("Bob", 100);

        b = a;

        ASSERT_TEST(b.getGrade() == 10, "operator= grade");

        // name must NOT change (const rule)
        ASSERT_TEST(b.getName() == "Bob", "operator= name stays same");

        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    std::cout << std::endl;

    /************************************/
    std::cout << MAGENTA << "TEST 5 - INCREMENT / DECREMENT" << NC << std::endl;

    try
    {
        Bureaucrat a("Alice", 2);

        a.incrementGrade(1);
        ASSERT_TEST(a.getGrade() == 1, "increment to 1");

        try
        {
            a.incrementGrade(1); // should throw
            ASSERT_TEST(false, "increment above 1 should throw");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(true, e.what());
        }
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b("Bob", 149);

        b.decrementGrade(1);
        ASSERT_TEST(b.getGrade() == 150, "decrement to 150");

        try
        {
            b.decrementGrade(1); // should throw
            ASSERT_TEST(false, "decrement below 150 should throw");
        }
        catch (std::exception &e)
        {
            ASSERT_TEST(true, e.what());
        }
    }
    catch (std::exception &e)
    {
        ASSERT_TEST(false, e.what());
    }

	return 0;
}
