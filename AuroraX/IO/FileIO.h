#pragma once

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace FileIO
{
	char* syncReadBinaryFile(const char* filePath);
	bool syncReadTextFile(const char* filePath, string& outString);
}
