#ifndef __STRUCT__
	#define __STRUCT__

	#include <iostream>
	#include <string>

	typedef struct s_contactInfo
	{
		std::string	firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string	darkestSecret;
	}	contactInfo;
	

#endif