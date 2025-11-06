/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:34 by ppontet           #+#    #+#             */
/*   Updated: 2025/11/06 09:47:43 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Basic-Bureaucrat"), _grade(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	this->checkGrade(grade);
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
	if (this->_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	this->_grade -= 1;
	return (*this);
}

// Post-Increment (int dummy, exist only to differentiate with pre-increment)
Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat temp(*this);

	if (this->_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	this->_grade -= 1;
	return (temp);
}

// Pre-Decrement
Bureaucrat &Bureaucrat::operator--(void) 
{
	if (this->_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	this->_grade += 1;
	return (*this);
}

// Post-Decrement (int dummy, exist only to differentiate with pre-decrement)
Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat temp(*this);

	if (this->_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	this->_grade += 1;
	return (temp);
}

void Bureaucrat::checkGrade(int grade) const
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
	} catch (std::exception & e) {
		std::cout << "Error: " << this->getName() << " couldn't execute " << form.getName() << " because '" << e.what() << "'." << std::endl;
		return;
	}
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &crat) 
{
	o << crat.getName() << ", bureaucrat grade " << crat.getGrade();
	return (o);
}
