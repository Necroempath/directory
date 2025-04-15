#include "UI.h"

short UI::Menu()
{
	std::cout << "1. Search by name"
			<< "\n2. Search by owner"
			<< "\n3. Search by phone number"
			<< "\n4. Search by address"
			<< "\n5. Search by career"
			<< "\n6. Display all"
			<< "\n7. New Directory"
			<< "\n8. View Log"
			<< "\n9. Exit\n\n";

	short option;
	std::cin >> option;
	std::cin.ignore();

	return option;
}

string UI::NameInput()
{
	std::cout << "Type firm name:\t";
	char name[50];

	std::cin.getline(name, 50);
	return name;
}

string UI::OwnerInput()
{
	std::cout << "Type owner name:\t";
	char owner[50];
	
	std::cin.getline(owner, 50);
	return owner;
}

string UI::PhoneInput()
{
	std::cout << "Type phone number:\t";
	char phone[20];
	std::cin.getline(phone, 20);
	return phone;
}

string UI::AddressInput()
{
	std::cout << "Type address:\t";
	char address[100];
	std::cin.getline(address, 100);
	return address;
}

string UI::CareerInput()
{
	std::cout << "Type career field:\t";
	char career[50];
	std::cin.getline(career, 50);
	return career;
}

void UI::PrintError(const char* msg)
{
	std::cerr << msg;
}

void UI::InvalidInputMsg()
{
	std::cout << "Invalid input data\n";
}

void UI::PrintLog(const string log)
{
	std::cout << log << '\n';
}

void UI::PrintDirectories(SuperVector<Directory*> directories)
{
	for (size_t i = 0; i < directories.Size(); i++)
	{
		std::cout << "Firm Name:\t\t\t" << directories[i]->GetFirmName() << '\n'
			<< "Owner:\t\t\t\t" << directories[i]->GetOwner() << '\n'
			<< "Phone number:\t\t\t" << directories[i]->GetPhoneNumber() << '\n'
			<< "Address:\t\t\t" << directories[i]->GetAddress() << '\n'
			<< "Career:\t\t\t\t" << directories[i]->GetCareer() << "\n\n";

	}
}

void UI::PrintFilteredDirectories(SuperVector<Directory*> directories)
{
	if (!directories.Size()) std::cout << "No directories exist by given search parameter\n";
	else
	{
		std::cout << "\n========== Amount of matches: " << directories.Size() << " ==========\n\n";
		PrintDirectories(directories);
	}
}

string UI::PrintSearchParameter(const MenuOption option)
{
	switch (option)
	{
	case NAME:
		std::cout << "Enter firm name:\t";
		break;
	case OWNER:
		std::cout << "Enter owner:\t";
		break;
	case PHONE:
		std::cout << "Enter phone number:\t";
		break;
	case ADDRESS:
		std::cout << "Enter address:\t";
		break;
	case CAREER:
		std::cout << "Enter career:\t";
		break;
	}

	char temp[50];
	std::cin.getline(temp, 50);

	return temp;
}

void UI::PrintSuccessMsg()
{
	std::cout << "\nNew directory successfully added to file\n\n";
}
