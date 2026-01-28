#include "Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(const int n)//pq ca suffit pas de faire _value(n) ??????
{
	std::cout << "Int constructor called\n";
	this->_value = n << this->_fractional;//pq les this-> sont facultatifs ?
	return ;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	_value = roundf(num * 256);
	return ;
}

Fixed::Fixed(Fixed const & model)
{
	std::cout << "Copy constructor called\n";
	this->operator=(model);
	return ;
}

Fixed &Fixed::operator=(Fixed const &base)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &base)
		std::cout << "Copy assignment operator called on himself\n";
	else
		this->_value = base.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractional);
}

float	Fixed::toFloat(void) const
{
	return (_value / (float)(1 << _fractional));
	// return (_value / 256.0f);
}

std::ostream & operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
