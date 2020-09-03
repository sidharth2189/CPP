# include "flight_database.h"
# include <map>
# include <iterator>

using namespace FlightManagementSystem;

FlightTripDatabase::FlightTripDatabase(){}

void FlightTripDatabase:: AddTrip(const std::string flight_number, const std::string origin_city, 
	const std::string destination_city, const std::string flight_operator, float air_fare)
{
    std::shared_ptr<FlightTrip> ft(new FlightTrip {flight_number, origin_city, destination_city, 
    flight_operator, air_fare});
    trip_map.insert(std::pair<std::string, std::shared_ptr<FlightTrip>>(flight_number, ft));
}

void FlightTripDatabase:: RemoveTrip(const std::string flight_number)
{
    trip_map.erase(flight_number);
}

void FlightTripDatabase:: DisplayAllTrips()
{
    std::unordered_map<std::string, std::shared_ptr<FlightTrip>>::iterator it;
    std::cout << "\nThe flight detail(s) is/are : " << std::endl; 
    std::cout << "\tFLIGHT NUMBER\t\tDETAILS" << std::endl;

    for (it=trip_map.begin(); it!=trip_map.end(); ++it) 
    { 
        std::cout << '\t' << it->first << '\t\t' << it->second->origin_city << '\t\t' 
        << it->second->destination_city <<'\t\t' << it->second->flight_operator <<'\t\t' 
        << it->second->air_fare << std::endl;
    } 
    std::cout << std::endl;
}