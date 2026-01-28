#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	int	_value;
	static const int	_fractional;

public:
	Fixed(void);//constructor
	Fixed(const int n);
	Fixed(const float num);
	Fixed(Fixed const & model);//Copy constructor
	Fixed & operator=(Fixed const &base);//copy assignment operator overload
	~Fixed(void);//destructeur

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream & operator<<(std::ostream &o, Fixed const & rhs);

#endif