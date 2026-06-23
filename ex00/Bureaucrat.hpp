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

class Bureaucrat
{
	private:
		std::string const   _name;
		int                 _grade;

	public:
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat &	operator=(Bureaucrat const & rhs);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		upGrade(int up);
		void		downGrade(int down);

};

#endif
