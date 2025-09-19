#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	std::string line;

	std::ifstream open_file("input.txt");
	if (open_file.is_open())
	{
		while (std::getline(open_file, line))
		{
			std::cout << line << std::endl;
		}
	}
	open_file.close();


	return EXIT_SUCCESS;
}