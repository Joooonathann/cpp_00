#ifndef __PHONEBOOK__
	#define __PHONEBOOK__

	#include "../include/Contact.hpp"

	class PhoneBook
	{
		private:
			int		totalContact;
			Contact _contacts[8];
		public:
			PhoneBook(void);
			~PhoneBook(void);
			void	AddContact(void);
			void	SearchContact(void);
	};
	

#endif