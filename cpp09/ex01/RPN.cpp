#include "RPN.hpp"

RPN::RPN(std::string const& input) {
	_calculate(input);
}

RPN::~RPN() {}

int const&	RPN::getResult() const {
	if (_stack.size() != 1) {
		throw std::runtime_error("unprocessed operand(s)");
	}
	return _stack.top();
}

void	RPN::_calculate(std::string const& expr)
{
	// Check chars validity
	if (expr.find_first_not_of("0123456789 +-*/") != std::string::npos) {
		throw std::runtime_error("invalid char found");
	}
	// Extract tokens and process them
	std::istringstream ss(expr);
	for (std::string token; ss >> token;) {
	//for (std::string token; std::getline(ss, token, ' ');) {
	//	if (token.size() == 0) continue;
		if (token.size() == 1 && token.find_first_of("+-/*") != std::string::npos) {
			_pushOperatorResult(token);
		} else {
			_pushOperand(token);
		}
	}
}

void	RPN::_pushOperand(std::string const& operand)
{
	char* endptr;
	long n = std::strtol(operand.c_str(), &endptr, 10);
	if (*endptr != '\0') {
		throw std::runtime_error("invalid operand");
	}
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()) {	
		throw std::runtime_error("operand oveflow");
	}
	_stack.push(static_cast<int>(n));
}

void	RPN::_pushOperatorResult(std::string const& op)
{
	// Operator needs 2 operands to be possible
	if (_stack.size() < 2) {
		throw std::runtime_error("not enough operands before operator");
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
		throw std::runtime_error("intermediary result overflow");
	}
	// Push result to stack
	_stack.push(static_cast<int>(res));
}

