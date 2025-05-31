#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{

	public:

		static const std::string levels[4];

		Harl(void);

		void complain( std::string level );

	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};

#endif
