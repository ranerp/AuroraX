#include "FileIO.h"

using namespace std;

char* FileIO::syncReadBinaryFile(const char* filePath)
{
	ifstream file;
	streamsize length;

	file.open(filePath, ios::in);

	if (!file.is_open())
	{
		cerr << "Error opening file: " << filePath << endl;
		return NULL;
	}

	file.seekg(0, ios::end);
	length = file.tellg();

	char* buffer = new char[length]();
	file.read(buffer, length);

	file.close();

	return buffer;
}

bool FileIO::syncReadTextFile(const char* filePath, string& outString)
{
	string line;
	ifstream file(filePath);

	if (!file.is_open())
	{
		cerr << "Error opening file: " << filePath << endl;
		return false;
	}
	else
	{
		while (getline(file, line))
		{
			outString.append(line);
			outString.append("\n");
		}

		file.close();

		return true;
	}
}