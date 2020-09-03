//# include <gtest/gtest.h>
//# include <iostream>
//# include "flight_database.h"

/** Google Test*/
/*TEST(Testname, Subtest)
{
	// Arrange
	FlightManagementSystem::FlightDetails fd;
	fd.flight_num = "AI-99";
	fd.origin_city = "Bangalore";
	fd.destination_city = "Pune";
	fd.flight_operator = "AirIndia";
	fd.air_fare = 5345.80;
	
	// Act
	FlightManagementSystem::FlightTripDatabase ftd(fd);
	char flight_number = "AI-99";
	if(flight_number == ftd._flight_trip_ptr->_details.flight_num)
	{
		ftd.trip_map.insert({flight_number, ftd._flight_trip_ptr});
	}
	
	// ASSERT that flight exists
	ASSERT_EQ(ftd.trip_map.find(flight_number) == ftd.trip_map.end(), 1);
}*/

//* Main Function*/
/*
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
	
	/** Test plan, you may use additional functions/classes
      for the validation purpose.
	*/
  
	/** Some Calls can be like (Note:- invoke with object appropriately )
	/** AddTrip("AI-854","Pune","Delhi",5000)*/
	/** RemoveTrip("SG-512")*/
	/** UpdateFareByTrip(“6E-702”, 5000)*/
	/** DisplayAllTrips()*/
	/** FindFlightByNumber("6E-302"), Return the instance(s) */
	/** FindFlightsByOriginCity("Pune"), Return the instance(s) */
	/** FindAverageCostOfAllTrips()*/
	/** FindMinFareBetweenCities("Pune","Bengaluru");*/
	/** FindMaxFareByOperator(“Indigo”);*/
	/** UpdateFareByOperator("AirIndia");*//*
}
*/
# include <iostream>
# include "flight_database.h"
using namespace FlightManagementSystem;

int main()
{
    // Create flight trip data base
    FlightTripDatabase ftd;

    // Add trips
    ftd.AddTrip("AI-620", "Pune", "Bangalore", "AirIndia", 5000.00);
    ftd.AddTrip("AI-621", "Bangalore", "Pune", "AirIndia", 5000.50);

    // Display all trips
    ftd.DisplayAllTrips();
}