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

vector<Receiver> Receiver::averageFootfallsPerHourDaily()
{
	/*ofstream fout("test-data/Average Hourly Footfalls Daily.csv", ios::app);
	if(fout.is_open())
	{
		cout << "File created" << endl;
		fout << "11" << ", " << "123" << ", " << "45" <<"\n";
	}
	fout.close();*/
	vector<Receiver> hourlyAverageDailyData;
	Receiver receiverObj(footfallData[0][5], footfallData[0][6], footfallData[0][7], 0);
	for(unsigned int i = 0; i < footfallData.size(); i++)
	{
		if(receiverObj.date == footfallData[i][5])
		{
			receiverObj.hourlyAverage += 1;
		}
		else
		{
			receiverObj.hourlyAverage = receiverObj.hourlyAverage / 4;
			hourlyAverageDailyData.push_back(receiverObj);
			receiverObj.date = footfallData[i][5];
			receiverObj.month = footfallData[i][6];
			receiverObj.year = footfallData[i][7];
			receiverObj.hourlyAverage = 0;
			i--;
		}
	}
	receiverObj.hourlyAverage = receiverObj.hourlyAverage / 4;
	hourlyAverageDailyData.push_back(receiverObj);
	
	return hourlyAverageDailyData;
}

int main()
{
	Receiver receiverObj;
	
	cout << "In receiver main" << endl;
	
	receiverObj.readSenderData();
	vector<Receiver> hourlyAverageDailyData = receiverObj.averageFootfallsPerHourDaily();
	
	cout<<"Date "<<"Month "<<"Year "<<" Hourly Avg"<<endl;
	for(unsigned int i = 0; i < hourlyAverageDailyData.size(); i++)
	{
		cout<<hourlyAverageDailyData[i].date<<" "<<hourlyAverageDailyData[i].month<<" "<<hourlyAverageDailyData[i].year<<" "<<hourlyAverageDailyData[i].hourlyAverage<<endl;
	}
	
	return 0;
}
