# include <memory>
# include <unordered_map>
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
		void UpdateFareByTrip(const std::string flight_number, float air_fare);
		float FindAverageCostOfAllTrips();
		float FindMinFareBetweenCities(const std::string origin_city, const std::string destination_city);
		std::shared_ptr<FlightTrip> FindFlightByNumber(const std::string flight_number); 	// Return the instance(s)
		// ---------- yet to implement ------------------------ //
		std::shared_ptr<FlightTrip> FindFlightsByOriginCity(const std::string origin_city); // Return the instance(s)
		float FindMaxFareByOperator(const std::string flight_operator);
		void UpdateFareByOperator(const std::string flight_operator);
  
		/** Return the results wherver possible, let's not leave by just printing*/

		private:
		/** Suitable container */
		std::unordered_map<std::string, std::shared_ptr<FlightTrip>> trip_map;
	};
}