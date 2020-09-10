#pragma once
#include <vector>
#include <string>

using namespace std;

class Receiver
{
private:
	vector<Receiver> footfallData;
	int id;
	int hour;
	int minute;
	int second;
	int day;
	int date;
	int month;
	int year;
	float hourlyAverage;
public:
	Receiver();
	Receiver(int, int, int, float);
	Receiver(int, int, int, int, int, int, int, int);
	void readSenderData();
	void storeFootfallData(const string&);
	void averageFootfallsPerHourDaily();
	void displayhourlyAverageDailyData(vector<Receiver>);
	//float averageDailyFootfallsWeekly();
	//float peakDailyFootfallLastMonth();
};
