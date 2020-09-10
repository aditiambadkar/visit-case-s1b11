#include "ReceiverHeader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Receiver::Receiver() {}

Receiver::Receiver(int d, int m, int y, float ha) : date(d), month(m), year(y), hourlyAverage(ha) {}

void Receiver::readSenderData()
{
	string footfallRecordString;
	getline(cin, footfallRecordString);
	cout << footfallRecordString << endl;
	while (getline(cin, footfallRecordString))
	{
		cout << footfallRecordString << endl;
		storeFootfallData(footfallRecordString);
	}
}

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
	/*ofstream fout("test-data/Average Hourly Footfalls Daily.csv", ios::app);
	if(fout.is_open())
	{
		cout << "File created" << endl;
		fout << "11" << ", " << "123" << ", " << "45" <<"\n";
	}
	fout.close();*/
	
	for(unsigned int i = 0; i < footfallData.size(); i++)
	{
		
	}
}

int main()
{
	Receiver receiverObj;
	
	cout << "In receiver main" << endl;
	
	receiverObj.readSenderData();
	receiverObj.averageFootfallsPerHourDaily();
	
	return 0;
}
