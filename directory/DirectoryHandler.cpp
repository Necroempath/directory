#include "DirectoryHandler.h"
SuperVector<Directory*> DirectoryHandler::_directories = SuperVector<Directory*>(0);
SuperVector<Directory*> DirectoryHandler::_directoriesFiltered = SuperVector<Directory*>(0);



void DirectoryHandler::InitFilteredDirectoryVector(UI::MenuOption option, const string& searchParameter)
{
	size_t size = _directories.Size();

	switch (option)
	{
	case UI::NAME:
		for (size_t i = 0; i < size; i++)
		{
			if (_directories[i]->GetFirmName() == searchParameter && !(_directories[i]->GetFirmName() == "Unknown")) _directoriesFiltered.PushBack(_directories[i]);
		}
		break;
	case UI::OWNER:
		for (size_t i = 0; i < size; i++)
		{
			if (_directories[i]->GetOwner() == searchParameter && !(_directories[i]->GetOwner() == "Unknown")) _directoriesFiltered.PushBack(_directories[i]);
		}
		break;
	case UI::PHONE:
		for (size_t i = 0; i < size; i++)
		{
			if (_directories[i]->GetPhoneNumber() == searchParameter && !(_directories[i]->GetPhoneNumber() == "Unknown")) _directoriesFiltered.PushBack(_directories[i]);
		}
		break;
	case UI::ADDRESS:
		for (size_t i = 0; i < size; i++)
		{
			if (_directories[i]->GetAddress() == searchParameter && !(_directories[i]->GetAddress() == "Unknown")) _directoriesFiltered.PushBack(_directories[i]);
		}
		break;
	case UI::CAREER:
		for (size_t i = 0; i < size; i++)
		{
			if (_directories[i]->GetCareer() == searchParameter && !(_directories[i]->GetCareer() == "Unknown")) _directoriesFiltered.PushBack(_directories[i]);
		}
		break;
	}

}

string DirectoryHandler::ValidateInput(const string& string)
{
	if (!string.GetLen()) return "Unknown";
	return string;
}

Directory* DirectoryHandler::NewDirectory()
{
	string name = ValidateInput(UI::NameInput());
	string owner = ValidateInput(UI::OwnerInput());
	string phone = ValidateInput(UI::PhoneInput());
	string address = ValidateInput(UI::AddressInput());
	string career = ValidateInput(UI::CareerInput());

	return new Directory(name, owner, phone, address, career);
}


void DirectoryHandler::Launch()
{
	//_directories.PushBack(new Directory("Null & Void Inc.", "Seg Fault", "+1 404 000 0001", "0xDEADBEEF, Heap Sector 3", "Undefined behavior consultancy" ));
	//_directories.PushBack(new Directory("GhostPtr Systems", "Dangling Dave", "+1 314 000 2718", "Uninitialized Ln, Shadow Stack", "Smart pointer exorcism" ));
	//_directories.PushBack(new Directory("Race Condition Co.", "Valgrind Whisper", "+1 503 001 0002", "Parallel Blvd, Thread Hell", "Multithreaded debugging under stress" ));
	//_directories.PushBack(new Directory("The Leakery", "Memory Goulash", "+1 777 010 0200", "Lost Allocation Rd, Leak Town", "Long-term memory retention (accidental)" ));
	//_directories.PushBack(new Directory("Stack Overflowed", "Callie Recurse", "+1 800 999 0420", "Call Stack Loop, Level 666", "Recursion therapy center" ));
	//_directories.PushBack(new Directory("EvilCast Inc.", "reinterpret_demon", "+1 102 008 0048", "Bitfield Swamp, UB Forest", "Legacy C casting solutions" ));
	//_directories.PushBack(new Directory("Void Return Funeral Home", "Dr. Nothing", "+1 701 003 0701", "Segmentation St., Code Abyss", "Postmortem for non-returning functions"));
	//_directories.PushBack(new Directory("OffByOne", "Index Ripper", "+1 900 000 0009", "ArrayEnd Blvd, Boundsville", "Loop termination correction (with pain)"));
	//_directories.PushBack(new Directory("The Unaligned Ones", "Byte Misfit", "+1 300 010 0110", "Misaligned Memory Ave, Sector 7B", "Exotic architecture support"));
	//_directories.PushBack(new Directory("Destructor Cult", "SIGABRT Prophet", "+1 202 404 0815", "Object Graveyard, VTable Vault", "Custom destruction rituals for the cursed"));
	//
	//FileHandler::WriteToFile(fileName, _directories);

	FileHandler::ReadFromFile(fileName, _directories);
	string searchParameter;
	while (true)
	{
		switch (UI::Menu())
		{
		case UI::NAME:
			searchParameter = UI::PrintSearchParameter(UI::NAME);
			InitFilteredDirectoryVector(UI::NAME, searchParameter);
			UI::PrintFilteredDirectories(_directoriesFiltered);
			FileHandler::WriteLog(logName, "Firm name");
			break;
		case UI::OWNER:
			searchParameter = UI::PrintSearchParameter(UI::OWNER);
			InitFilteredDirectoryVector(UI::OWNER, searchParameter);
			UI::PrintFilteredDirectories(_directoriesFiltered);
			FileHandler::WriteLog(logName, "Owner");
			break;
		case UI::PHONE:
			searchParameter = UI::PrintSearchParameter(UI::PHONE);
			InitFilteredDirectoryVector(UI::PHONE, searchParameter);
			UI::PrintFilteredDirectories(_directoriesFiltered);
			FileHandler::WriteLog(logName, "Phone number");
			break;
		case UI::ADDRESS:
			searchParameter = UI::PrintSearchParameter(UI::ADDRESS);
			InitFilteredDirectoryVector(UI::ADDRESS, searchParameter);
			UI::PrintFilteredDirectories(_directoriesFiltered);
			FileHandler::WriteLog(logName, "Address");
			break;
		case UI::CAREER:
			searchParameter = UI::PrintSearchParameter(UI::CAREER);
			InitFilteredDirectoryVector(UI::CAREER, searchParameter);
			UI::PrintFilteredDirectories(_directoriesFiltered);
			FileHandler::WriteLog(logName, "Career");
			break;
		case UI::ALL:
			UI::PrintDirectories(_directories);
			break;
		case UI::ADD:
			_directories.PushBack(NewDirectory());
			FileHandler::WriteToFile(fileName, _directories);
			UI::PrintSuccessMsg();
			break;
		case UI::LOG:
		{
			string buffer;
			FileHandler::ReadLog(logName, buffer);
			UI::PrintLog(buffer);
			break;
		}
		case UI::EXIT:
			return;
		default:
			UI::InvalidInputMsg();
			break;
		}
		_directoriesFiltered.Resize(0);
	}
}

DirectoryHandler::~DirectoryHandler()
{
	for (size_t i = 0; i < _directories.Size(); i++)
	{
		delete _directories[i];
	}
}
