#include "Note.h"

const std::string dir = "..\\Notes\\", prefix = "Note", extension = ".txt";

bool Note::CreateNote(std::string path)
{
	int i = NumberFiles(dir, prefix, extension);

	try
	{
		if (path == "-1")
		{
			std::ofstream note;
			note.open(dir + prefix + std::to_string(i) + extension);
			note.close();
		}
	}
	catch (std::exception)
	{
		return false;
	}

	return true;
}

bool Note::DeleteNote(std::string path)
{
	try
	{
		remove((dir + path).c_str());
		return true;
	}
	catch (std::exception)
	{
		return false;
	}
}

bool FileExistenceCheck(const std::string& name) 
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

int NumberFiles(std::string dir, std::string prefix, std::string extension)
{
	int returnedCount = 0;
	int possibleMax = 9999999;
	
	for (int istarter = 1; istarter < possibleMax; istarter++) {
		std::string fileName = "";
		fileName.append(dir + prefix + std::to_string(istarter) + extension);
		bool status = FileExistenceCheck(fileName);

		returnedCount = istarter;

		if (!status)
		{
			break;
		}
	}
	return returnedCount;
}

std::ofstream Note::OpenNoteForWrite(std::string path)
{
	std::ofstream note;
	note.open(dir + path, std::ios::out | std::ios::trunc); //Open with clearing prev. info
	return note;
}

std::string toStandardString(System::String^ string)
{
	using System::Runtime::InteropServices::Marshal;
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);

	return returnString;
}


