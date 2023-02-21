#include "Header.h"

void main()
{
	const int SIZE = 1024;
	
	char symbol = ' ';
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
		
		while (!fin.eof())
		{
			char* buffer;
			if (fin.eof() != symbol)
			{
				fin.getline(buffer, SIZE);
				cout << buffer << "\t";
			}
		}
	}

	


	fout.close();
	fin.close();
}