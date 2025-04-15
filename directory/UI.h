#pragma once
#include <iostream>
#include "vector.h"
#include "string.h"
#include "Directory.h"
class UI
{
public:
	enum MenuOption
	{
		NAME = 1,
		OWNER,
		PHONE,
		ADDRESS,
		CAREER,
		ALL,
		ADD,
		LOG,
		EXIT
	};

	static short Menu();

	static string NameInput();

	static string OwnerInput();

	static string PhoneInput();

	static string AddressInput();

	static string CareerInput();

	static string PrintSearchParameter(const MenuOption option);

	static void PrintSuccessMsg();

	static void PrintError(const char* msg);

	static void InvalidInputMsg();

	static void PrintLog(const string log);

	static void PrintDirectories(SuperVector<Directory*> directories);

	static void PrintFilteredDirectories(SuperVector<Directory*> directories);
};

