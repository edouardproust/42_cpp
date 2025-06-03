#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

	private:

		int					_rawBits;
		static const int	_fractBits;

	public:

		// Constructors / Destructor
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &src);
		~Fixed(void);

		// Accessors
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Math manipulations
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed		&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);

		// Operator overload
		Fixed	&operator=(const Fixed &right);
		bool	operator>(const Fixed &right) const;
		bool	operator<(const Fixed &right) const;
		bool	operator>=(const Fixed &right) const;
		bool	operator<=(const Fixed &right) const;
		bool	operator==(const Fixed &right) const;
		bool	operator!=(const Fixed &right) const;
		Fixed	operator+(const Fixed &right) const;
		Fixed	operator-(const Fixed &right) const;
		Fixed	operator*(const Fixed &right) const;
		Fixed	operator/(const Fixed &right) const;
		Fixed	&operator++(); //pre-increment
		Fixed	operator++(int); //post-increment
		Fixed	&operator--(); //pre-decrement
		Fixed	operator--(int); //post-decrement
};

// Streams overload
std::ostream	&operator<<(std::ostream &o, const Fixed &right);

#endif
