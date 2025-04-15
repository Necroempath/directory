#pragma once
#define null "Unknown"
#include "string.h"
class Directory
{
private:
	string _firmName;
	string _owner;
	string _phoneNumber;
	string _address;
	string _career;

public:
	Directory();

	Directory(const string& firmName, const string& owner, const string& phoneNumber, const string& career, const string& address);

#pragma region Accessors
	string GetFirmName() const;
	string GetOwner() const;
	string GetPhoneNumber() const;
	string GetAddress() const;
	string GetCareer() const;
#pragma endregion

};
