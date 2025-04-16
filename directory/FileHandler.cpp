#define _CRT_SECURE_NO_WARNINGS
#include "FileHandler.h"
#include <chrono>
void FileHandler::WriteFieldToFile(const string& str, std::ofstream& fout)
{
	size_t size = str.GetLen();

	fout.write(reinterpret_cast<const char*>(&size), sizeof(size));

	fout.write(str.c_str(), size);
}

string FileHandler::ReadFromFieldToFile(std::ifstream& fin)
{
	size_t size = 0;

	fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));

	char* temp = new char[size];
	
	fin.read(temp, size);

	string str = temp;

	delete[] temp;

	return str;
}

void FileHandler::WriteToFile(const char* fileName, const SuperVector<Directory*>& directories)
{
	try
	{
		std::ofstream fout(fileName, std::ios::binary);

		if (!fout.is_open()) throw std::runtime_error("Can not open file");

		size_t size = directories.Size();

		fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));

		for (size_t i = 0; i < size; i++)
		{

			WriteFieldToFile(directories[i]->GetFirmName(), fout);
			WriteFieldToFile(directories[i]->GetOwner(), fout);
			WriteFieldToFile(directories[i]->GetPhoneNumber(), fout);
			WriteFieldToFile(directories[i]->GetAddress(), fout);
			WriteFieldToFile(directories[i]->GetCareer(), fout);

			if(!fout) throw std::runtime_error("Error writing to file");
		}

		fout.close();
	}
	catch (const std::runtime_error& e)
	{
		UI::PrintError(e.what());
	}	
}

void FileHandler::ReadFromFile(const char* fileName, SuperVector<Directory*>& directories)
{
	try
	{
		std::ifstream fin(fileName, std::ios::binary);

		if (!fin.is_open()) throw std::runtime_error("Can not open file");
		
		size_t size = 0;

		fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));

		directories.Resize(size);

		for (size_t i = 0; i < size; i++)
		{
			string name = ReadFromFieldToFile(fin);
			string owner = ReadFromFieldToFile(fin);
			string phone = ReadFromFieldToFile(fin);
			string address = ReadFromFieldToFile(fin);
			string career = ReadFromFieldToFile(fin);

			if (!fin) throw std::runtime_error("Error reading to file");

			directories[i] = new Directory(name, owner, phone, address, career);
		}
		
		fin.close();
	}
	catch (const std::runtime_error& e)
	{
		UI::PrintError(e.what());
	}
}

void FileHandler::WriteLog(const char* fileName, const string& msg)
{
	try
	{
		std::ofstream fout(fileName, std::ios::app);

		if (!fout.is_open()) throw std::runtime_error("Can not open file");

		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm* now_tm = std::localtime(&now_c);

		fout << "["
			<< (now_tm->tm_mday < 10 ? "0" : "") << now_tm->tm_mday << '.'
			<< (now_tm->tm_mon + 1 < 10 ? "0" : "") << (now_tm->tm_mon + 1) << '.'
			<< (now_tm->tm_year + 1900) << " | "
			<< (now_tm->tm_hour < 10 ? "0" : "") << now_tm->tm_hour << ':'
			<< (now_tm->tm_min < 10 ? "0" : "") << now_tm->tm_min << ':'
			<< (now_tm->tm_sec < 10 ? "0" : "") << now_tm->tm_sec << "] ";

		fout << "Search by " << msg << '\n';
	}
	catch (const std::runtime_error& e)
	{
		UI::PrintError(e.what());
	}
}

void FileHandler::ReadLog(const char* fileName, string& buffer)
{
	try
	{
		std::ifstream fin(fileName);

		if (!fin.is_open()) throw std::runtime_error("Can not open log file");

		char line[256];

		while (fin.getline(line, 256))
		{
			buffer += line;
			buffer += "\n";
		}

		fin.close();
	}
	catch (const std::runtime_error& e)
	{
		UI::PrintError(e.what());
	}
}
