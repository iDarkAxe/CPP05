#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;

	public:
		static const int SIGN_GRADE = 145;
		static const int EXEC_GRADE = 137;

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(std::string name, std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &f);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		void execute(class Bureaucrat const &executor) const;

	class CannontExecuteNotSignedException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};

void write_tree(std::ostream &o);

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &crat);

#endif
