#include <iostream>
#include <cctype>

std::string	UppercaseConvert(const std::string &str)
{
	size_t		i;
	std::string	result;

	i = 0;
	while (i < str.length())
		result += static_cast<char>(std::toupper(str[i++]));
	return (result);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
		std::cout << UppercaseConvert(argv[i++]);
	std::cout << std::endl;
	return (0);
}