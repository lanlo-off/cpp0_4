#include "Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	this->_value = n << this->_fractional;
	return ;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	_value = roundf(num * (1 << _fractional));
	return ;
}

Fixed::Fixed(Fixed const & model)
{
	std::cout << "Copy constructor called\n";
	this->operator=(model);
	return ;
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
}

std::ostream & operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed &Fixed::operator=(Fixed const &base)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &base)
		std::cout << "Copy assignment operator called on himself\n";
	else
		this->_value = base._value;
	return (*this);
}

bool Fixed::operator>(Fixed const & other)
{
	return (toFloat() > other.toFloat());
}

bool Fixed::operator>=(Fixed const & other)
{
	return (toFloat() >= other.toFloat());
}

bool Fixed::operator<(Fixed const & other)
{
	return (toFloat() < other.toFloat());
}

bool Fixed::operator<=(Fixed const & other)
{
	return (toFloat() <= other.toFloat());
}

bool Fixed::operator==(Fixed const & other)
{
	return (toFloat() == other.toFloat());
}

bool Fixed::operator!=(Fixed const & other)
{
	return (toFloat() != other.toFloat());
}

Fixed Fixed::operator+(Fixed const &other)
{
	Fixed res;
	long val;

	val = _value + other._value;
	res.setRawBits((int)val);
	return (res);
}

Fixed Fixed::operator-(Fixed const &other)
{
	Fixed res;
	long val;

	val = _value - other._value;
	res.setRawBits((int)val);
	return (res);
}

Fixed Fixed::operator*(Fixed const &other)
{
	Fixed res;
	long val;

	val = _value * other._value;
	val = val >> _fractional;
	res.setRawBits((int)val);
	return (res);
}

Fixed Fixed::operator/(Fixed const &other)
{
	Fixed	res;
	float	val;

	if (other._value == 0)
	{
		val = 0;
		std::cout << "Division by 0 is dangerous\nLet's set the result to 0\n";
	}
	else 
		val = (_value << _fractional) / (other._value << _fractional);
	res.setRawBits((int)val);
	return (res);
}

/**
 * @brief //Pour le ++i -> 
 * Incremente la variable puis la renvoie 
 * (on renvoie donc une reference a l'objet depuis lequel a ete appelee la fonction
 * et pas un nouvel objet)
 * 
 * @return Fixed& 
 */
Fixed &Fixed::operator++(void)
{
	_value++;
	return (*this);
}

/**
 * @brief //pour i++
 * renvoie la variable inchangee 
 * (donc on doit faire une copie de la variable depuis laquelle
 * on a appele la fonction
 * puis incremente la variable d'origine, ce qui ne modifie pas la copie
 * on renvoie un Fixed = la copie de la variable 
 * 
 * @return Fixed 
 */
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	_value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	_value--;
	return (tmp);
}

Fixed & Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs._value <= rhs._value)
		return (lhs);
	return (rhs);
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs <= rhs)
	// if (lhs._value < rhs._value)
		return (lhs);
	return (rhs);
	
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (lhs._value <= rhs._value)
		return (rhs);
	return (lhs);
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs <= rhs)
	// if (lhs._value < rhs._value)
		return (rhs);
	return (lhs);
	
}