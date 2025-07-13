#include <iostream>
#include <algorithm>

int	main(int argc, char *argv[])
{
	std::string	str = "";
	if (argc > 1) {
		for (int i = 1; i < argc; i++)
			str += argv[i];
	}
	else
		str = "* Loud and unbearable feedback noise *";
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str << std::endl;
	return (0);
}