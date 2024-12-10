#include "../include/Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::SetContact(std::string fName, std::string lName,
	std::string nName, std::string pNumber, std::string dSecret)
{
	this->_firstName = fName;
	this->_lastName = lName;
	this->_nickName = nName;
	this->_phoneNumber = pNumber;
	this->_darkestSecret = dSecret;
}

contactInfo	Contact::GetContact(void)
{
	contactInfo	result;

	result.firstName = this->_firstName;
	result.lastName = this->_lastName;
	result.nickName = this->_nickName;
	result.phoneNumber = this->_phoneNumber;
	result.darkestSecret = this->_darkestSecret;
	return (result);
}
