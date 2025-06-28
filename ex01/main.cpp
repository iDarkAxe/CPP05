/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/28 18:36:16 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	{
		Bureaucrat NPC("John Does", 100);
		Bureaucrat NPC2("Johnny Doesn't", 150);

		std::cout << NPC << std::endl;

		Form papier;

		std::cout << "Name is " << papier.getName() << std::endl;
		std::cout << "Grade is " << papier.getSignGrade() << std::endl;
		std::cout << "SignGrade is " << papier.getSignGrade() << std::endl;
		std::cout << "ExecuteGrade is " << papier.getExecuteGrade() << std::endl;
		std::cout << papier << std::endl;

		papier.beSigned(NPC);
		papier.beSigned(NPC2);
	}
	{
		Form papier("Declaration d'impots");
	
	}
	{
		Form papier("Permis de conduire", 147, 145);

		
	}
	return 0;
}
	
