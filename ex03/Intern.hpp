/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:34:06 by marvin            #+#    #+#             */
/*   Updated: 2026/06/24 15:34:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern
{
	private:

	public:
		Intern(void);
		Intern(Intern const & src);
		Intern &	operator=(Intern const & rhs);
		~Intern(void);

		AForm*	makeForm(std::string const & formName, std::string const & target) const;

};

#endif
