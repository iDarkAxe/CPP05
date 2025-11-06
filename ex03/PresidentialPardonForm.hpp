#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;

	public:
		static const int SIGN_GRADE = 25;
		static const int EXEC_GRADE = 5;

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
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

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &crat);

#endif
