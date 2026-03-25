#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>

class NoddleNotFound : public std::exception {

	public :
		virtual const char *what() const throw() {
			return "Element not found in container";
		}
} ;


template <typename T>
typename T::iterator easyfind(T &container, int toFind) {
	
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NoddleNotFound();
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int toFind) {
	
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NoddleNotFound();
	return it;
}

#endif