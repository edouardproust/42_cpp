#pragma once

class Fixed
{

	private:

		int					_rawBits;
		static const int	_fractBits;

	public:

		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed	&operator=(const Fixed &right);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};