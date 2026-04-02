/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:45:13 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/13 10:35:07 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <stack>
#include <limits>
#include <sstream>
#include <stdexcept>

#include "RPN.hpp"

template <char op> struct Operator
{
		static int reduce(int a, int b);
};

template <> struct Operator<'+'>
{
		static int reduce(int a, int b)
		{
			if ((b > 0 && a > std::numeric_limits<int>::max() - b)
				|| (b < 0 && a < std::numeric_limits<int>::min() - b))
				throw std::overflow_error(std::string("addition ")
										  + (b > 0 ? "overflow" : "underflow"));
			return a + b;
		}
};

template <> struct Operator<'-'>
{
		static int reduce(int a, int b)
		{
			if ((a > 0 && b > std::numeric_limits<int>::max() - a)
				|| (a < 0 && b < std::numeric_limits<int>::min() - a))
				throw std::overflow_error(std::string("subtraction ")
										  + (a > 0 ? "overflow" : "underflow"));
			return a - b;
		}
};

template <> struct Operator<'*'>
{
		static int reduce(int a, int b)
		{
			if (b
				&& (a > std::numeric_limits<int>::max() / b
					|| a < std::numeric_limits<int>::min() / b))
				throw std::overflow_error(std::string("multiplication ")
										  + (a > 0 ? "overflow" : "underflow"));
			return a * b;
		}
};

template <> struct Operator<'/'>
{
		static int reduce(int a, int b)
		{
			if (!b || (a == std::numeric_limits<int>::min() && b == -1))
				throw std::overflow_error("division overflow");
			return a / b;
		}
};

RPN::RPN(void)
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& rhs)
{
	(void)rhs;
	return *this;
}

RPN::~RPN(void)
{
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream				 ss(expression);
	std::stack<int, std::list<int> > stack;
	std::string						 token;

	while (ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			stack.push(static_cast<int>(token[0] - '0'));
		else if (token.length() == 1
				 && std::string("+-*/").find(token[0]) != std::string::npos)
		{
			if (stack.size() < 2)
				throw std::runtime_error(
						"cannot apply operand with less than two numbers.");
			int rhs = stack.top();
			stack.pop();
			int lhs = stack.top();
			stack.pop();
			switch (token[0])
			{
				case '+':
					stack.push(Operator<'+'>::reduce(lhs, rhs));
					break;
				case '-':
					stack.push(Operator<'-'>::reduce(lhs, rhs));
					break;
				case '*':
					stack.push(Operator<'*'>::reduce(lhs, rhs));
					break;
				case '/':
					stack.push(Operator<'/'>::reduce(lhs, rhs));
					break;
				default:
					throw std::runtime_error("'" + token
											 + "' is an invalid operand.");
			}
		}
		else
			throw std::runtime_error("'" + token + "' is an invalid operand.");
	}
	if (stack.size() != 1)
		throw std::runtime_error("expression is not equilibrated.");
	return stack.top();
}
