#include "phonebook.hpp"


void	short_str(std::string to_print)
{
	std::cout << " | ";
	if (to_print.size() < 10)
		std::cout << to_print;
	else
    {
		to_print.resize(9);
		std::cout << to_print << ".";
    }
}


void getInput(std::string prompt, std::string& field) {
    std::cout << prompt << std::endl;
    std::cin >> field;
    while (field.size() < 10)
        field.append(" ");
}

// • ADD: save a new contact
// ◦ If the user enters this command, they are prompted to input the information
// of the new contact one field at a time. Once all the fields have been completed,
// add the contact to the phonebook.
// ◦ The contact fields are: first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
void    addContact(Phonebook& Pb)
{
    system("clear");
	std::cout << "ADD New Contact"<< std::endl;
			
	for (int i = 7; i > 0; i--)
        Pb.Cons[i] = Pb.Cons[i - 1];
	
    getInput("First name ->", Pb.Cons[0].first_name);
    getInput("Last name ->", Pb.Cons[0].last_name);
    getInput("Nickname ->", Pb.Cons[0].nickname);
    getInput("Phone number: ->", Pb.Cons[0].phone_number);
    getInput("Darkest Secret ->", Pb.Cons[0].darkest_secret);
	system("clear");

	if (Pb.index < 8)
		Pb.index++;
}

// • SEARCH: display a specific contact
// ◦ Display the saved contacts as a list of 4 columns: index, first name, last
// name and nickname.
// ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
// them. The text must be right-aligned. If the text is longer than the column,
// it must be truncated and the last displayable character must be replaced by a
// dot (’.’).
// ◦ Then, prompt the user again for the index of the entry to display. If the index
// is out of range or wrong, define a relevant behavior. Otherwise, display the
// contact information, one field per line.
void    searchContact(Phonebook& Pb)
{
    int selector;

	for (int i = 0; i < Pb.index; i++)
	{
		std::cout << i + 1;
		short_str(Pb.Cons[i].first_name);
		short_str(Pb.Cons[i].last_name);
		std::cout << " | " << std::endl;
	}
	std::cin >> selector;
	selector--;
	system("clear");
	if (selector < Pb.index && selector >= 0)
	{
		std::cout << Pb.Cons[selector].first_name << std::endl;
		std::cout << Pb.Cons[selector].last_name << std::endl;
		std::cout << Pb.Cons[selector].nickname << std::endl;
		std::cout << Pb.Cons[selector].phone_number << std::endl;
		std::cout << Pb.Cons[selector].darkest_secret << std::endl;
	}
	else
	{
		std::cout << "invalid" << std::endl;
	}
}

int main(void)
{
    Phonebook   Pb;
    Pb.index = 0;
    std::string command;
    
	system("clear");
    while (1)
	{
		std::cout << "ADD (1) | SEARCH (2) | EXIT (3)" << std::endl;
		std::cin >> command;
		if(std::cin.eof())
		{
        	std::cout << "\nClosed input." << std::endl;
        	return 0;
    	}
        if (command == "ADD" || command == "1")
            addContact(Pb);
        else if (command == "SEARCH" || command == "2")
            searchContact(Pb);
        else if (command == "EXIT" || command == "3")
            return 0;
    }
}

// • EXIT
// ◦ The program quits and the contacts are lost forever!
// • Any other input is discarded.
// Once a command has been correctly executed, the program waits for another one. It
// stops when the user inputs EXIT