#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>

class Span {

	private : 
		unsigned int _size;
		std::vector<int> _tab;

	public :

		Span(unsigned int n);
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &copy);

		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end) {

			size_t distance = std::distance(begin, end);
			if (_tab.size() + distance > _size)
				throw TabIsFull();
			_tab.insert(_tab.end(), begin, end);
		}

	class TabIsFull : public std::exception {
		public :
			virtual const char *what() const throw();
	};

	class NotEnoughInt : public std::exception {
		public :
			virtual const char *what() const throw();
	};
} ;

#endif