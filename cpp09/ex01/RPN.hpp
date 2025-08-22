#ifndef RPN_HPP
#define RPN_HPP

#include <string> // std::string
#include <iostream> // std::cout|cerr|endl
#include <sstream> // std::istringstream
#include <stack> // std::stack<>
#include <cstdlib> // std::strtol()
#include <limits> // std::numeric_limits<>::min()|max()
#include <stdexcept> // std::runtime_error()

/**
 * RPN error cases:
 * - on parsing:
 *  meet an char other than [0-9] + - / * or space
 *  meet an operand >= 10
 * - on caclulation
 *  meet an operator + - / * but there is less than 2 operands in stack
 *  division by 0
 *  int overflow
 * - on reaching the end of expression
 *  number of operands in stack is not 1
 */
class RPN
{
	std::stack<int>	_stack;

	RPN();
	RPN(RPN const&);
	RPN&	operator=(RPN const&);

	void	_calculate (std::string const&);
	void	_pushOperand(std::string const&);
	void	_pushOperatorResult(std::string const&);

	public:
	
		RPN(std::string const&);
		~RPN();

		int const&	getResult() const;
};

#endif
