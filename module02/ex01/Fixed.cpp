#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractBits = 8;

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = intNb << this->_fractBits;
}

Fixed::Fixed(const float realNb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = roundf(realNb * (1 << this->_fractBits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &right)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &right)
		this->_rawBits = right.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_rawBits / (1 << this->_fractBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_rawBits >> this->_fractBits);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &right)
{
	o << right.toFloat();
	return (o);
}
