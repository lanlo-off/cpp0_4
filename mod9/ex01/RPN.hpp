/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:14:48 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/27 16:15:04 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <exception>
# include <stack>
# include <list>

class RPN {

public:

	//Constructors
	RPN(void);
	RPN(const RPN &other);
	//Destructor
	~RPN(void);
	// = Operator overload (very confusing in this case I know)
	RPN	&operator=(const RPN &other);

	//RPN Operation member function
	int	rpnOperate(const std::string &expression);

	//Exceptions
	class MissingSpaceException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Missing space between two arguments.");
			};
	};

	class InvalidArgumentException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Invalid argument in expression.");
			};
	};

	class OperatingOnEmptyException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Attempted operation on an empty stack.");
			};
	};

	class IncompleteExpressionException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Missing operators in expression.");
			};
	};

	class EmptyExpressionException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Try writing something next time.");
			};
	};

	class DivByZeroException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Division by zero. Lmao.");
			};
	};

private:

	std::stack< int, std::list<int> >	_rpnStack;

};

#endif
