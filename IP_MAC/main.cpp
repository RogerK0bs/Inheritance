#include "Header.h"

void main()
{
	char symbol = ' ';
	const int SIZE = 1024;
	ofstream fout;
	fout.open("201 ready.txt");
	ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		char sz_buffer[SIZE]{};
		while (!fin.eof())
		{
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	for (size_t i = 0; i < 12; i++)
	{
		char* buffer;
		while (!fin.eof())
		{
			if (fin.eof() != symbol)fin.getline(buffer,SIZE);
		}

	}

	


	fout.close();
	fin.close();
}