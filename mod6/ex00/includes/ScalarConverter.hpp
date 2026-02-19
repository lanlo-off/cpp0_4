#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>//pour set precision
#include <cstdlib>//strtod
#include <cerrno>//pour double overflow
#include <limits>//limites

#define CHARMIN std::numeric_limits<char>::min()
#define CHARMAX std::numeric_limits<char>::max()
#define INTMIN std::numeric_limits<int>::min()
#define INTMAX std::numeric_limits<int>::max()
// #define FMIN std::numeric_limits<float>::min()//celle-ci renvoie la valeur la plus proche de 0 qui existe
#define FMIN -std::numeric_limits<float>::max()//car lowest n'existe pas en c++98 pour float
#define FMAX std::numeric_limits<float>::max()
// #define DMIN std::numeric_limits<double>::min()
#define DMIN std::numeric_limits<double>::lowest()
#define DMAX std::numeric_limits<double>::max()

void	printFromChar(char const& input);
void	printFromInt(long& input);
void	printFromFloat(float& input);
void	printFromDouble(double& input);
void	printFromSpecial(std::string const& input);

typedef enum e_type
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
}	Type;

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

public:
	static void convert(std::string const& input);
};




#endif