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