/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollock <cpollock@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:54:25 by cpollock          #+#    #+#             */
/*   Updated: 2026/01/23 10:54:36 by cpollock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <exception>
# include <string>

class BitcoinExchange {

public:

	//Constructors
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);

	//Destructor
	~BitcoinExchange(void);
	
	// = Operator overload
	BitcoinExchange	&operator=(const BitcoinExchange &other);

	//Load file
	void	loadDatabase(const std::string &database);
	//Read file
	void	readInput(const std::string &input) const;

	//Exceptions
	class DatabaseOpenFailException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Cannot open database file.");
			};
	};

	class InvalidDateValueException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Invalid value in date.");
			};
	};

	class InvalidFloatValueException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Value is not a float.");
			};
	};

	class InputOpenFailException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("Cannot open input file.");
			};
	};

	class NoDataException : public std::exception {
		public:
			virtual const char	*what(void) const throw() {
				return ("No usable data was found.");
			};
	};

private:

	std::map<std::string, float>	_btcDatabase;

};

#endif
