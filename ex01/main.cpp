/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/29 17:32:16 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat NPC("John Does");
	try {
		NPC = Bureaucrat("name", 8);
		std::cout << NPC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	
	Bureaucrat NPC2("Johnny Doesn't");
	try {
		NPC2 = Bureaucrat("name2", 141);
		std::cout << NPC2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	Form papier("Declaration d'impots");
	std::cout << "Name is " << papier.getName() << std::endl;
	std::cout << "Grade is " << papier.getSignGrade() << std::endl;
	std::cout << "SignGrade is " << papier.getSignGrade() << std::endl;
	std::cout << "ExecuteGrade is " << papier.getExecuteGrade() << std::endl;
	std::cout << papier << std::endl;

	papier.beSigned(NPC);
	papier.beSigned(NPC2);
	
	Form permis("Permis de conduire", 10, 12);
	permis.beSigned(NPC2);
	permis.beSigned(NPC);
	return 0;
}
	
