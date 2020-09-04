# include <iostream>
# include "flight_database.h"
using namespace FlightManagementSystem;

int main()
{
    // Create flight trip data base
    FlightTripDatabase ftd;

	/**** Test Start****/

    // Add trips
    ftd.AddTrip("AI-620", "Pune", "Bangalore", "AirIndia", 5000.00);
    ftd.AddTrip("AI-621", "Bangalore", "Pune", "AirIndia", 5000.50);
	ftd.AddTrip("6E-230", "Delhi", "Mumbai", "Indigo", 4000.00);
	ftd.AddTrip("6E-231", "Mumbai", "Delhi", "Indigo", 4000.50);
	ftd.AddTrip("SG-278", "Pune", "Bangalore", "SpiceJet", 4500.00);

    // Display all trips
    ftd.DisplayAllTrips();

	// Remove trip
	ftd.RemoveTrip("AI-621");

	// Display all trips
    ftd.DisplayAllTrips();

	// Remove a non-existent trip
	ftd.RemoveTrip("AI-230");

	// Display all trips
    ftd.DisplayAllTrips();

	// Update fare by trip
	std::shared_ptr<FlightTrip> ft_ptr1 = ftd.UpdateFareByTrip("6E-231", 4100.50);

	// Update fare for a non-existent trip
	std::shared_ptr<FlightTrip> ft_ptr2 = ftd.UpdateFareByTrip("6E-431", 4100.50);

	// Display all trips
    ftd.DisplayAllTrips();

	// Find average cost of all trips in database
	float avg_cost = ftd.FindAverageCostOfAllTrips();

	// Find mimimum fare between two cities
	float min_fare1 = ftd.FindMinFareBetweenCities("Pune","Bangalore");

	// Find mimimum fare for non-existent trips between two cities
	float min_fare2 = ftd.FindMinFareBetweenCities("Kolkata","Delhi");

	// Find maximum fare by operator
	float max_fare1 = ftd.FindMaxFareByOperator("Indigo");
	float max_fare2 = ftd.FindMaxFareByOperator("AirIndia");

	// Find maximum fare for non-existent operator
	float max_fare3 = ftd.FindMaxFareByOperator("AirAsisa");

	// Update fare by operator
	ftd.UpdateFareByOperator("AirIndia");

	// Update fare for a non-existent operator
	ftd.UpdateFareByOperator("GoAir");

	// Display all trips
    ftd.DisplayAllTrips();

	// Find flight by number
	std::shared_ptr<FlightTrip> ft_ptr3 = ftd.FindFlightByNumber("AI-620");

	// Find a non-existent flight by number
	std::shared_ptr<FlightTrip> ft_ptr4 = ftd.FindFlightByNumber("SG-620");

	// Find flights by origin city
	std::vector<std::shared_ptr<FlightTrip>> vec_ft_ptr1 = ftd.FindFlightsByOriginCity("Pune");

	// Find non-existent flights by origin city
	std::vector<std::shared_ptr<FlightTrip>> vec_ft_ptr2 = ftd.FindFlightsByOriginCity("Kochi");

	/**** Test End****/
}