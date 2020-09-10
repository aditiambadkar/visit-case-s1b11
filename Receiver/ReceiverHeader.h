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
	double hourlyAverage;
public:
	Receiver();
	Receiver(int, int, int, double);
	void readSenderData();
	void storeFootfallData(const string&);
	void averageFootfallsPerHourDaily();
	//float averageDailyFootfallsWeekly();
	//float peakDailyFootfallLastMonth();
};
