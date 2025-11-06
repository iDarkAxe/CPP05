/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:16:52 by ppontet           #+#    #+#             */
/*   Updated: 2025/11/06 10:50:49 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

static void robotomization(std::ostream &o, std::string target);

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", this->SIGN_GRADE, this->EXEC_GRADE), _target("DefaultTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", this->SIGN_GRADE, this->EXEC_GRADE), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->setSignedState(other.getSignedState());
	return (*this);
}

void RobotomyRequestForm::execute(class Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw RobotomyRequestForm::CannontExecuteNotSignedException();
	if (executor.getGrade() > this->EXEC_GRADE)
		throw AForm::GradeTooLowException();
	robotomization(std::cout, this->_target);
}

// Exceptions
const char* RobotomyRequestForm::CannontExecuteNotSignedException::what() const throw()
{
    return ("Error: cannot execute because it is not signed.");
}

void robotomization(std::ostream &o, std::string target) 
{
	int a;
	
	srand(time(NULL));
	a = rand() % 2;
	if (a == 0)
		o << "Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz... " << std::endl
		  << "Robotomy successful on "<< target << "!" << std::endl;
	else
		o << "Robotomy failed on "<< target << "!" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &RobotomyRequestForm) 
{
	o << RobotomyRequestForm.getName() << ", RobotomyRequestForm, status " << RobotomyRequestForm.getSignedState() << ", SignGrade " << RobotomyRequestForm.getSignGrade() << ", ExecuteGrade " << RobotomyRequestForm.getExecuteGrade();
	return (o);
}
