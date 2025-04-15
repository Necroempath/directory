#pragma once
#include <fstream>
#include "string.h"
#include "UI.h"
#include "vector.h"
#include "Directory.h"
class FileHandler
{
private:
	static void WriteFieldToFile(const string& str, std::ofstream& fout);

	static string ReadFromFieldToFile(std::ifstream& fin);
public:
	static void WriteToFile(const char* fileName, const SuperVector<Directory*>& directories);

	static void ReadFromFile(const char* fileName, SuperVector<Directory*>& directories);

	static void WriteLog(const char* fileName, const string& msg);

	static void ReadLog(const char* fileName, string& buffer);
};

