#include <iostream>
#include <string>
#include <cstdlib>
#include "./include/PhoneBook.hpp"

void	PrintBanner(void)
{
	system("clear");
	std::cout << "\nWelcome to your PhoneBook.\n\n";
	std::cout << "You can use the following commands: \n";
	std::cout << "• ADD: register a new contact.\n";
	std::cout << "• SEARCH: displays the requested contact.\n";
	std::cout << "• EXIT: The program exits.\n";
	std::cout << std::endl;
}

bool is_printable(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isprint(str[i])) {
            return (false);
        }
    }
    return (true);
}

void	PrintPrompt(std::string &command)
{
	std::cout << std::getenv("USER") << ": ";
    std::getline(std::cin, command);
}

int main(void)
{
	PhoneBook	phone;
	std::string	command;
	bool		run;

	run = true;
	PrintBanner();
	while (run)
	{
    	PrintPrompt(command);
		if (std::cin.eof() == true)
		{
			std::cout << "Exiting PhoneBook now." << std::endl;
			return (0);
		}
		if (is_printable(command))
		{
			if (command == "ADD")
				phone.AddContact();
			if (command == "SEARCH")
				phone.SearchContact();
			if (command == "EXIT")
				run = false;
		}
    }
	return (0);
}