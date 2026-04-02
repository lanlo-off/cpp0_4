/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubois <ldubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:43:48 by ldubois           #+#    #+#             */
/*   Updated: 2026/03/16 20:37:03 by ldubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

#include "ansi.hpp"
#include "AbsolutelyNotAVector.hpp"
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _rates(other._rates), _amounts(other._amounts)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		_rates = rhs._rates;
		_amounts = rhs._amounts;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

const std::multimap<std::string, double>& BitcoinExchange::getAmounts(
		void) const
{
	return _amounts;
}

const std::map<std::string, double>& BitcoinExchange::getRates(void) const
{
	return _rates;
}

static void dateValidator(const std::string& date)
{
	std::istringstream				  ss(date);
	AbsolutelyNotAVector<std::string> tokens;
	std::string						  token;
	char*							  end;

	while (std::getline(ss, token, '-'))
		tokens.push_back(token);
	if (tokens.size() != 3 || tokens[0].size() != 4 || tokens[1].size() != 2
		|| tokens[2].size() != 2)
		throw std::runtime_error("must be in YYYY-MM-DD");

	unsigned long year = std::strtoul(tokens[0].c_str(), &end, 10);
	if (end == tokens[0].c_str() || *end)
		throw std::runtime_error("'" + tokens[0] + "' is not a valid year");
	unsigned long month = std::strtoul(tokens[1].c_str(), &end, 10);
	if (end == tokens[1].c_str() || *end || month == 0 || month > 12)
		throw std::runtime_error("'" + tokens[1] + "' is not a valid month");
	unsigned long day = std::strtoul(tokens[2].c_str(), &end, 10);
	if (end == tokens[2].c_str() || *end || day == 0
		|| day > (month == 2
						  ? 28 + (!(year % 4) && (year % 100 || !(year % 400)))
						  : ((month % 2 == (month <= 7)) ? 31 : 30)))
		throw std::runtime_error("'" + tokens[2] + "' is not a valid day");
}

static std::string trimWhitespace(const std::string& str)
{
	const std::string	   charset = " \t\n\r\f\v";
	std::string::size_type start = str.find_first_not_of(charset);
	std::string::size_type end = str.find_last_not_of(charset);

	if (start == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

static bool isWhitespace(char c)
{
	return std::isspace(static_cast<unsigned char>(c));
}

void BitcoinExchange::loadRate(const std::string& record)
{
	std::istringstream				  ss(record);
	AbsolutelyNotAVector<std::string> tokens;
	std::string						  token;
	char*							  end;

	while (std::getline(ss, token, ','))
		tokens.push_back(trimWhitespace(token));
	if (tokens.size() != 2)
		throw std::runtime_error("invalid row");
	const std::string& date = tokens[0];
	const std::string& value = tokens[1];
	try
	{
		dateValidator(date);
	}
	catch (const std::exception& e)
	{
		throw std::runtime_error("'" + date
								 + "' is not a valid date: " + e.what());
	}
	double rate = std::strtod(value.c_str(), &end);
	if (end == value.c_str() || *end)
		throw std::runtime_error("'" + value + "' is not a valid rate");
	if (_rates.find(date) != _rates.end())
		throw std::runtime_error("duplicated entry");
	_rates[date] = rate;
}

void BitcoinExchange::loadRates(const std::string& filename)
{
	std::ifstream infile(filename.c_str());
	std::string	  line;

	if (!infile)
		throw std::runtime_error("'" + filename + "' could not be opened.");
	if (!std::getline(infile, line))
		throw std::runtime_error("empty database");
	line.erase(std::remove_if(line.begin(), line.end(), isWhitespace),
			   line.end());
	if (line != "date,exchange_rate")
		throw std::runtime_error("'" + line + "' is not a valid header");
	for (std::size_t index = 2; std::getline(infile, line); ++index)
	{
		std::ostringstream os;
		try
		{
			os << index;
			loadRate(line);
		}
		catch (const std::exception& e)
		{
			throw std::runtime_error(filename + ": line " + os.str() + ": "
									 + e.what() + ".");
		}
	}
}

void BitcoinExchange::loadAmount(const std::string& record)
{

	std::istringstream				  ss(record);
	AbsolutelyNotAVector<std::string> tokens;
	std::string						  token;
	char*							  end;

	while (std::getline(ss, token, '|'))
		tokens.push_back(trimWhitespace(token));
	if (tokens.size() != 2)
		throw std::runtime_error("must contain only date and amount");
	const std::string& date = tokens[0];
	const std::string& value = tokens[1];
	try
	{
		dateValidator(date);
	}
	catch (const std::exception& e)
	{
		throw std::runtime_error("'" + date
								 + "' is not a valid date: " + e.what());
	}
	double amount = std::strtod(value.c_str(), &end);
	if (end == value.c_str() || *end || amount < 0.0 || amount > 1000.0)
		throw std::runtime_error("'" + value + "' is not a valid amount");
	if (date < _rates.begin()->first)
		throw std::runtime_error("'" + date
								 + "' is before first exchange rate");
	_amounts.insert(std::make_pair(date, amount));
}

void BitcoinExchange::loadAccount(const std::string& filename)
{
	std::ifstream infile(filename.c_str());
	std::string	  line;

	if (!infile)
		throw std::runtime_error("'" + filename + "' could not be opened.");
	if (!std::getline(infile, line))
		throw std::runtime_error("empty database");
	line.erase(std::remove_if(line.begin(), line.end(), isWhitespace),
			   line.end());
	if (line != "date|value")
		throw std::runtime_error("'" + line + "' is not a valid header");
	for (std::size_t index = 2; std::getline(infile, line); ++index)
	{
		std::ostringstream os;
		try
		{
			os << index;
			loadAmount(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << ANSI_BOLD << ANSI_FG_RED << "Error: " << ANSI_RESET
					  << (filename + ": line " + os.str()
						  + ": invalid row: " + e.what() + ".\n")
					  << ANSI_RESET;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& rhs)
{
	const std::multimap<std::string, double>& amounts = rhs.getAmounts();
	const std::map<std::string, double>&	  rates = rhs.getRates();
	double									  prev = 0.0;

	out << "┌────────────┬────────────┬────────────┬────────────┐\n";
	out << "│    Date    │  Position  │  Value ($) │   Yield    │\n";
	out << "├────────────┼────────────┼────────────┼────────────┤\n";
	for (std::multimap<std::string, double>::const_iterator it
		 = amounts.begin();
		 it != amounts.end(); ++it)
	{
		std::ostringstream os;
		const std::string& date = it->first;
		const double	   position = it->second;
		const double value = position * (--rates.upper_bound(date))->second;
		const double yield
				= (prev != 0.0 ? ((value - prev) / prev) * 100 : 100.0);

		out << "│" << std::setw(12) << date;
		os << std::fixed << std::setprecision(1) << position << "₿";
		out << "│" << std::setw(14) << os.str();
		os.str("");
		os << std::fixed << std::setprecision(0) << value << "$";
		out << "│" << std::setw(12) << os.str();
		os.str("");
		os << std::fixed << std::setprecision(0)
		   << (yield > 0.0 ? ANSI_FG_GREEN "+" : ANSI_FG_RED) << yield << "%"
		   << ANSI_RESET;
		out << "│" << std::setw(21) << os.str() << "│\n";
		os.str("");
		prev = value;
	}
	out << "└────────────┴────────────┴────────────┴────────────┘\n";
	return out;
}
