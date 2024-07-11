#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        std::string nickname;
        std::string darkest_secret;

    void    getContact(void)
    {
        std::cout << nickname << " | " << phone_number << std::endl;
    }
};

class Phonebook
{
    public:
    Contact Cons[8];
    int index;
};



#endif