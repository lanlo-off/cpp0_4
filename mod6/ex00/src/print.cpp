#include "../includes/ScalarConverter.hpp"
#include <sstream>
#include <cmath>

static bool isWholeNumber(double value)
{
	double integralPart;

	return (std::modf(value, &integralPart) == 0.0);
}

static std::string formatFloatValue(float value)
{
	std::ostringstream oss;

	if (isWholeNumber(static_cast<double>(value)))
		oss << std::fixed << std::setprecision(1) << value;
	else
		oss << std::setprecision(7) << value;
	return (oss.str());
}

/**
 * @brief Necessaire pour garder la precision (42.42f = 42.42 et pas 42.4)
 * 15 etant la precision max fiable des double, mais si c'est un entier on ne veut que 1
 * 
 * @param value 
 * @param fractionalPrecision 
 * @return std::string 
 */
static std::string formatDoubleValue(double value, int fractionalPrecision)
{
	std::ostringstream oss;

	if (isWholeNumber(value))
		oss << std::fixed << std::setprecision(1) << value;
	else
		oss << std::setprecision(fractionalPrecision) << value;
	return (oss.str());
}

//std::precision(1) definit le nombre de chiffres apres la virgule 
//(grace a std::fixed car sans lui ca definirait le nb de chiffres a afficher avant et apres la virgule)

void	printFromChar(char const& input)
{
	double val = static_cast<double>(input);
/*CHAR*/
	std::cout	<< "char: ";
	if (!std::isprint(static_cast<int>(input)))
		std::cout << "Non displayable\n";
	else
		std::cout	<< "'"
					<< static_cast<unsigned char>(input)
					<< "'"
					<< '\n';
/*INT*/
	std::cout	<< "int: "
				<< static_cast<int>(val)
				<< '\n';
/*FLOAT*/
	std::cout	<< "float: "
				<< formatFloatValue(static_cast<float>(val))
				<< "f"
				<< '\n';
/*DOUBLE*/
	std::cout	<< "double: "
				<< formatDoubleValue(val, 15)
				<< std::endl;
}

void	printFromInt(long& input)
{
	double val = static_cast<double>(input);//car overflow d'un double beaucoup plus loin qu'un long
/*CHAR*/
	std::cout	<< "char: ";
	if (input >= CHARMIN && input <= CHARMAX)
	{
		if (!std::isprint(static_cast<int>(input)))
			std::cout << "Non displayable\n";
		else
			std::cout	<< "'"
						<< static_cast<unsigned char>(input)
						<< "'"
						<< '\n';
	}
	else
		std::cout << "Impossible\n";
/*INT*/
	std::cout	<< "int: "
				<< static_cast<int>(input)
				<< '\n';
/*FLOAT*/
	std::cout	<< "float: ";
	if (val >= FMIN && val <= FMAX)
		std::cout	<< formatFloatValue(static_cast<float>(val))
					<< "f\n";
	else
		std::cout << "Impossible\n";
/*DOUBLE*/
	std::cout	<< "double: "
				<< formatDoubleValue(val, 15)
				<< std::endl;
}

void	printFromFloat(float& input)
{
	double val = static_cast<double>(input);//car overflow d'un double beaucoup plus loin qu'un float
/*CHAR*/
	std::cout	<< "char: ";
	if (input >= CHARMIN && input <= CHARMAX)
	{
		if (!std::isprint(static_cast<int>(input)))
			std::cout << "Non displayable\n";
		else
			std::cout	<< "'"
						<< static_cast<unsigned char>(input)
						<< "'"
						<< '\n';
	}
	else
		std::cout << "Impossible\n";
/*INT*/
	std::cout	<< "int: ";
	if (val >= INTMIN && val <= INTMAX)
		std::cout << static_cast<int>(input) << '\n';
	else
		std::cout << "Impossible\n";
/*FLOAT*/
	std::cout	<< "float: "
				<< formatFloatValue(static_cast<float>(val))
				<< "f\n";
/*DOUBLE*/
	std::cout	<< "double: "
				<< formatDoubleValue(val, 7)
				<< std::endl;
}

void	printFromDouble(double& input)
{
/*CHAR*/
	std::cout	<< "char: ";
	if (input >= CHARMIN && input <= CHARMAX)
	{
		if (!std::isprint(static_cast<int>(input)))
			std::cout << "Non displayable\n";
		else
			std::cout	<< "'"
						<< static_cast<unsigned char>(input)
						<< "'"
						<< '\n';
	}
	else
		std::cout << "Impossible\n";
/*INT*/
	std::cout	<< "int: ";
	if (input >= INTMIN && input <= INTMAX)
		std::cout << static_cast<int>(input) << '\n';
	else
		std::cout << "Impossible\n";
/*FLOAT*/
	std::cout	<< "float: ";
	if (input >= FMIN && input <= FMAX)
		std::cout	<< formatFloatValue(static_cast<float>(input))
					<< "f\n";
	else
		std::cout << "Impossible\n";
/*DOUBLE*/
	std::cout	<< "double: "
				<< formatDoubleValue(input, 15)
				<< std::endl;
}

void	printFromSpecial(std::string const& input)
{
	float	f;
	double	d;

	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		f = std::strtof(input.c_str(), NULL);
		d = static_cast<double>(f);
	}
	else
	{
		d = std::strtod(input.c_str(), NULL);
		f = static_cast<float>(d);
	}
	std::cout	<< "char: Impossible\n"
				<< "int: Impossible\n"
				<< "float: "
				<< (f >= 0 ? "+" : "")
				<< f << "f"
				<<"\ndouble: "
				<< (d >= 0 ? "+" : "")
				<< d
				<< std::endl;
}