#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;

	public:
		static const int SIGN_GRADE = 72;
		static const int EXEC_GRADE = 45;

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &f);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		void execute(class Bureaucrat const &executor) const;

	class CannontExecuteNotSignedException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};

void robotomization(std::ostream &o, std::string target);

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &crat);

#endif
