 class FlightTrip {
  /** attributes */
  char flight_num;
  char origin_city;
  char destination_city;
  char flight_operator; // Air India, Indigo, etc.
  float air_fare;
  
  /** constructor(s) */
  public:
  FlightTrip(char f_num, char or_city, char des_city, char flight_op, float fare):flight_num(f_num), origin_city(or_city), destination_city(des_city), flight_operator(flight_op), air_fare(fare) {}
  FlightTrip(const FlightTrip& ref):FlightTrip(ref.flight_num,ref.origin_city,ref.destination_city, ref.flight_operator, ref.air_fare) {}
  FlightTrip():FlightTrip("AI-854",'pune','bangalore','AirIndia',5000.00) {}
  
  /** any other functions */
};

class FlightTripDatabase {
  /** Suitable container */
  
  /** Suitable prototypes/defintions for the expected functionality*/
  
  /** Return the results wherver possible, let's not leave by just printing*/
  public:
  void AddTrip(char f_num, char or_city, char des_city, char flight_op, float fare)
  {
	  /* some logic */
  }
  
  void RemoveTrip(char f_num)
  {
	  /* some logic */
  }
  
  void UpdateFareByTrip(char f_num, float fare)
  {
	  /* some logic */
  }
  
  void DisplayAllTrips()
  {
	  /* some logic */
  }
  
  void FindFlightByNumber(char f_num)
  {
	  /* some logic */
  }
  
  void FindFlightsByOriginCity(char f_num)
  {
	  /* some logic */
  }
  
  void FindAverageCostOfAllTrips()
  {
	  /* some logic */
  }
  
  void FindMinFareBetweenCities(char or_city, char des_city)
  {
	  /* some logic */
  }
  
  void FindMaxFareByOperator(char flight_op)
  {
	  /* some logic */
  }
  
  void UpdateFareByOperator(char flight_op)
  {
	  /* some logic */
  }
};

TEST(Testname, Subtest)
{
	FlightTrip ft;
	/* ASSERT(...)
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
int main() {
  /** Test plan, you may use additional functions/classes
      for the validation purpose.
  */
  
  /** Some Calls can be like (Note:- invoke with object appropriately )
	/** AddTrip("AI-854","Pune","Delhi",5000)*/
	/** RemoveTrip("SG-512")*/
	/** UpdateFareByTrip(“6E-702”, 5000)*/
	/** DisplayAllTrips()*/
	/**FindFlightByNumber("6E-302"), Return the instance(s) */
	/**FindFlightsByOriginCity("Pune"), Return the instance(s) */
	/** FindAverageCostOfAllTrips()*/
	/**FindMinFareBetweenCities("Pune","Bengaluru");*/
	/**FindMaxFareByOperator(“Indigo”);*/
	/**UpdateFareByOperator("AirIndia");*/
}  */

