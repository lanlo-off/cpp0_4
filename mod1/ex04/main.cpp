#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "./replace filename str1 str2 to launch the program" << std::endl;
		return (1);
	}
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error : could not open infile in read mode\n";
		return (1);
	}

	std::ofstream outfile(filename.append(".replace").c_str());
	if (!outfile)
	{
		infile.close();
		std::cerr << "Error : could not open outfile in write mode\n";
		return (1);
	}

	std::string line;
	std::string content;
	while (std::getline(infile, line))//on remplit content ligne par ligne
	{
		content += line;//pareil que content.append(line)
		if (!infile.eof())
			content += '\n';
	}

	size_t	pos = content.find(s1);
	while (pos != std::string::npos)//npos = valeur retournee par find si on trouve pas d'occurrence
	{
		std::string left = content.substr(0, pos);
		std::string right = content.substr(pos + s1.size());
		content = left + s2 + right;
		pos = content.find(s1);
	}
	outfile << content;
	infile.close();
	outfile.close();//inutile car le destructeur des ifstream et ofstream close deja apparemment
	return (0) ;
}