#ifndef LOG_H
#define LOG_H

#include "WriteFile.h"
#include <bai>
#include <map>
#include <string>

class Log
{
private:
	Log();
	~Log();
	WriteFile wf;
	/*Fichier par default*/
	std::string file;
	std::string lastLog;
	bool includeDate;
	std::map<size_t, std::string> logTypes = { {0, "info"} , {1, "debug"} , {2, "trace"}, {3, "warning"}, {4, "error"}, {5, "fatal"} };


public:
	static Log& getInstance();
	void setFile(std::string file);
	void setIncludeDate(bool id);
	bool getIncludeDate();
	void writeLog(size_t type, std::string message);
	void writeLog(size_t type, std::string message, int value);
	void writeLog(size_t type, std::string message, bool value);
	void writeLog(size_t type, std::string message, double value);
	void writeLog(size_t type, std::string message, bai::PointReal point);
	bool isLastLog(std::string message);
	std::string findType(size_t type);
	void updateLog(std::string message);
	
};

#endif // !LOG_H