/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:14:28 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/27 16:14:38 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN(void) {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::~RPN(void) {}

RPN	&RPN::operator=(const RPN &other) {
	this->_rpnStack = other._rpnStack;
	return (*this);
}

static int	rpnAdd(int n1, int n2) {
	return (n1 + n2);
}

static int	rpnSubstract(int n1, int n2) {
	return (n1 - n2);
}

static int	rpnMultiply(int n1, int n2) {
	return (n1 * n2);
}

static int	rpnDivide(int n1, int n2) {
	if (n2 == 0)
		throw(RPN::DivByZeroException());
	return (n1 / n2);
}

static int	rpnModulo(int n1, int n2) {
	if (n2 == 0)
		throw(RPN::DivByZeroException());
	return (n1 % n2);
}

int	RPN::rpnOperate(const std::string &expression) {
	std::stringstream	ssOp(expression);
	std::string			strArg;
	std::string			sOperators = "+-*/%";
	int					(*doOperation[5])(int n1, int n2) = {&rpnAdd, &rpnSubstract, &rpnMultiply, &rpnDivide, &rpnModulo};
	int					num;

	while (ssOp >> strArg) {
		if (strArg.size() > 1)
			throw (RPN::MissingSpaceException());
		if (std::isdigit(strArg[0]))
			this->_rpnStack.push(strArg[0] - '0');
		else if (sOperators.find(strArg[0]) != std::string::npos) {
			if (this->_rpnStack.size() <= 1)
				throw (RPN::OperatingOnEmptyException());
			num = this->_rpnStack.top();
			this->_rpnStack.pop();
			for (size_t i = 0; i < 5; i++) {
				if (strArg[0] == sOperators[i])
					this->_rpnStack.top() = doOperation[i](this->_rpnStack.top(), num);
			}
		}
		else
			throw (RPN::InvalidArgumentException());
	}
	if (this->_rpnStack.size() > 1)
		throw (RPN::IncompleteExpressionException());
	if (this->_rpnStack.empty())
		throw (RPN::EmptyExpressionException());
	return (this->_rpnStack.top());
}
