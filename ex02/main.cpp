/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/30 12:30:53 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int test1_Shrubbery();
int test2_Shrubbery();
int test1_Robotomy();
int test1_PresidentPardon();

int main()
{
	test1_Shrubbery();
	std::cout << "----------------------------------------" << std::endl;
	test2_Shrubbery();
	std::cout << "----------------------------------------" << std::endl;
	test1_Robotomy();
	std::cout << "----------------------------------------" << std::endl;
	test1_PresidentPardon();
	return 0;
}
	
int test1_Shrubbery()
{
	Bureaucrat NPC("John Does");
	try {
		NPC = Bureaucrat("name", 8);
		std::cout << NPC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	
	Bureaucrat NPC2("Johnny Doesn't");
	try {
		NPC2 = Bureaucrat("name2", 141);
		std::cout << NPC2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	ShrubberyCreationForm papier("Declaration d'impots");
	std::cout << "Name is " << papier.getName() << std::endl;
	std::cout << "Grade is " << papier.getSignGrade() << std::endl;
	std::cout << "SignGrade is " << papier.getSignGrade() << std::endl;
	std::cout << "ExecuteGrade is " << papier.getExecuteGrade() << std::endl;
	std::cout << papier << std::endl;

	papier.beSigned(NPC);
	papier.beSigned(NPC2);
	try {
		papier.execute(NPC2);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	try {
		papier.execute(NPC);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}
	
	try {
		NPC.executeForm(papier);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}

	try {
		NPC2.executeForm(papier);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	return (0);
}

int test2_Shrubbery()
{
	Bureaucrat NPC("John Does");
	try {
		NPC = Bureaucrat("name", 8);
		std::cout << NPC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	
	Bureaucrat NPC2("Johnny Doesn't");
	try {
		NPC2 = Bureaucrat("name2", 141);
		std::cout << NPC2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	ShrubberyCreationForm permis("Permis de conduire", "Permis de conduire de John Does");
	try {
		NPC.executeForm(permis);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}
	permis.beSigned(NPC2);
	permis.beSigned(NPC);
	try {
		NPC2.executeForm(permis);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	permis.beSigned(NPC2);
	permis.beSigned(NPC);
	try {
		NPC.executeForm(permis);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}
	
	try {
		NPC2.executeForm(permis);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	return (0);
}

int test1_Robotomy()
{
	Bureaucrat NPC("John Does");
	try {
		NPC = Bureaucrat("name", 8);
		std::cout << NPC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	
	Bureaucrat NPC2("Johnny Doesn't");
	try {
		NPC2 = Bureaucrat("name2", 141);
		std::cout << NPC2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	RobotomyRequestForm robotomie("Autorisation de Robotomie", "Pichel Molnareff");
	try {
		NPC.executeForm(robotomie);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}
	robotomie.beSigned(NPC2);
	robotomie.beSigned(NPC);
	try {
		NPC2.executeForm(robotomie);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	robotomie.beSigned(NPC2);
	robotomie.beSigned(NPC);
	try {
		NPC.executeForm(robotomie);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}
	
	try {
		NPC2.executeForm(robotomie);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	return (0);
}


int test1_PresidentPardon()
{
	Bureaucrat NPC("John Does");
	try {
		NPC = Bureaucrat("name", 8);
		std::cout << NPC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	
	Bureaucrat NPC2("Johnny Doesn't");
	try {
		NPC2 = Bureaucrat("name2", 141);
		std::cout << NPC2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
		return (1);
	}

	Bureaucrat NPC3("Jerry CanDoEverything");
	try {
		NPC3 = Bureaucrat("name2", 1);
		std::cout << NPC3 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC3.getName() << ": " << e.what() << std::endl;
		return (1);
	}
	
	PresidentialPardonForm askForForgiveness("Autorisation de Pardon", "Joe Didn't");
	try {
		NPC.executeForm(askForForgiveness);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}
	askForForgiveness.beSigned(NPC2);
	askForForgiveness.beSigned(NPC);
	try {
		NPC2.executeForm(askForForgiveness);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	askForForgiveness.beSigned(NPC2);
	askForForgiveness.beSigned(NPC);
	try {
		NPC.executeForm(askForForgiveness);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC.getName() << ": " << e.what() << std::endl;
	}
	
	try {
		NPC2.executeForm(askForForgiveness);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC2.getName() << ": " << e.what() << std::endl;
	}
	try {
		NPC3.executeForm(askForForgiveness);
	} 
	catch (std::exception &e) {
		std::cout << "Error: " << NPC3.getName() << ": " << e.what() << std::endl;
	}
	return (0);
}
