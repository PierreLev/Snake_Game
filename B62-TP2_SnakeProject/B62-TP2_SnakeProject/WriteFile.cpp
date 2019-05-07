#include "WriteFile.h"
using namespace std;

WriteFile::WriteFile() = default;
WriteFile::~WriteFile() {
	this->file.close();
}

void WriteFile::openFile(string fileName) {
	this->file.open(fileName, fstream::in | fstream::out | fstream::app);
}

void WriteFile::updateFile(string log) {
	if (!this->file.is_open()) {
		this->openFile("log.txt");
	}
	this->file << log << endl;

}