/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:03:05 by marvin            #+#    #+#             */
/*   Updated: 2026/06/24 14:03:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	
	protected:
		void	executeAction(void) const;

	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);
};

#endif
