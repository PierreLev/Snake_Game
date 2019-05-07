#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <string>
#include <fstream>

class WriteFile
{

private:
	std::fstream file;
	
public:
	WriteFile();
	~WriteFile();
	void openFile(std::string fileName);
	void updateFile(std::string log);
};

#endif // !WRITEFILE_H

