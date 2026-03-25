/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:24:45 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/28 13:25:18 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>
# include <exception>

class PmergeMe {

public:

	//Constructors
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	//Destructor
	~PmergeMe(void);
	// = Operator overload
	PmergeMe	&operator=(const PmergeMe &other);

	//Push numbers to both containers
	void	push_to_cont(const std::string &num);
	//Display container contents
	void	display_vector(void) const;
	void	display_deque(void) const;

	//Sorting
	void	sortVector(void);
	void	sortDeque(void);

	//Sort check
	void	sortCheckVector(void) const;
	void	sortCheckDeque(void) const;

	//Exceptions
	class InvalidValueException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Invalid value in sequence.");
			};
	};

	class NegativeIntException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Negative int in sequence.");
			};
	};

	class BadSortException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Sequence was not sorted!");
			};
	};

private:

	std::vector<int>	_sortVector;
	std::deque<int>		_sortDeque;

};

#endif
