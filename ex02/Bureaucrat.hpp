#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

		void checkGrade(int grade) const;

	public:
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
		
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &f);
		Bureaucrat &operator=(const Bureaucrat &other);

		std::string getName() const;
		int	getGrade() const;
		Bureaucrat &operator++(void);
		Bureaucrat operator++(int);
		Bureaucrat &operator--(void);
		Bureaucrat operator--(int);
		void executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &crat);

#endif
