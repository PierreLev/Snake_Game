#include "Utils.h"
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

string Utils::getCurrentDate(string const & format) {
	stringstream stream;  
	time_t time{ std::time(nullptr) };  
	tm tm;  localtime_s(&tm, &time);  
	stream << std::put_time(&tm, format.c_str());  
	return stream.str();
}
