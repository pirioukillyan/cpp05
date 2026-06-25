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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	
	protected:
		virtual void	executeAction(void) const = 0;

	public:
		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
		AForm(void);
		AForm(AForm const & src);
		AForm&	operator=(AForm const & rhs);
		virtual ~AForm(void);

		std::string const &	getName(void) const;
		int const &			getGradeToSign(void) const;
		int const &			getGradeToExecute(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(Bureaucrat const & b);

		void				execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			public:
                const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

};

std::ostream &	operator<<(std::ostream& out, AForm const & f);

#endif
