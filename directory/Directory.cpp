#include "Directory.h"

Directory::Directory() : _firmName(null), _owner(null), _phoneNumber(null), _career(null), _address(null) {};

Directory::Directory(const string& firmName, const string& owner, const string& phoneNumber, const string& career, const string& address)
    : _firmName(firmName), _owner(owner), _phoneNumber(phoneNumber), _address(career), _career(address) {};

#pragma region Accessors
string Directory::GetFirmName() const {
    return _firmName;
}

string Directory::GetOwner() const {
    return _owner;
}

string Directory::GetPhoneNumber() const {
    return _phoneNumber;
}

string Directory::GetAddress() const {
    return _address;
}

string Directory::GetCareer() const {
    return _career;
}
#pragma endregion

