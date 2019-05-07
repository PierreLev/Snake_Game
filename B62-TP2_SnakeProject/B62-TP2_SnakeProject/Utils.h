#ifndef UTILS_H
#define UTILS_H

#include <string>
class Utils
{
public:
	static std::string getCurrentDate(std::string const & format = "%Y.%m.%d %H:%M:%S");

};

#endif // !UTILS_H