#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	int	_value;
	static const int	_fractional;

public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float num);
	Fixed(Fixed const & model);
	~Fixed(void);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
	Fixed & operator=(Fixed const &base);

	bool operator>(Fixed const &other);//Verifier si on prefere reflechir en value ou en toFloat !!
	bool operator>=(Fixed const &other);//Passer tous les operateurs de comparaison en const (apres fct) pour pouvoir les utiliser dans les min et max
	bool operator<(Fixed const &other);
	bool operator<=(Fixed const &other);
	bool operator==(Fixed const &other);
	bool operator!=(Fixed const &other);

	Fixed operator+(Fixed const &other);
	Fixed operator-(Fixed const &other);
	Fixed operator*(Fixed const &other);
	Fixed operator/(Fixed const &other);

	Fixed & operator++(void);
	Fixed operator++(int);
	Fixed & operator--(void);
	Fixed operator--(int);

	Fixed & min(Fixed & lhs, Fixed & rhs);//pq on peut pas utiliser les operateurs definis avant ici ??
	Fixed const & min(Fixed const & lhs, Fixed const & rhs);
	Fixed & max(Fixed & lhs, Fixed & rhs);
	Fixed const & max(Fixed const & lhs, Fixed const & rhs);

};

std::ostream & operator<<(std::ostream &o, Fixed const & rhs);

#endif