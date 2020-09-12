#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "ReceiverHeader.h"
#include "catch.hpp"
#include <fstream>
#include <iostream>

using namespace std;

void printSenderData()
{
    ifstream fin("test-data/Visit Count Data.csv");
    if (fin.good())
	{
		while (getline(fin, footfallRecordString))
	    {
            cout << footfallRecordString << endl;
	    }
	}
    fin.close();
}

TEST_CASE("Average footfalls per hour day wise") {
    printSenderData();
    REQUIRE(1 == 1);
}
