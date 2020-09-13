#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "ReceiverHeader.h"
#include "catch.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<Receiver> senderData;
Receiver obj;

void createSenderDataVector(const string& footfallRecordString)
{
	vector<int> footfallRecord;
	string footfallElement;
	stringstream footfallStream(footfallRecordString);
	while (getline(footfallStream, footfallElement, ','))
	{
		footfallRecord.push_back(stoi(footfallElement));
	}
	Receiver receiverObj(footfallRecord[0], footfallRecord[1], footfallRecord[2], footfallRecord[3], footfallRecord[4], footfallRecord[5], footfallRecord[6], footfallRecord[7]);
	senderData.push_back(receiverObj);
}

void printSenderData()
{
    ifstream fin("test-data/Visit Count Data.csv");
    string footfallRecordString;
    if (fin.good())
    {
	getline(fin, footfallRecordString);
	while (getline(fin, footfallRecordString))
	{
	    createSenderDataVector(footfallRecordString);
	}
    }
    fin.close();
}

TEST_CASE("Average footfalls per hour day wise") {
    printSenderData();
    vector<Receiver> result = obj.averageFootfallsPerHourDaily(senderData);
    obj.displayHourlyAverageDailyData(result);
    ifstream fin1("test-data/Average Footfalls Hourly Test.csv");
    string testDataBuffer((istreambuf_iterator<char>(fin1)), istreambuf_iterator<char>());
    fin1.close();
    ifstream fin2("test-data/Average Footfalls Hourly.csv");
    string actualDataBuffer((istreambuf_iterator<char>(fin2)), istreambuf_iterator<char>());
    fin2.close();
    REQUIRE(testDataBuffer == actualDataBuffer);
}

TEST_CASE("Average footfalls per day week wise") {
    vector<Receiver> result = obj.averageDailyFootfallsWeekly(senderData);
    obj.displayDailyAverageWeeklyData(result);
    ifstream fin1("test-data/Average Footfalls Weekly Test.csv");
    string testDataBuffer((istreambuf_iterator<char>(fin1)), istreambuf_iterator<char>());
    fin1.close();
    ifstream fin2("test-data/Average Footfalls Weekly.csv");
    string actualDataBuffer((istreambuf_iterator<char>(fin2)), istreambuf_iterator<char>());
    fin2.close();
    REQUIRE(testDataBuffer == actualDataBuffer);
}

TEST_CASE("Peak daily footfalls last month") {
    vector<Receiver> result = obj.peakDailyFootfallLastMonth(senderData);
    obj.displayPeakDailyFootfallLastMonth(result);
    ifstream fin1("test-data/test-data/Peak Daily Footfalls Last Month Test.csv");
    string testDataBuffer((istreambuf_iterator<char>(fin1)), istreambuf_iterator<char>());
    fin1.close();
    ifstream fin2("test-data/test-data/Peak Daily Footfalls Last Month.csv");
    string actualDataBuffer((istreambuf_iterator<char>(fin2)), istreambuf_iterator<char>());
    fin2.close();
    REQUIRE(testDataBuffer == actualDataBuffer);
}
