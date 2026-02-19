#include "../includes/ScalarConverter.hpp"

bool isInt(const std::string& s)
{
	size_t i = 0;

	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i == s.length())
		return false;//signe sans chiffre
	for (; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

bool isFloat(const std::string& s)
{
	bool dotFound = false;
	size_t i = 0;
	
	if (s.find('.') == std::string::npos || s[s.length() - 1] != 'f')
		return false;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (; i < s.length() - 1; i++)//On s'arrête avant le 'f'
	{
		if (s[i] == '.')
		{
			if (dotFound) 
				return false;//Deux points
			dotFound = true;
		}
		else if (!isdigit(s[i]))
			return false;
	}
	return true;
}

bool isDouble(const std::string& s)
{
	bool dotFound = false;
	size_t i = 0;

	if (s.find('.') == std::string::npos)
		return false;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			if (dotFound)
				return false;
			dotFound = true;
		}
		else if (!isdigit(s[i]))
			return false;
	}
	return true;
}

/**
 * @brief On va parser l'input et s'il est valide renvoyer le type de la valeur.
 * 
 * @param input 
 * @return double 
 */
Type	parseInput(std::string const& input)
{
	if (input.length() == 0)
		return (INVALID);
	if (input.length() == 1 && !isdigit(input[0]))
		return (CHAR);
	if (input == "-inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "nan")
		return (SPECIAL);
	if (isInt(input))
		return (INT);
	if (isFloat(input))
		return (FLOAT);
	if (isDouble(input))
		return (DOUBLE);
	return (INVALID);
}

void ScalarConverter::convert(std::string const& input)
{
	Type type = parseInput(input);
	long l;
	float f;
	double d;
	errno = 0;

	switch (type)
	{
	case CHAR:
		return (printFromChar(input[0]));
	case INT:
		l = std::strtol(input.c_str(), NULL, 10);//ca mieux que atol car set errno
		if (errno == ERANGE || l < INTMIN || l > INTMAX)
			break;
		return (printFromInt(l));//on l'envoie en long et on fera la conversion plus tard pour overflow
	case FLOAT:
		f = std::strtof(input.c_str(), NULL);
		if (errno == ERANGE)
			break;
		return (printFromFloat(f));
	case DOUBLE:
		d = std::strtod(input.c_str(), NULL);
		if (errno == ERANGE)
			break;
		return (printFromDouble(d));
	case SPECIAL:
		return (printFromSpecial(input));
	default:
		break;
	}
	if (type == INVALID)
		std::cout << "The type is unknown" << std::endl;
	else
		std::cout <<"The type was recognized as " << type << ". But you submitted a value that overflow this type" << std::endl;
}