#pragma once
#include "FileHandler.h"
#define fileName "Directory.bin"
#define logName "log.txt"
class DirectoryHandler
{
	static SuperVector<Directory*> _directories;

	static SuperVector<Directory*> _directoriesFiltered;

	static void InitFilteredDirectoryVector(UI::MenuOption option, const string& searchParameter);

	static string ValidateInput(const string& string);

	static Directory* NewDirectory();
public:
	static void Launch();

	~DirectoryHandler();
};

