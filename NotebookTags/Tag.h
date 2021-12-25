#pragma once
#include <fstream>
#include <chrono>
#include <Windows.h>


class MyTag
{
	std::string name;
	std::chrono::system_clock::time_point date;
public:
	std::string GetName() { return name; };
	std::chrono::system_clock::time_point GetDate() { return date; };

	void SetDate(std::chrono::system_clock::time_point date) { this->date = date; };
	void SetName(std::string name) { this->name = name; };

	static void DeleteTag(std::string name);
};

class ImportantTag : public MyTag
{
public:
	ImportantTag() 
	{
		SetName("Important");
		SetDate(std::chrono::system_clock::now());
	}
	static void CreateTag(std::string name);

};

class WorkTag : public MyTag
{
public:
	WorkTag() 
	{
		SetName("Work");
		SetDate(std::chrono::system_clock::now());
	}
	static void CreateTag(std::string name);
};

std::string dateTimeToString(std::chrono::system_clock::time_point time);



