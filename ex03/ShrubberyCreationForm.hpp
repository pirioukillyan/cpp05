/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:33:14 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 17:33:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const & executor) const;

		class FileNotAccess : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Not file access.";
				}
		};

};

#endif
