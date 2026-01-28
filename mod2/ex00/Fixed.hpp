#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
private:
	int	_value;
	static const int	_fractional;

public:
	Fixed(void);//constructor
	Fixed(Fixed const & model);//Copy constructor
	Fixed & operator=(Fixed const &base);//copy assignment operator overload
	~Fixed(void);//destructeur

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif