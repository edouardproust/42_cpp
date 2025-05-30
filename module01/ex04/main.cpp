#include <iostream>
#include <fstream>
#include <sstream>

bool searchAndReplace(char *filename, std::string &content,
	std::string const& search, std::string const& replace)
{
	std::size_t pos = 0;

	std::string outFile = std::string(filename) + ".replace";
	std::ofstream ofs(outFile.c_str());
	if (!ofs)
		return (false);
	while (true)
	{
		pos = content.find(search, pos);
		if (pos == std::string::npos)
			break;
		content.erase(pos, search.length());
		content.insert(pos, replace);
		pos += replace.length();
	}
	ofs << content;
	ofs.close();
	return (true);
}

int main(int argc, char **argv)
{
	std::stringstream buffer;
	std::string content;

	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments. ";
		std::cerr << "Usage: ./sed <file> <s1> <s2>" << std::endl;
		return (1);
	}
	std::ifstream ifs(argv[1]);
	if (!ifs)
	{
		std::cerr << "Unable to open file for reading" << std::endl;
		return (1);
	}
	buffer << ifs.rdbuf();
	content = buffer.str();
	if (!searchAndReplace(argv[1], content, argv[2], argv[3]))
	{
		std::cerr << "Unable to open file for writing" << std::endl;
		return (1);
	}
	ifs.close();
	return (0);
}

/*
Command: ./sed test sad happy

Content of file `test`:

I woke up feeling sad, the rain tapping against the window like it understood my mood.
It was a sad day, not just because of the weather, but because everything felt wrong.
The empty streets looked sad, the gray sky hung low, and even the birds seemed too sad to sing.
As I sat alone in the café, sipping cold coffee, I couldn't help but think how sad it is to be
circled by people and still feel so alone.
*/