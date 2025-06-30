/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:16:52 by ppontet           #+#    #+#             */
/*   Updated: 2025/06/30 12:31:50 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", this->SIGN_GRADE, this->EXEC_GRADE), _target("DefaultTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, this->SIGN_GRADE, this->EXEC_GRADE), _target("DefaultTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : AForm(name, this->SIGN_GRADE, this->EXEC_GRADE), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->setSignedState(other.getSignedState());
	return (*this);
}

void PresidentialPardonForm::execute(class Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw PresidentialPardonForm::CannontExecuteNotSignedException();
	if (executor.getGrade() > this->EXEC_GRADE)
		throw AForm::GradeTooLowException();
	bePardonned(std::cout, this->_target);
}

// Exceptions
const char* PresidentialPardonForm::CannontExecuteNotSignedException::what() const throw()
{
    return ("Error: cannot execute because it is not signed.");
}

void bePardonned(std::ostream &o, std::string target) 
{
	o << "Presidential Pardon granted to " << target << "!" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &PresidentialPardonForm) 
{
	o << PresidentialPardonForm.getName() << ", PresidentialPardonForm, status " << PresidentialPardonForm.getSignedState() << ", SignGrade " << PresidentialPardonForm.getSignGrade() << ", ExecuteGrade " << PresidentialPardonForm.getExecuteGrade();
	return (o);
}
