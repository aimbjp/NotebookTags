#include "Tag.h"

const std::string Path = "..\\Tags\\";

void ImportantTag::CreateTag(std::string name)
{
	std::ofstream tag;
    ImportantTag newTag;
	tag.open(Path + name, std::ios::out | std::ios::trunc);
	tag << newTag.ImportantTag::GetName() << '\n' << dateTimeToString(newTag.ImportantTag::GetDate());
}

void WorkTag::CreateTag(std::string name)
{
    std::ofstream tag;
    WorkTag newTag;
    tag.open(Path + name, std::ios::out | std::ios::trunc);
    tag << newTag.WorkTag::GetName() << '\n' << dateTimeToString(newTag.WorkTag::GetDate());
}

std::string dateTimeToString(std::chrono::system_clock::time_point time) 
{
    time_t now_c = std::chrono::system_clock::to_time_t(time);
    auto tm = localtime(&now_c);
    char buffer[32];
    strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", tm);
    return std::string(buffer);
}

void MyTag::DeleteTag(std::string name)
{
    std::string file_name = Path + name;
    remove(file_name.c_str());
}


