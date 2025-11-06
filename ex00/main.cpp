/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/11/06 09:51:28 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
{
	try 
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
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
{
	try 
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
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
{
	try 
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
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
	return 0;
}
	
