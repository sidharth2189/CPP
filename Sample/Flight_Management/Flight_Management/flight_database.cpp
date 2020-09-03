# include "flight_database.h"
# include <map>
# include <iterator>

using namespace FlightManagementSystem;

FlightTripDatabase::FlightTripDatabase(){}

void FlightTripDatabase:: AddTrip(const std::string flight_number, const std::string origin_city, 
	const std::string destination_city, const std::string flight_operator, float air_fare)
{
    // Add flight number if not in database already, else display details
    if (trip_map.find(flight_number) == trip_map.end())
    {
        std::shared_ptr<FlightTrip> ft(new FlightTrip {flight_number, origin_city, destination_city, 
        flight_operator, air_fare});
        trip_map.insert(std::pair<std::string, std::shared_ptr<FlightTrip>>(flight_number, ft));
    }
    else
    {
        std::cout << "\nThe flight already exists in database:" << std::endl;
        std::cout << flight_number << '\t' << trip_map[flight_number]->origin_city <<
        '\t' << trip_map[flight_number]->destination_city << 
        '\t' << trip_map[flight_number]->flight_operator <<
        '\t' << trip_map[flight_number]->air_fare << std::endl;
    }
}

void FlightTripDatabase:: RemoveTrip(const std::string flight_number)
{
    // Remove flight trip, if flight number present in database
    if (trip_map.find(flight_number) == trip_map.end())
    {
        std::cout << "\nNo such flight in database" << std::endl;
    }
    else
    {
        trip_map.erase(flight_number);
        std::cout << "\nRemoved trip" << std::endl;
    }
}

void FlightTripDatabase:: DisplayAllTrips()
{
    if (trip_map.empty())
    {
        std::cout << "\nNo trips in database" << std::endl;
    }
    else
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
}

void FlightTripDatabase:: UpdateFareByTrip(const std::string flight_number, float air_fare)
{
    std::unordered_map<std::string, std::shared_ptr<FlightTrip>>::iterator it = trip_map.find(flight_number); 
    if (it != trip_map.end())
    {
        it->second->air_fare = air_fare;
        std::cout << "\nUpdated details are:" << std::endl;
        std::cout << flight_number << '\t' << trip_map[flight_number]->origin_city <<
        '\t' << trip_map[flight_number]->destination_city << 
        '\t' << trip_map[flight_number]->flight_operator <<
        '\t' << trip_map[flight_number]->air_fare << std::endl;
    }
    else
    {
        std::cout << "\nNo such flight in database" << std::endl;
    }
    
}

std::shared_ptr<FlightTrip> FlightTripDatabase:: FindFlightByNumber(const std::string flight_number)
{
    std::unordered_map<std::string, std::shared_ptr<FlightTrip>>::iterator it = trip_map.find(flight_number);
    if (it != trip_map.end())
    {
        std::cout << "\nFlight details are:" << std::endl;
        std::cout << flight_number << '\t' << trip_map[flight_number]->origin_city <<
        '\t' << trip_map[flight_number]->destination_city << 
        '\t' << trip_map[flight_number]->flight_operator <<
        '\t' << trip_map[flight_number]->air_fare << std::endl;
        return trip_map[flight_number];
    }
    else
    {
        std::cout << "\nNo such flight in database" << std::endl;
        return nullptr;
    }
}

float FlightTripDatabase:: FindAverageCostOfAllTrips()
{
    if (trip_map.empty())
    {
        std::cout << "\nNo trips in database" << std::endl;
        return 0.0;
    }
    else
    {
        float CostOfAllTrips = 0.0;
        float AverageCostOfAllTrips = 0.0;
        std::unordered_map<std::string, std::shared_ptr<FlightTrip>>::iterator it;
        std::cout << "\nThe flight detail(s) is/are : " << std::endl; 
        std::cout << "\tFLIGHT NUMBER\t\tDETAILS" << std::endl;

        for (it=trip_map.begin(); it!=trip_map.end(); ++it) 
        { 
            CostOfAllTrips = CostOfAllTrips + it->second->air_fare;
        } 
        AverageCostOfAllTrips = CostOfAllTrips/trip_map.size();
        return AverageCostOfAllTrips;
    }
}

float FlightTripDatabase:: FindMinFareBetweenCities(const std::string origin_city, 
const std::string destination_city)
{
    if (trip_map.empty())
    {
        std::cout << "\nNo trips in database" << std::endl;
        return 0.0;
    }
    else
    {
        float MinFareBetweenCities = 0.0;
        int counter = 0;
        bool flag = 'False';
        std::unordered_map<std::string, std::shared_ptr<FlightTrip>>::iterator it;
        for (it=trip_map.begin(); it!=trip_map.end(); ++it)
        {
            if((it->second->origin_city == origin_city) && (it->second->destination_city == destination_city))
            {
                if (flag == 'False')
                {
                    MinFareBetweenCities = it->second->air_fare;
                    flag = 'True';
                }
                else if (MinFareBetweenCities > it->second->air_fare)
                {
                    MinFareBetweenCities = it->second->air_fare;
                }
            }
            else
            {
                counter++;
            }
        }

        if (counter == trip_map.size())
        {
            std::cout << "\nNo trips in database" << std::endl;
        }
        return MinFareBetweenCities;
    }
}

float FlightTripDatabase:: FindMaxFareByOperator(const std::string flight_operator)
{
    // Add logic
}

void FlightTripDatabase:: UpdateFareByOperator(const std::string flight_operator)
{
    // Add logic
}

std::shared_ptr<FlightTrip> FlightTripDatabase:: FindFlightsByOriginCity(const std::string origin_city)
{
    // Add logic
}