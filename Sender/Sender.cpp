#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string footfallRecordString;
  ifstream fin("test-data/Visit Count Data.csv");
	if (fin.is_open())
	{
		cout << "file open" << endl;
	}

	if (fin.good())
	{
		while (getline(fin, footfallRecordString))
		{
			cout << footfallRecordString << endl;
		}	
	}

	fin.close();

	return 0;
}
