#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("shrubbery creation", 145, 137), _target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target):
	AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src):
	AForm(src._name, src._gradeToSign, src._gradeToExecute) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
		_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream o((_target + "_shrubbery").c_str());
	if (!o) { // operator! overload, equivalent to `o.fail()`
		std::cerr << "Error: opening file " << _target << "_shrubbery" << std::endl;
		return;
	}
	o << "\n";
	o << "        # #### ####                ### ###\n";
	o << "      ### \\/#|### |/##         ## \\/##|/###  #           # ###  ##\n";
	o << "     ##\\/#/ \\||/##/_/##/#     ###\\/#/ \\||/##/_#        ### \\/##|##/#\n";
	o << "   ###  \\/###|/ \\/ # ###      #### \\/###|/ \\/ ##      ##\\/#/ \\| /#####\n";
	o << " ##_\\_#\\_\\## | #/###_/_###  ##_\\_#\\_\\## | #/###_/_   #### \\/###|/# \\/##\n";
	o << "## #### # \\ #| /  #### ##/# # #### # \\ #| /  ####   ##_\\_#\\_\\## | #/##\n";
	o << " __#_--###`  |{,###---###-~  \\__#_--###`  |{,###--  # #### # \\ #| / ###\n";
	o << "           \\ }{                      \\ }{           -~ __#_--###`  |{,\n";
	o << "            }}{                       }}{                  \\ }{\n";
	o << "            }}{                       }}{                   }}{\n";
	o << "            {{}                       {{}                   }}{\n";
	o << " ^ _ . , -=-~  .-^- _ -_ . - _.^ , -=-~  .-^- _ .- = . ~ -=-~  .-^- _ -\n";
	o << "            `          \"           `          \'             `\n";
	std::cout << "Shrubbery has been created in " << _target << "_shrubbery" << std::endl;
}
