#include <iostream>
#include <fstream>
#include <string>
#include <vector>


double solver(std::string line)
{

	std::vector<double> numbers{};
	std::vector<char> all_types_operator{ '/', '+', '-', '*' };

	std::string tek;

	for (char s : line)
	{
		if (std::isdigit(s))
		{
			tek += s;
		}
		else
		{
			try
			{
				numbers.push_back(std::stoi(tek));
			}
			catch (...) {}
			tek = "";

			if (s == '+' or s == '-' or s == '*' or s == '/')
			{
				if (s == '+')
				{
					numbers[numbers.size() - 2] = numbers[numbers.size() - 2] + numbers[numbers.size() - 1];
					numbers.pop_back();
				}
				else if (s == '-')
				{
					numbers[numbers.size() - 2] = numbers[numbers.size() - 2] - numbers[numbers.size() - 1];
					numbers.pop_back();
				}
				else if (s == '*')
				{
					numbers[numbers.size() - 2] = numbers[numbers.size() - 2] * numbers[numbers.size() - 1];
					numbers.pop_back();
				}
				else
				{
					numbers[numbers.size() - 2] = numbers[numbers.size() - 2] / numbers[numbers.size() - 1];
					numbers.pop_back();
				}
			}
		}
	}

	std::cout << numbers[0] << std::endl;
	return numbers[0];
}




int main(int argc, char* argv[])
{
	std::string line;

	std::ifstream open_file("input.txt");
	std::ofstream out("output.txt", std::ios::trunc);
	if (open_file.is_open())
	{
		while (std::getline(open_file, line))
		{
			std::cout << line << std::endl;
			out << line + " = " + std::to_string(solver(line)) << std::endl;
		}
	}
	open_file.close();


	return EXIT_SUCCESS;
}