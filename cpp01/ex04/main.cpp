#include <iostream>
#include <fstream>
#include <sstream>

static bool setIFStream(std::ifstream& ifs, char* infile, std::string& content)
{
	std::stringstream	buffer;

	ifs.open(infile);
	if (!ifs.is_open())
		return (false);
	buffer << ifs.rdbuf();
	content = buffer.str();
	return (true);
}

static bool setOFStream(std::ofstream& ofs, char *infile,std::string const& fileExt)
{
	std::string	const outFile = std::string(infile) + fileExt;

	ofs.open(outFile.c_str());
	if (!ofs.is_open())
		return (false);
	return (true);
}

static void searchAndReplace(std::string &content, std::string const& search,
	std::string const& replace)
{
	std::size_t 		pos = 0;
	std::size_t const	search_len = search.length();
	std::size_t const	replace_len = replace.length();

	if (search_len == 0)
		return;
	while (true)
	{
		pos = content.find(search, pos);
		if (pos == std::string::npos)
			break;
		content.erase(pos, search_len);
		content.insert(pos, replace);
		pos += replace_len;
	}
}

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		content;

	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments. "
			<< "Usage: ./sed <file> <s1> <s2>" << std::endl;
		return (1);
	}
	if (!setIFStream(ifs, argv[1], content))
	{
		std::cerr << "Unable to open input file" << std::endl;
		return (1);
	}
	if (!setOFStream(ofs, argv[1], ".replace"))
	{
		std::cerr << "Unable to create output file" << std::endl;
		return (1);
	}
	searchAndReplace(content, argv[2], argv[3]);
	ofs << content;
	ofs.close();
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