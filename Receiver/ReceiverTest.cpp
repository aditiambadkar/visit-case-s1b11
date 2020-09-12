#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "ReceiverHeader.h"
using namespace std;
TEST_CASE("Average footfalls per hour day wise") {
    Receiver obj;
    REQUIRE(obj.testAverageFootfallsPerHourDaily() == true);
}
