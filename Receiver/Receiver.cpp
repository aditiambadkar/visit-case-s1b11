#include "ReceiverHeader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void Receiver::storeFootfallData(const string& footfallRecordString)
{
	vector<int> footfallRecord;
	string footfallElement;
	stringstream footfallStream(footfallRecordString);
	while (getline(footfallStream, footfallElement, ','))
	{
		footfallRecord.push_back(stoi(footfallElement));
	}
	cout << "Record Pushed" << endl;
	cout << footfallRecord.size() << endl;
	footfallData.push_back(footfallRecord);
}

void Receiver::averageFootfallsPerHourDaily()
{
	ofstream fout("test-data/Average Hourly Footfalls Daily.csv", ios::app);
	if(fout.is_open())
	{
		cout << "File created" << endl;
		fout << "11" << ", " << "123" << ", " << "45" <<"\n";
	}
	fout.close();
}

int main()
{
	Receiver receiverObj;
	string footfallRecordString;
	cout << "In receiver main" << endl;
	getline(cin, footfallRecordString);
	cout << footfallRecordString << endl;
	while (getline(cin, footfallRecordString))
	{
		cout << footfallRecordString << endl;
		receiverObj.storeFootfallData(footfallRecordString);
	}

	receiverObj.averageFootfallsPerHourDaily();
	
	return 0;
}
