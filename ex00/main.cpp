/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/28 14:49:51 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		Bureaucrat cratos;

		std::cout << "Name is " << cratos.getName() << std::endl;
		std::cout << "Grade is " << cratos.getGrade() << std::endl;
		std::cout << cratos << std::endl;

		cratos++;
		std::cout << cratos << std::endl;
		cratos++;
		cratos++;
		cratos++;
		cratos++;
		std::cout << cratos << std::endl;
		std::cout << cratos++ << std::endl;
		std::cout << ++cratos << std::endl;
	}
	{
		Bureaucrat cratos("Cratos", 1);

		std::cout << "Name is " << cratos.getName() << std::endl;
		std::cout << "Grade is " << cratos.getGrade() << std::endl;
		std::cout << cratos << std::endl;

		cratos++;
		std::cout << cratos << std::endl;
		std::cout << cratos << std::endl;
		std::cout << cratos++ << std::endl;
		std::cout << ++cratos << std::endl;
	
	}
	{
		Bureaucrat cratos("Crabe", 147);

		std::cout << "Name is " << cratos.getName() << std::endl;
		std::cout << "Grade is " << cratos.getGrade() << std::endl;
		std::cout << cratos << std::endl;

		cratos--;
		std::cout << cratos << std::endl;
		std::cout << cratos << std::endl;
		std::cout << cratos-- << std::endl;
		std::cout << --cratos << std::endl;
		std::cout << --cratos << std::endl;
		std::cout << --cratos << std::endl;
	
	}
	return 0;
}
	
