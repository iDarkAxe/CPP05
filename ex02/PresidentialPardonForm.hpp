#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;

		void checkGrade(int grade) const;

	public:
		static const int SIGN_GRADE = 25;
		static const int EXEC_GRADE = 5;

		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(std::string name, std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &f);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		void execute(class Bureaucrat const &executor) const;

	class CannontExecuteNotSignedException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};

void bePardonned(std::ostream &o, std::string target);

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &crat);

#endif
