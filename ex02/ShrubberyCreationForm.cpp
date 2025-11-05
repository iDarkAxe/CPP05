/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:16:52 by ppontet           #+#    #+#             */
/*   Updated: 2025/11/05 11:03:28 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", this->SIGN_GRADE, this->EXEC_GRADE), _target("DefaultTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", this->SIGN_GRADE, this->EXEC_GRADE), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->setSignedState(other.getSignedState());
	return (*this);
}

void ShrubberyCreationForm::execute(class Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw ShrubberyCreationForm::CannontExecuteNotSignedException();
	if (executor.getGrade() > this->EXEC_GRADE)
		throw AForm::GradeTooLowException();
	std::string filename = this->_target + "_shrubbery";
	std::ofstream os(filename.c_str());
	if (os.is_open() == false)
	{
		std::cout << "Error: could not open file " << this->_target << std::endl;
		return;
	}
	write_tree(os);
	write_tree(os);
}

// Exceptions
const char* ShrubberyCreationForm::CannontExecuteNotSignedException::what() const throw()
{
    return ("Error: cannot execute because it is not signed.");
}

void write_tree(std::ostream &o) 
{
	o << "         _-_-_\n";
	o << "      /~~     ~~\\\n";
	o << "   /~~           ~~\\\n";
	o << "  |                 |\n";
	o << "  |                 |\n";
	o << "   \\__           __/\n";
	o << "      \\_________/\n";
	o << "         | | |\n";
	o << "         | | |\n";
	o << "         | | |\n";
	o << "         | | |\n";
	o << "   * *   | | |\n";
	o << "   | |   | | | \n";
	o << " -----------------\n";
	return ;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &ShrubberyCreationForm) 
{
	o << ShrubberyCreationForm.getName() << ", ShrubberyCreationForm, status " << ShrubberyCreationForm.getSignedState() << ", SignGrade " << ShrubberyCreationForm.getSignGrade() << ", ExecuteGrade " << ShrubberyCreationForm.getExecuteGrade();
	return (o);
}
