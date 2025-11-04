#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
	private:

	public:
		static const int NBR_OF_FORMS = 3;

		Intern();
		~Intern();
		Intern(const Intern &f);
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string formName, std::string target) const;

	class NoNameException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Intern const &crat);

#endif
