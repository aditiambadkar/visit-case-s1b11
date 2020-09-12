#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "ReceiverHeader.h"
#include "catch.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Receiver> senderData;

void printSenderData()
{
    ifstream fin("test-data/Visit Count Data.csv");
    string footfallRecordString;
    if (fin.good())
    {
	while (getline(fin, footfallRecordString))
	{
            cout << footfallRecordString << endl;
	    createSenderDataVector(footfallRecordString);
	}
    }
    fin.close();
}

void createSenderDataVector(const string& footfallRecordString)
{
	vector<int> footfallRecord;
	string footfallElement;
	stringstream footfallStream(footfallRecordString);
	while (getline(footfallStream, footfallElement, ','))
	{
		footfallRecord.push_back(stoi(footfallElement));
	}
	cout << footfallRecord.size() << endl;
	Receiver receiverObj(footfallRecord[0], footfallRecord[1], footfallRecord[2], footfallRecord[3], footfallRecord[4], footfallRecord[5], footfallRecord[6], footfallRecord[7]);
	senderData.push_back(receiverObj);
}

Receiver obj;

TEST_CASE("Average footfalls per hour day wise") {
    printSenderData();
    vector<Receiver> testSenderData = obj.readSenderData()
    REQUIRE(testSenderData == senderData);
}
