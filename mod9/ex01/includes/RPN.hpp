#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <exception>
# include <stack>
# include <list>

class RPN {

public:

	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN	&operator=(const RPN &other);

	int	RPNOperate(const std::string &expression);

	class MissingSpaceException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class InvalidArgumentException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class OperatingOnEmptyException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class IncompleteExpressionException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class EmptyExpressionException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class DivByZeroException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

private:

	std::stack< int, std::list<int> >	_rpnStack;

};

#endif
