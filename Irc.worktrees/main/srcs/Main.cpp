#include "Main.hpp"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "usage: " << argv[0] << " <port> <password>" << std::endl;
		return (EXIT_FAILURE);
	}

	Server	server(atoi(argv[1]), argv[2]);

	server.init();
	server.loop();

	return (EXIT_SUCCESS);
}
