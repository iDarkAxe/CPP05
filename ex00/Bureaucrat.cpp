/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:34 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/28 14:56:01 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Basic-Bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) 
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// Pre-Increment
Bureaucrat &Bureaucrat::operator++(void) 
{
	try
	{
		if (this->_grade - 1 < 1)
			throw std::out_of_range("Grade too high, cannot increment.");
		this->_grade -= 1;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (*this);
	}
	return (*this);
}

// Post-Increment (int dummy, exist only to differentiate with pre-increment)
Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat temp(*this);

	try
	{
		if (this->_grade - 1 < 1)
			throw std::out_of_range("Grade too high, cannot increment.");
		this->_grade -= 1;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (*this);
	}
	return (temp);
}

// Pre-Decrement
Bureaucrat &Bureaucrat::operator--(void) 
{
	try
	{
		if (this->_grade + 1 > 150)
			throw std::out_of_range("Grade too low, cannot decrement.");
		this->_grade += 1;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (*this);
	}
	return (*this);
}

// Post-Decrement (int dummy, exist only to differentiate with pre-decrement)
Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat temp(*this);

	try
	{
		if (this->_grade + 1 > 150)
			throw std::out_of_range("Grade too low, cannot decrement.");
		this->_grade += 1;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (*this);
	}
	return (temp);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &crat) 
{
	o << crat.getName() << ", bureaucrat grade " << crat.getGrade();
	return (o);
}
