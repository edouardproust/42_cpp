#include <iostream>
#include <stack>
#include <cstdlib>

/*
	Error cases:
	1. on parsing:
	- Meet an char other than [0-9] + - / * or space
	- Meet an operand >= 10
	2. on caclulation
	- Meet an operator + - / * but there is less than 2 operands in stack
	- Division by 0
	- int overflow
	3. on reaching the end of expression
	- Number of operands in stack is not 1
*/
int main(int ac, char** av)
{
	std::stack<int> _stack;
	if (ac != 2) {
		std::cerr << "Usage: ./RPN <expression>\nExample: ./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << std::endl;
		return 2;
	}
	std::string s(av[1]);
	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
		if (*it == ' ') continue;
		else if (*it >= '0' && *it <= '9') {
			_stack.push(*it - '0');
		} else if (*it == '+' || *it == '-' || *it == '/' || *it == '*') {
			if (_stack.size() < 2) {
				std::cerr << "Error: incorrect RPN expression" << std::endl;
				return 1;
			}
			int first = _stack.top();
			_stack.pop();
			int second = _stack.top();
			_stack.pop();
			if (*it == '+') {
				_stack.push(second + first);
			} else if (*it == '-') {
				_stack.push(second - first);
			} else if (*it == '/') {
				if (second == 0) {
					std::cerr << "Error: division by 0" << std::endl;
				}
				_stack.push(second / first);
			} else if (*it == '*') {
				_stack.push(second * first);
			}
		} else {
			std::cerr << "Error: invalid character" << std::endl;
			return 1;
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error: incorrect RPN expression" << std::endl;
		return 1;
	}
	std::cout << _stack.top() << std::endl;
	/*
		loop through each char of the expression {
			if is space: skip char + continue;
			if invalid char: error
			else if isdigit:
				get index of the next space (i)
				if each char is NOT a digit (check with std::strtol and (*endptr == ' ' || *endptr == '\0'): error
				else:
					convert it to int
					if (int >= 10 ou int <= -10): error
					else: add int to stack
			else if is operand:
				if stack size < 2: error
				else if (operand is '/' and top == 0): error
				else:
					first = top(); pop()
					second = top(); pop();
					calculate (first operand second)
					if result is int overflow: error
					else: stack result
			increment by index of the next space (i)
		}
	*/
	return 0;
}
