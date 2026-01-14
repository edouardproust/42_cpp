#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN const& other)
: _stack(other._stack)
{}

RPN&	RPN::operator=(RPN const& other)
{
	if (this != &other) {
		_stack = other._stack; // Use of std::stack's operator=()
	}
	return *this;
}

RPN::~RPN()
{}

int	RPN::calculate(std::string const& expr)
{
	// Check chars validity
	size_t invalidCharPos = expr.find_first_not_of("0123456789 +-*/");
	if (invalidCharPos != std::string::npos) {
		throw std::runtime_error("invalid char: " + std::string(1, expr[invalidCharPos]));
	}
	// Extract tokens and process them
	std::istringstream ss(expr);
	for (std::string token; ss >> token;) { // Auto skip whitespaces before filling token
		if (token.size() == 1 && token.find_first_of("+-/*") != std::string::npos) {
			_pushOperatorResult(token);
		} else {
			_pushOperand(token);
		}
	}
	// Return result
	if (_stack.size() != 1) {
		throw std::overflow_error("unprocessed operand(s)");
	}
	return _stack.top();
}

void	RPN::_pushOperand(std::string const& operand)
{
	char* endptr;
	long n = std::strtol(operand.c_str(), &endptr, 10);
	if (*endptr != '\0' || n < 0 || n > 9) {
		throw std::runtime_error("invalid operand: " + operand);
	}
	_stack.push(static_cast<int>(n));
}

void	RPN::_pushOperatorResult(std::string const& op)
{
	// Operator needs 2 operands to be possible
	if (_stack.size() < 2) {
		throw std::underflow_error("not enough operands before operator");
	}
	// Get the 2 top operands
	int second = _stack.top();
	_stack.pop();
	int first = _stack.top();
	_stack.pop();
	// Do the calculation
	long res;
	if (op == "+") {
		res = static_cast<long>(first) + second;
	} else if (op == "-") {
		res = static_cast<long>(first) - second;
	} else if (op == "/") {
		if (second == 0) {
			throw std::runtime_error("division by 0");
		}
		res = static_cast<long>(first) / second;
	} else if (op == "*") {
		res = static_cast<long>(first) * second;
	} else {
		throw std::runtime_error("invalid operator token");
	}
	// Check result overflow
	if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max()) {
		throw std::overflow_error("intermediary result overflow");
	}
	// Push result to stack
	_stack.push(static_cast<int>(res));
}

