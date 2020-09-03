# include <iostream>
namespace FlightManagementSystem
{
    /** attributes */
	struct FlightTrip
	{
		std::string flight_num;
		std::string origin_city;
		std::string destination_city;
		std::string flight_operator; // Air India, Indigo, etc.
		float air_fare;
	};
}    