#pragma once

#include <iostream>

class Fixed
{

	public:

		Fixed(void);
		Fixed(const int intNb);
		Fixed(const float floatNb);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed	&operator=(const Fixed &right);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:

		int					_rawBits;
		static const int	_fractionalBits;

};

std::ostream	&operator<<(std::ostream &o, const Fixed &right);
