#ifndef __CONTACT__
	#define __CONTACT__

	#include <iostream>
	#include <string>
	#include "../include/Struct.hpp"
	
	class Contact
	{
		private:
			std::string	_firstName;
			std::string	_lastName;
			std::string	_nickName;
			std::string _phoneNumber;
			std::string _darkestSecret;
		public:
			Contact(void);
			~Contact(void);
			void	SetContact(std::string fName, std::string lName,
			std::string nName, std::string pNumber, std::string dSecret);
			contactInfo	GetContact(void);
	};
	
#endif