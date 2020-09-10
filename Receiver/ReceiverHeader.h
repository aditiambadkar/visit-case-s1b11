#pragma once
#include <vector>
#include <string>

using namespace std;

class Receiver
{
private:
	vector<vector<int>> footfallData;
	int date;
	int month;
	int year;
	float hourlyAverage;
public:
	Receiver();
	Receiver(int, int, int, float);
	void readSenderData();
	void storeFootfallData(const string&);
	vector<Receiver> averageFootfallsPerHourDaily();
	//float averageDailyFootfallsWeekly();
	//float peakDailyFootfallLastMonth();
};
