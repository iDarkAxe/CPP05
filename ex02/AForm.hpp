#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _executeGrade;

		void checkGrade(int grade) const;

	protected:
		AForm();
		AForm(std::string name);
		AForm(std::string name, int signGrade, int executeGrade);

	public:
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;

		virtual ~AForm();
		AForm(const AForm &f);
		AForm &operator=(const AForm &other);

		std::string getName() const;
		int getSignedState() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void setSignedState(bool state);
		void beSigned(class Bureaucrat &bureaucrat);
		virtual void execute(class Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &o, AForm const &crat);

#endif
