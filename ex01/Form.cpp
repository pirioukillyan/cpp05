/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:14:22 by marvin            #+#    #+#             */
/*   Updated: 2026/06/23 14:14:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("unamed"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(Form const & src);

Form&	Form::operator=(Form const & rhs);
Form::~Form(void);
