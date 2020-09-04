# include <memory>
# include <unordered_map>
# include <vector>
# include "flight_trip.h"

/** Flight Management System*/
namespace FlightManagementSystem
{
	class FlightTripDatabase
	{
		public:
		/** Constructor(S)*/
		FlightTripDatabase();
  
		/** Suitable prototypes/defintions for the expected functionality*/
		void AddTrip(const std::string flight_number, const std::string origin_city, 
		const std::string destination_city, const std::string flight_operator, float air_fare);
		void RemoveTrip(const std::string flight_number);
		void DisplayAllTrips();
		std::shared_ptr<FlightTrip> UpdateFareByTrip(const std::string flight_number, float air_fare);
		float FindAverageCostOfAllTrips();
		float FindMinFareBetweenCities(const std::string origin_city, const std::string destination_city);
		float FindMaxFareByOperator(const std::string flight_operator);
		void UpdateFareByOperator(const std::string flight_operator);
		std::shared_ptr<FlightTrip> FindFlightByNumber(const std::string flight_number);
		std::vector<std::shared_ptr<FlightTrip>> FindFlightsByOriginCity(const std::string origin_city); 
		
		/** Return the results wherver possible, let's not leave by just printing*/

		private:
		/** Suitable container */
		std::unordered_map<std::string, std::shared_ptr<FlightTrip>> trip_map;
	};
}