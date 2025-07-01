/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/07/01 13:22:35 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

/* Form name accepted by Intern:
"shrubbery creation"
"robotomy request"
"presidential pardon" */
int try_all_forms(void);
int try_modify_form(void);

int main()
{
	if (try_all_forms() != 0)
	{
		std::cout << "An error occurred while trying to create forms." << std::endl;
		return (1);
	}
	if (try_modify_form() != 0)
	{
		std::cout << "An error occurred while trying to modify forms." << std::endl;
		return (1);
	}
	return (0);
}

int try_all_forms(void)
{
	Intern someRandomIntern;
	AForm* rrf;

	try {
		rrf = someRandomIntern.makeForm("not existant", "Earth");
		std::cout << *rrf << std::endl;
		delete rrf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		rrf = someRandomIntern.makeForm("shrubbery creation", "Wind");
		std::cout << *rrf << std::endl;
		delete rrf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Fire");
		std::cout << *rrf << std::endl;
		delete rrf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		rrf = someRandomIntern.makeForm("presidential pardon", "Water");
		std::cout << *rrf << std::endl;
		delete rrf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}

int try_modify_form(void)
{
	Intern someRandomIntern;
	AForm* rrf;

	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Pachycephalosaurus");	
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	std::cout << *rrf << std::endl;
	std::cout << someRandomIntern << std::endl;
	Bureaucrat trex("T-Rex", 1);

	rrf->beSigned(trex);
	trex.executeForm(*rrf);
	delete rrf;
	return 0;
}
