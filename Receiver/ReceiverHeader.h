#pragma once
#include <vector>
#include <string>

using namespace std;

class Receiver
{
private:
	vector<vector<int>> footfallData;
public:
	void storeFootfallData(const string&);
	void averageFootfallsPerHourDaily();
	//float averageDailyFootfallsWeekly();
	//float peakDailyFootfallLastMonth();
};
