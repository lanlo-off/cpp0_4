#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(void) {
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void) {
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	this->_btcDatabase = other._btcDatabase;
	return (*this);
}

static std::string	&trim(std::string &str) {
	while ((str.size() > 0) && (std::isspace((unsigned char)str[0])))
		str.erase(0, 1);
	while ((str.size() > 0) && (std::isspace((unsigned char)str[str.size() - 1])))
		str.erase(str.size() - 1, 1);
	return (str);
}

static void	getDateVal(const std::string &date, int *year, int *month, int *day) {
	std::string	datetrim(date);
	datetrim = trim(datetrim);

	std::stringstream	ssDate(datetrim), ssYear, ssMonth, ssDay;
	std::stringstream	*ssPtrs[3] = {&ssYear, &ssMonth, &ssDay};
	std::string			strGetVal;
	int					*valPtrs[3] = {year, month, day};
	size_t				i;

	if (datetrim.size() == 0 || datetrim[0] == '-' || datetrim[datetrim.size() - 1] == '-')
		throw (BitcoinExchange::InvalidDateValueException());
	for (i = 0; (i < 3) && getline(ssDate, strGetVal, '-'); i++) {
		if ((i > 0) && (strGetVal.size() != 2))
			throw (BitcoinExchange::InvalidDateValueException());
		for (size_t j = 0; j < strGetVal.size(); j++) {
			if (!isdigit(strGetVal[j]))
				throw (BitcoinExchange::InvalidDateValueException());
		}
		*ssPtrs[i] << strGetVal;
		*ssPtrs[i] >> *valPtrs[i];
		if ((*ssPtrs[i]).fail())
			throw (BitcoinExchange::InvalidDateValueException());
	}
	if (i != 3 || getline(ssDate, strGetVal, '-'))
		throw (BitcoinExchange::InvalidDateValueException());
}

static float	getFloatVal(const std::string &str) {
	std::string	strtrim(str);
	strtrim = trim(strtrim);

	size_t	i = (strtrim[0] == '+' || strtrim[0] == '-') ? 1 : 0;
	bool	bFoundPoint = (strtrim[i] == '.');
	while (i < strtrim.size()) {
		if (!isdigit(strtrim[i])) {
			if ((strtrim[i] == '.') && (!bFoundPoint) && (i != strtrim.size() - 1))
				bFoundPoint = true;
			else
				throw (BitcoinExchange::InvalidFloatValueException());
		}
		i++;
	}
	
	std::stringstream	ssFloat;
	float				val;
	ssFloat << strtrim;
	ssFloat >> val;
	if (ssFloat.fail())
		throw (BitcoinExchange::InvalidFloatValueException());
	return (val);
}

static bool	isValidDate(const std::string &date) {
	int					year, month, day;
	static int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

	try {
		getDateVal(date, &year, &month, &day);
		if (year < 0 || month < 1 || month > 12 || day <= 0)
			return (false);
		
		bool isBissextile = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
		if (month == 2 && isBissextile)
			return day <= 29;
		return (day <= daysInMonth[month - 1]);
	}
	catch (std::exception &e) {}
	return (false);
}

static bool	isValidFloat(const std::string &str) {
	try {
		getFloatVal(str);
		return (true);
	}
	catch (std::exception &e) {}
	return (false);
}

void	BitcoinExchange::loadDatabase(const std::string &database) {
	std::ifstream	fData;

	fData.open(database.c_str());
	if (!fData || !fData.is_open() || fData.fail())
		throw (BitcoinExchange::DatabaseOpenFailException());

	std::string	line, date, rate;
	while (getline(fData, line)) {
		std::stringstream	ssLine(line);
		if (getline(ssLine, date, ',') && getline(ssLine, rate)
			&& isValidDate(date) && isValidFloat(rate))
			this->_btcDatabase[date] = getFloatVal(rate);
	}

	fData.close();
}

static float	getBtcRate(const std::string &date, const std::map<std::string, float> &data) {
	std::map<std::string, float>::const_iterator	iteData = data.end();
	std::map<std::string, float>::const_iterator	found = data.find(date);
	if (found != iteData)
		return (found->second);

	std::map<std::string, float>::const_iterator	itData = data.begin();
	float									rate = itData->second;
	
	while ((itData != iteData) && (date > itData->first)) {
		rate = itData->second;
		itData++;
	}
	return (rate);
}

void	BitcoinExchange::readInput(const std::string &input) const {
	std::ifstream	fInput;

	fInput.open(input.c_str());
	if (!fInput || !fInput.is_open() || fInput.fail())
		throw (BitcoinExchange::InputOpenFailException());
	if (this->_btcDatabase.empty()) {
		fInput.close();
		throw (BitcoinExchange::NoDataException());
	}

	std::string	line, date, val;
	bool		bValidDate, bValidFloat, bFirstLine = true;
	float		Value;
	while (getline(fInput, line)) {
		if ((!bFirstLine) || (line != "date | value")) {
			std::stringstream	ssLine(line);
			if (getline(ssLine, date, '|') && getline(ssLine, val)) {
				date = trim(date);
				val = trim(val);
				bValidDate = isValidDate(date);
				bValidFloat = isValidFloat(val);
				if (bValidFloat)
					Value = getFloatVal(val);
				if (bValidDate && bValidFloat && ((Value >= 0) && (Value <= 1000))) {
					std::cout << date << " -> " << Value << " = "
					<< getBtcRate(date, this->_btcDatabase) * Value << '\n';
				}
				else {
					std::cout << "\e[0m" "\e[3m" "Error:";
					if (!bValidDate)
						std::cout << " \"" << date << "\" is not a valid date.";
					if (!bValidFloat)
						std::cout << " \"" << val << "\" is not a valid value.";
					else if (Value < 0)
						std::cout << " Value " << Value << " is negative.";
					else if (Value > 1000)
						std::cout << " Value " << Value << " is OVER 1 000.";
					std::cout << "\e[0m" << '\n';
				}
			}
			else
				std::cout << "\e[0m" "\e[3m" "Error: malformed or incomplete line: "
				"expected \"date | value\"." "\e[0m" << '\n';
		}
		bFirstLine = false;
	}
	
	fInput.close();
}



const char*	BitcoinExchange::DatabaseOpenFailException::what(void) const throw() {
	return ("Cannot open database file.");
};

const char*	BitcoinExchange::InvalidDateValueException::what(void) const throw() {
	return ("Invalid value in date.");
};

const char*	BitcoinExchange::InvalidFloatValueException::what(void) const throw() {
	return ("Value is not a float.");
};

const char*	BitcoinExchange::InputOpenFailException::what(void) const throw() {
	return ("Cannot open input file.");
};

const char*	BitcoinExchange::NoDataException::what(void) const throw() {
	return ("No usable data was found.");
};