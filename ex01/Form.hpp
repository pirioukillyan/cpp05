/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:56:52 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 13:56:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		Form(void);
		Form(Form const & src);
		Form&	operator=(Form const & rhs);
		~Form(void);

		std::string const &	getName(void) const;
		int const &			getGradeToSign(void) const;
		int const &			getGradeToExecute(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(Bureaucrat const & b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("form grade too high");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("form grade too low");
				}
		};

};

std::ostream &	operator<<(std::ostream& out, Form const & f);

#endif
