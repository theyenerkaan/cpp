#include <iostream>
#include <fstream>
#include <string>

static std::string	performReplace(const std::string& content, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t		pos;
	size_t		lastPos;

	if (s1.empty())
		return content;
	
	lastPos = 0;
	pos = content.find(s1, lastPos);
	
	while (pos != std::string::npos)
	{
		result.append(content, lastPos, pos - lastPos);
		result.append(s2);
		lastPos = pos + s1.length();
		pos = content.find(s1, lastPos);
	}
	
	result.append(content, lastPos, content.length() - lastPos);
	
	return result;
}

int	main(int argc, char **argv)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		content;
	std::string		line;

	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	inFile.open(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}
	
	while (std::getline(inFile, line))
	{
		content.append(line);
		if (!inFile.eof())
			content.append("\n");
	}
	inFile.close();
	
	content = performReplace(content, s1, s2);
	
	outFile.open((filename + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not create output file" << std::endl;
		return 1;
	}
	
	outFile << content;
	outFile.close();
	
	return 0;
}
