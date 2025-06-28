/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:16:52 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/28 18:38:20 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("Basic-Form"), _signGrade(150), _executeGrade(150)
{
	this->_isSigned = false;
}

Form::Form(std::string name) : _name(name), _signGrade(150), _executeGrade(150)
{
	this->_isSigned = false;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->_isSigned = false;
}

Form::~Form()
{
}

Form::Form(const Form &other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	this->_isSigned = other._isSigned;
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	this->_isSigned = other._isSigned;
	return (*this);
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
	try 
	{
		if (bureaucrat.getGrade() < this->_signGrade)
			throw Form::GradeTooLowException();
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
		this->_isSigned = true;
	} 
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
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
