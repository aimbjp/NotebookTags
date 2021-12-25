#pragma once
#include <fstream>
#include <string>
#include <Windows.h>


class Note
{
	std::string path; 
public:
	static bool CreateNote(std::string path = "-1");
	static std::ofstream OpenNoteForWrite(std::string path = "-1");
	static bool DeleteNote(std::string path = "-1");
	//static void RenameNote(std::string name, std::string newName);
};

int NumberFiles(std::string dir, std::string prefix, std::string extension);
bool FileExistenceCheck(const std::string& name);
std::string toStandardString(System::String^ string);

