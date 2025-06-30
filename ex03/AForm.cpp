/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:16:52 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/30 10:52:36 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("Basic-AForm"), _signGrade(MIN_GRADE), _executeGrade(MIN_GRADE)
{
	
	this->_isSigned = false;
}

AForm::AForm(std::string name) : _name(name), _signGrade(MIN_GRADE), _executeGrade(MIN_GRADE)
{
	this->_isSigned = false;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->checkGrade(signGrade);
	this->checkGrade(executeGrade);
	this->_isSigned = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	this->checkGrade(other._signGrade);
	this->checkGrade(other._executeGrade);
	this->_isSigned = other._isSigned;
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	this->_isSigned = other._isSigned;
	return (*this);
}

void AForm::checkGrade(int grade) const
{
	if (grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getSignedState() const
{
	return (this->_isSigned);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void AForm::setSignedState(bool state)
{
	this->_isSigned = state;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
	{
		std::cout << this->_name << " is already signed." << std::endl;
		return;
	}
	try 
	{
		if (bureaucrat.getGrade() > this->_signGrade)
			throw AForm::GradeTooLowException();
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
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &o, AForm const &Aform) 
{
	o << Aform.getName() << ", AForm, status " << Aform.getSignedState() << ", SignGrade " << Aform.getSignGrade() << ", ExecuteGrade " << Aform.getExecuteGrade();
	return (o);
}
