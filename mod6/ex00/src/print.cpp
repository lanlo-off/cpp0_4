#include "../includes/ScalarConverter.hpp"

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
	std::cout	<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val)
				<< "f"
				<< '\n';
/*DOUBLE*/
	std::cout	<< "double: "
				<< val
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
		std::cout	<< std::fixed << std::setprecision(1) << static_cast<float>(val)
					<< "f\n";
	else
		std::cout << "Impossible\n";
/*DOUBLE*/
	std::cout	<< "double: "
				<< val
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
				<< std::fixed << std::setprecision(1) << static_cast<float>(val)
				<< "f\n";
/*DOUBLE*/
	std::cout	<< "double: "
				<< val
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
		std::cout	<< std::fixed << std::setprecision(1) << static_cast<float>(input)
					<< "f\n";
	else
		std::cout << "Impossible\n";
/*DOUBLE*/
	std::cout	<< "double: "
				<< input
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
		f = static_cast<double>(d);
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