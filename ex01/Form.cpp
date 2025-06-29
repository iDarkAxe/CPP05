/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:16:52 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/29 17:28:16 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("Basic-Form"), _signGrade(MIN_GRADE), _executeGrade(MIN_GRADE)
{
	
	this->_isSigned = false;
}

Form::Form(std::string name) : _name(name), _signGrade(MIN_GRADE), _executeGrade(MIN_GRADE)
{
	this->_isSigned = false;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->checkGrade(signGrade);
	this->checkGrade(executeGrade);
	this->_isSigned = false;
}

Form::~Form()
{
}

Form::Form(const Form &other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	this->checkGrade(other._signGrade);
	this->checkGrade(other._executeGrade);
	this->_isSigned = other._isSigned;
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	this->_isSigned = other._isSigned;
	return (*this);
}

void Form::checkGrade(int grade) const
{
	if (grade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getSignedState() const
{
	return (this->_isSigned);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
	{
		std::cout << this->_name << " is already signed." << std::endl;
		return;
	}
	try 
	{
		if (bureaucrat.getGrade() > this->_signGrade)
			throw Form::GradeTooLowException();
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
		this->_isSigned = true;
	} 
	catch (std::exception & e)
	{
		std::cout << "Error: " << bureaucrat.getName() << " couldn't sign " << this->_name << " because '" << e.what() << "'." <<std::endl;
		return;
	}
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &o, Form const &form) 
{
	o << form.getName() << ", Form, status " << form.getSignedState() << ", SignGrade " << form.getSignGrade() << ", ExecuteGrade " << form.getExecuteGrade();
	return (o);
}
