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

# include "Bureaucrat.hpp"
# include <string>

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		Form(void);
		Form(Form const & src);
		Form&	operator=(Form const & rhs);
		~Form(void);

		void	beSigned(Bureaucrat const & b);

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

#endif
