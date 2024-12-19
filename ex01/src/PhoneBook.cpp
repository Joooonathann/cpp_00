#include "../include/PhoneBook.hpp"
#include "../include/Struct.hpp"
#include <iomanip>
#include <sstream>


PhoneBook::PhoneBook(void)
{
	this->totalContact = 0;
}

PhoneBook::~PhoneBook(void)
{
}

int     is_full_space(std::string str)
{
    size_t a = 0;

    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
            a++;
    }
    return (a == str.length() ? 1 : 0);
}

int     is_not_number(std::string str)
{
    for (size_t i = 0; str[i]; i++)
    {
        if (!std::isdigit(str[i]))
            return (1);
    }
    return (0);
}

bool is_printable_fd(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isprint(str[i])) {
            return (false);
        }
    }
    return (true);
}

bool is_spaceno(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r') {
            return (false);
        }
    }
    return (true);
}

void	PhoneBook::AddContact(void)
{
	int			i;
	std::string	fields[] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
    std::string	info[5];

	i = 0;
	while (i < 5)
	{
		std::cout << "Enter " << fields[i] << ": ";
        std::getline(std::cin, info[i]);
		if (std::cin.eof() == true)
		{
			std::cout << std::endl;
			return ;
		}
		if (info[i].empty() || is_full_space(info[i]))
            std::cout << "Error: " << fields[i] << " cannot be empty." << std::endl;
        else if (i == 3 && is_not_number(info[i]))
            std::cout << "Error: " << fields[i] << " can only contain numbers." << std::endl;
        else if (!is_printable_fd(info[i]))
            std::cout << "Error: " << fields[i] << " cannot contain non printable character." << std::endl;
        else if (!is_spaceno(info[i]))
            std::cout << "Error: " << fields[i] << " cannot contain white-space." << std::endl;
		else
			i++;
	}
	_contacts[totalContact % 8].SetContact(info[0], info[1], info[2], info[3], info[4]);
	std::cout << "Contact added successfully!" << std::endl;
    totalContact++;
}

std::string FormatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::SearchContact(void)
{
	int index;
    std::string input;

    if (this->totalContact == 0)
    {
        std::cout << "No contacts available.\n";
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";
    std::cout << std::string(44, '-') << "\n";
    for (int i = 0; i < this->totalContact && i < 8; i++)
    {
        contactInfo contact = this->_contacts[i].GetContact();
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << FormatField(contact.firstName) << "|"
                  << std::setw(10) << FormatField(contact.lastName) << "|"
                  << std::setw(10) << FormatField(contact.nickName) << "\n";
    }
    index = -1;
    std::cout << "\nEnter the index of the contact to display: ";
    std::getline(std::cin, input);
    std::istringstream(input) >> index;
    if (index < 0 || index >= this->totalContact || index >= 8 || is_not_number(input))
    {
        std::cout << "Invalid index. Please try again.\n";
        return;
    }
    contactInfo selected = this->_contacts[index].GetContact();
    std::cout << "\nContact Details:\n";
    std::cout << "First Name: " << selected.firstName << "\n";
    std::cout << "Last Name: " << selected.lastName << "\n";
    std::cout << "Nickname: " << selected.nickName << "\n";
    std::cout << "Phone Number: " << selected.phoneNumber << "\n";
    std::cout << "Darkest Secret: " << selected.darkestSecret << "\n";
}