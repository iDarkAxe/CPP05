/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:34 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/30 11:45:23 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target) const
{
	const std::string formNamesList[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	if (formName.empty())
		throw Intern::NoNameException();
	size_t index = 0;
	while (index < this->NBR_OF_FORMS && formName != formNamesList[index])
		index++;
	switch (index)
	{
		case 0:
			return new ShrubberyCreationForm("DefaultShrubberyCreationForm", target);
		case 1:
			return new RobotomyRequestForm("DefaultRobotomyRequestForm", target);
		case 2:
			return new PresidentialPardonForm("DefaultPresidentialPardonForm", target);
		default:
			throw Intern::FormNotFoundException();
	}
}

// Exceptions
const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Error: Intern couldn't create form as it doesn't exist.");
}

const char* Intern::NoNameException::what() const throw()
{
    return ("Error: Intern couldn't find a name of form.");
}

std::ostream &operator<<(std::ostream &o, Intern const &intern) 
{
	(void)intern;
	o << "Simple Intern can't say it's name as no one asked for it.";
	return (o);
}
