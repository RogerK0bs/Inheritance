#include "Header.h"

void main()
{
	const int colums = 40, str = 12;
	char mass_buffer[colums][str]{};
	char end = '\n';
	ofstream fout;
	fout.open("201 ready.txt", std::ios_base::app);
	ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		for (size_t i = 0; i < str; i++)
		{
			fin.getline(mass_buffer[i], colums, end);
			//cout << mass_buffer[i] << endl;
			char* mac_copy=new char[colums]{};
			char* ip_copy=new char[colums]{};
			for (size_t j = 0; j < colums - 22; j++)
			{
				mac_copy[j] = mass_buffer[i][j + 22];
			}
			for (size_t j = 0; j < 15; j++)
			{
				ip_copy[j] = mass_buffer[i][j];
			}
			for (size_t j = 0; j < colums; j++)
			{
				if (j < 18)fout << mac_copy[j];
				else fout << ' ';
				if (j == 26)
				{
					for (size_t er = 0; er < 20; er++)
					{
						fout << ip_copy[er];	
					}
				}
			}fout << "\n";
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fin.close();
	fout.close();
}