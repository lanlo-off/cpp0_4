#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <exception>
# include <string>

class BitcoinExchange {

public:

	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange(void);
	BitcoinExchange	&operator=(const BitcoinExchange &other);

	void	loadDatabase(const std::string &database);
	void	readInput(const std::string &input) const;

	class DatabaseOpenFailException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};

	class InvalidDateValueException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};

	class InvalidFloatValueException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};

	class InputOpenFailException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};

	class NoDataException : public std::exception {
		public:
			virtual const char	*what(void) const throw();
	};

private:

	std::map<std::string, float>	_btcDatabase;

};

#endif
