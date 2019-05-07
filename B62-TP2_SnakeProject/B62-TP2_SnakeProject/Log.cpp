#include "Log.h"
#include "Utils.h"

Log::Log():
	/*Valeur par default*/
	includeDate{false}
{};

Log::~Log() = default;

using namespace std;
//Permet d'avoir une seule instance de la classe Log
Log& Log::getInstance() {
	static Log s;
	return s;
}

void Log::setFile(string file) {
	this->wf.openFile(file);
}

void Log::setIncludeDate(bool id) {
	this->includeDate = id;
}
bool Log::getIncludeDate() {
	return this->includeDate;
}

void Log::writeLog(size_t type, string message) {
	string log;
	string typevalue = this->findType(type);
	if (this->includeDate) {
		log = Utils::getCurrentDate() + " " + typevalue + " " + message;
	}
	else {
		log = typevalue + " " + message;
	}

	this->updateLog(log);
}

void Log::writeLog(size_t type, std::string message, int value) {

	string log;
	string typevalue = this->findType(type);
	if (this->includeDate) {
		log = Utils::getCurrentDate() + " " + typevalue + " " + message + to_string(value);
	}
	else {
		log = typevalue + " " + message;
	}

	this->updateLog(log);
}

void Log::writeLog(size_t type, std::string message, bool value) {
	string log;
	string typevalue = this->findType(type);
	if (this->includeDate) {
		log = Utils::getCurrentDate() + " " + typevalue + " " + message + " " + to_string(value);
	}
	else {
		log = typevalue + " " + message;
	}

	this->updateLog(log);
}

void Log::writeLog(size_t type, std::string message, double value) {
	string log;
	string typevalue = this->findType(type);
	if (this->includeDate) {
		log = Utils::getCurrentDate() + " " + typevalue + " " + message + " " + to_string(value);
	}
	else {
		log = typevalue + " " + message;
	}

	this->updateLog(log);
}

void Log::writeLog(size_t type, std::string message, bai::PointReal point) {
	string log;
	string typevalue = this->findType(type);
	if (this->includeDate) {
		log = Utils::getCurrentDate() + " " + typevalue + " " + message + " " +  " Position X: "+ to_string(point.x()) + " " + " Position Y: " + to_string(point.y());
	}
	else {
		log = typevalue + " " + message;
	}

	this->updateLog(log);

}



string Log::findType(size_t type) {
	map<size_t, string>::iterator i;
	i = this->logTypes.find(type);
	/*l'itérateur parcours le map jusqua ce quil trouve la clé'*/
	if (i != this->logTypes.end()) { /*si l'itérateur arrete avant la fin du map la clé existe*/
		/*second élément du map est la valeur*/
		return i->second;  
	}
	else {
		/*si la clé n'est pas trouver la valeur est unknown*/
		return "unknown";
	}
}

bool Log::isLastLog(std::string message) {
	if (message == this->lastLog) {
		return true;
	}
	else {
		this->lastLog = message;
		return false;
	}
}

// Ouvre un fichier et écrit un log
void Log::updateLog(std::string message) {
	if (!this->isLastLog(message)) {
		this->wf.updateFile(message);
	}
	
}



