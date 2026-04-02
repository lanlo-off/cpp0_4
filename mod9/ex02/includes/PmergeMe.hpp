#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>
# include <exception>

class PmergeMe {

public:

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe	&operator=(const PmergeMe &other);

	void	push_to_cont(const std::string &num);
	void	display_vector() const;
	void	display_deque() const;

	void	sortVector();
	void	sortDeque();

	void	sortCheckVector() const;
	void	sortCheckDeque() const;

	class InvalidValueException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class NegativeIntException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class BadSortException : public std::exception {
		public:
			virtual const char	*what() const throw();
	};

private:

	std::vector<int>	_sortVector;
	std::deque<int>		_sortDeque;

};

#endif
