/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:41:09 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 17:41:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (_target.empty())
		throw std::invalid_argument("Target must be specified");
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
	if (_target.empty())
		throw std::invalid_argument("Target must be specified");
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		if (rhs._target.empty())
			throw std::invalid_argument("Target must be specified");
		_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);

	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out)
		throw FileNotAccess();

	out <<
	"                      ___\n"
	"                _,-'\"\"   \"\"\"\"`--.\n"
	"             ,-'          __,,-- \\\n"
	"           ,'    __,--\"\"\"\"dF      )\n"
	"          /   .-\"Hb_,--\"\"dF      /\n"
	"        ,'       _Hb ___dF\"-._,-'\n"
	"      ,'      _,-\"\"\"\"   \"\"--..__\n"
	"     (     ,-'                  `.\n"
	"      `._,'     _   _             ;\n"
	"       ,'     ,' `-'Hb-.___..._,-'\n"
	"       \\    ,'\"Hb.-'HH`-.dHF\"\n"
	"        `--'   \"Hb  HH  dF\"\n"
	"                \"Hb HH dF\n"
	"                 \"HbHHdF\n"
	"                  |HHHF\n"
	"                  |HHH|\n"
	"                  |HHH|\n"
	"                  |HHH|\n"
	"                  |HHH|\n"
	"                  dHHHb\n"
	"                .dFd|bHb.               o\n"
	"      o       .dHFdH|HbTHb.          o /\n"
	"\\  Y  |  \\__,dHHFdHH|HHhoHHb.__kpiriou  \n"
	"##########################################\n";
	out.close();

}

/* dans un fichier <_target>_shrubbery
                      ___
                _,-'""   """"`--.
             ,-'          __,,-- \
           ,'    __,--""""dF      )
          /   .-"Hb_,--""dF      /
        ,'       _Hb ___dF"-._,-'
      ,'      _,-""""   ""--..__
     (     ,-'                  `.
      `._,'     _   _             ;
       ,'     ,' `-'Hb-.___..._,-'
       \    ,'"Hb.-'HH`-.dHF"
        `--'   "Hb  HH  dF"
                "Hb HH dF
                 "HbHHdF
                  |HHHF
                  |HHH|
                  |HHH|
                  |HHH|
                  |HHH|
                  dHHHb
                .dFd|bHb.               o
      o       .dHFdH|HbTHb.          o /
\  Y  |  \__,dHHFdHH|HHhoHHb.__Krogg  Y
##########################################
*/
