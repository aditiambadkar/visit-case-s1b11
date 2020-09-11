#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "ReceiverHeader.h"

TEST_CASE("Average footfalls per hour day wise") {
    REQUIRE(testAverageFootfallsPerHourDaily("test-data/Average Footfalls Hourly Test.csv") == true);
}
