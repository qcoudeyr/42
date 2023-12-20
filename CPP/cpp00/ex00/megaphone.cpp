#include <iostream>

int main(int argc, char **argv)
{
	std::string outputstr;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 0; i < argc - 1; i++)
	{
		for (int x; argv[i][x] != 0; x++)
			outputstr[x] = std::toupper(argv[i][x]);
		std::cout << outputstr << std::endl;
	}
	return 0;
}
