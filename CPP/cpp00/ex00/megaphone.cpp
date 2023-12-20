#include <iostream>

int main(int argc, char **argv)
{
	std::string outputstr;

	for (int i = 0; i < argc - 1; i++)
	{
		outputstr = argv[i];
		for (char &c : outputstr)
			c = std::toupper(c);
		std::cout << outputstr << std::endl;
	}
	return 0;
}
