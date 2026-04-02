#include "../includes/RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::~RPN() {}

RPN	&RPN::operator=(const RPN &other) {
	_rpnStack = other._rpnStack;
	return (*this);
}

static int	RPNAdd(int n1, int n2) {
	return (n1 + n2);
}

static int	RPNSubtract(int n1, int n2) {
	return (n1 - n2);
}

static int	RPNMultiply(int n1, int n2) {
	return (n1 * n2);
}

static int	RPNDivide(int n1, int n2) {
	if (n2 == 0)
		throw(RPN::DivByZeroException());
	return (n1 / n2);
}


int	RPN::RPNOperate(const std::string &expression) {
	std::stringstream	ssOp(expression);
	std::string			strArg;
	std::string			Operators = "+-*/";
	int					(*doOperation[4])(int n1, int n2) = {&RPNAdd, &RPNSubtract, &RPNMultiply, &RPNDivide};
	int					num;

	while (ssOp >> strArg) {
		if (strArg.size() > 1)
			throw (RPN::MissingSpaceException());
		if (std::isdigit(strArg[0]))
			_rpnStack.push(strArg[0] - '0');
		else if (Operators.find(strArg[0]) != std::string::npos) {
			if (_rpnStack.size() <= 1)
				throw (RPN::OperatingOnEmptyException());
			num = _rpnStack.top();
			_rpnStack.pop();
			for (size_t i = 0; i < 4; i++) {
				if (strArg[0] == Operators[i])
					_rpnStack.top() = doOperation[i](_rpnStack.top(), num);
			}
		}
		else
			throw (RPN::InvalidArgumentException());
	}
	if (_rpnStack.size() > 1)//Si en sortie de boucle il me reste + que 1 truc dans la stack c'est qu'il y avait une formule invalide de base
		throw (RPN::IncompleteExpressionException());
	if (_rpnStack.empty())
		throw (RPN::EmptyExpressionException());
	return (_rpnStack.top());
}


const char*	RPN::MissingSpaceException::what() const throw() {
	return ("Missing space between two arguments.");
};

const char*	RPN::InvalidArgumentException::what() const throw() {
	return ("Invalid argument in expression.");
};

const char*	RPN::OperatingOnEmptyException::what() const throw() {
	return ("Attempted operation on an empty stack.");
};

const char*	RPN::IncompleteExpressionException::what() const throw() {
	return ("Missing operators in expression.");
};

const char*	RPN::EmptyExpressionException::what() const throw() {
	return ("Empty argument.");
};

const char*	RPN::DivByZeroException::what() const throw() {
	return ("Division by zero. Dangerous !");
};
