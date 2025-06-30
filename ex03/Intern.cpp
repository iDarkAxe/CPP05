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
	{
		std::cout << "Error: Intern couldn't create form with empty name." << std::endl;
		return NULL;
	}
	size_t index = 0;
	while (formName != formNamesList[index] && index < this->NBR_OF_FORMS)
		index++;

	switch (index)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Error: Intern couldn't create form '" << formName << "'." << std::endl;
			return NULL;
	}
}

// Exceptions
const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Error: Intern couldn't create form as it doesn't exist.");
}


std::ostream &operator<<(std::ostream &o, Intern const &intern) 
{
	(void)intern;
	o << "Simple Intern ";
	return (o);
}
