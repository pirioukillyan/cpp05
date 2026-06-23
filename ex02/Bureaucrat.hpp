/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:52:54 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 10:52:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class AForm;

class Bureaucrat
{
	private:
		std::string const   _name;
		int                 _grade;

	public:
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat&	operator=(Bureaucrat const & rhs);
		~Bureaucrat(void);

		std::string const &	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(int up);
		void				decrementGrade(int down);

		void				signForm(AForm & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("bureaucrat grade too high");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("bureaucrat grade too low");
				}
		};

};

std::ostream&	operator<<(std::ostream& out, Bureaucrat const & b);

#endif
