#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractBits = 8;

// Constructors / Destructor

Fixed::Fixed(void): _rawBits(0) {}

Fixed::Fixed(const int i) {
	int64_t shifted = static_cast<int64_t>(i) << Fixed::_fractBits;
	this->_rawBits = static_cast<int>(shifted);
}

Fixed::Fixed(const float f) {
	this->_rawBits = roundf(f * (1 << Fixed::_fractBits));
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::~Fixed(void) {}

// Accessors

int	Fixed::getRawBits(void) const {
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw) {
	this->_rawBits = raw;
}

// Math utils

float	Fixed::toFloat( void ) const {
	float num = static_cast<float>(this->_rawBits);
	return (num / (1 << Fixed::_fractBits));
}

int		Fixed::toInt( void ) const {
	return (this->_rawBits >> Fixed::_fractBits);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() <= b.getRawBits() ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() <= b.getRawBits() ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a.getRawBits() >= b.getRawBits() ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() >= b.getRawBits() ? a : b);
}

// Operator overload (comparisions)

Fixed	&Fixed::operator=(const Fixed &right) {
	if (this != &right)
		this->_rawBits = right.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &right) const {
	return (this->_rawBits > right.getRawBits());
}

bool	Fixed::operator<(const Fixed &right) const {
	return (this->_rawBits < right.getRawBits());
}

bool	Fixed::operator>=(const Fixed &right) const {
	return (this->_rawBits >= right.getRawBits());
}

bool	Fixed::operator<=(const Fixed &right) const {
	return (this->_rawBits <= right.getRawBits());
}

bool	Fixed::operator==(const Fixed &right) const {
	return (this->_rawBits == right.getRawBits());
}

bool	Fixed::operator!=(const Fixed &right) const {
	return (this->_rawBits != right.getRawBits());
}

// Operator overload (maths)

Fixed	Fixed::operator+(const Fixed &right) const {
	Fixed res;
	res.setRawBits(this->_rawBits + right.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &right) const {
	Fixed res;
	res.setRawBits(this->_rawBits - right.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &right) const {
	Fixed res;
	res.setRawBits((this->_rawBits * right.getRawBits()) >> Fixed::_fractBits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &right) const {
	Fixed res;
	if (right.getRawBits() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return (res);
	}
	int64_t num = static_cast<int64_t>(this->_rawBits) << Fixed::_fractBits;
	res.setRawBits(static_cast<int>(num / right.getRawBits()));
	return (res);
}

// Operator overload (increment/decrement)

Fixed	&Fixed::operator++() {
	++this->_rawBits;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed cpy(*this);
	++this->_rawBits;
	return (cpy);
}

Fixed	&Fixed::operator--()
{
	--this->_rawBits;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed cpy(*this);
	--this->_rawBits;
	return (cpy);
}

// Streams overload (non-member method)

std::ostream	&operator<<(std::ostream &o, const Fixed &right)
{
	o << right.toFloat();
	return (o);
}
