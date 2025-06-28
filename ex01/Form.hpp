#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form();
		Form(std::string name);
		Form(std::string name, int signGrade, int executeGrade);
		~Form();
		Form(const Form &f);
		Form &operator=(const Form &other);

		std::string getName() const;
		int getSignedState() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(class Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception 
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form const &crat);

#endif
