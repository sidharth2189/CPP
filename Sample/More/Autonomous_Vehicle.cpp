#include <iostream>
#include <memory>
using namespace std;


/* Imagine a fleet of 3 autonomous vehicles driving on a highway in a line. Every vehicle is able to control its actuators, 
but only the first in line is able to detect obsctacles. As a result, the rest of the vehicles have to follow its behavior - 
if the leader applies throttle it notifies the second vehicle (its successor) that it should apply throttle as well. 
The same happens for situation in which leader brakes.

One limitation is that one car can pass the information about throttle or brake only to one nearest vehicle that is behind. 
Since there are few vehicles, every car has to continiue  forwarding the information until the last vehicle has been notified about the action.
*/

// ------ TASK 1 ------
/* Create enum called "VehicleState" which has three fields: DRIVING, STOPPED and NOT_SET. */
enum VehicleState {
  DRIVING,
  STOPPED,
  NOT_SET,
};



// ------ TASK 2 ------
/* Create enum called "VehicleType" which has 3 fields: SEDAN, SMALL_TRUCK, LARGE_TRUCK and UNKNOWN. */
enum VehicleType {
  SEDAN,
  SMALL_TRUCK,
  LARGE_TRUCK,
  UNKNOWN,
};


// ------ TASK 3 ------
/* Create "EnumToString" function which takes as an input VehicleType enum and converts its value to a string. */
string EnumToString (VehicleType A)
{
  string str;
  if (A == VehicleType::SEDAN)
  {
    str = "SEDAN";
  }
  else if (A == VehicleType::SMALL_TRUCK)
  {
    str = "SMALL_TRUCK";
  }
  else if (A == VehicleType::LARGE_TRUCK)
  {
    str = "LARGE_TRUCK";
  }
  else if (A == VehicleType::UNKNOWN)
  {
    str = "UNKNOWN";
  }
  return str;
}


// ------ TASK 4 ------
/* Create a class called "Vehicle". It should contain 2 public pure virtual functions which don't return any value and don't take any arguments:
    - ApplyThrottle
    - ApplyBrake
   And 2 public pure virtual function which return VehicleType and VehicleState enums:
    - GetType
    - GetState
*/
class Vehicle {
  public:
  void virtual ApplyThrottle() = 0;
  void virtual ApplyBrake() = 0;
  VehicleType virtual GetType() = 0;
  VehicleState virtual GetState() = 0;
};


// ------ TASK 5 ------
/* Each vehicle driving in a line is different and requires different amount of throttle to be applied for sustaining the same speed and 
different amount of brake pressure to stop. Additionally, as we mentioned above, every vehicle has to be aware who is its successor (the vehicle behind) 
to be able to inform it about the state change. Implement "AutonomousVehicle" class which inherits from Vehicle interface and has:
    - private member containing information about its type (type:
    VehicleType)
    - private member containing information about its state (type: VehicleState)
    - private member containing pointer to the vehicle behind (use smart pointers if you can)
    - private member containing information about the required throttle (type: integer)
    - private member containing information about the required brake pressure (type: integer)
    - public constructor taking as parameters values of:
      - vehicle type (type: VehicleType)
      - required throttle (type: integer),
      - brake pressure (type: integer),
      - pointer to the vehicle behind.
      Remember to initialize the values of all the members)
    - public copy constructor which ensures that the state and
      address of the successor are not copied (state should be
      reset to NOT_SET and pointer should be set to nullptr)
    - public assignment operator which has the same responsibility as
      the copy constructor
    - implementation of ApplyThrottle member function which prints "<VehicleType>: applying throttle = <throtle_value>", updates the state of the vehicle and makes the successor to apply throttle as well
    - implementation of ApplyBrake member function which prints "<VehicleType>: applying brake = <throtle_value>", updates the state of the vehicle and make the successor to apply brake as well
    - implementation of GetType member function
    - implementation of GetState member function
*/

class AutonomousVehicle : public Vehicle {
  VehicleType _veh_type;
  VehicleState _veh_state = VehicleState::NOT_SET;
  shared_ptr<AutonomousVehicle> _veh_behind;
  int _veh_throttle;
  int _veh_brake_pressure;
  public:
  // constructor
  AutonomousVehicle (VehicleType veh_type, shared_ptr<AutonomousVehicle> veh_behind, int veh_throttle, int veh_brake_pressure) : _veh_type(veh_type), _veh_behind(veh_behind), _veh_throttle(veh_throttle), _veh_brake_pressure(veh_brake_pressure) {}

  // copy constructor
  AutonomousVehicle (AutonomousVehicle * A) {
    _veh_type = A->_veh_type;
    _veh_throttle = A->_veh_throttle;
    _veh_brake_pressure = A->_veh_brake_pressure;
    _veh_state = VehicleState::NOT_SET;
    _veh_behind = nullptr;
  }

  // copy assignment operator
  AutonomousVehicle& operator =(AutonomousVehicle * A){
    _veh_type = A->_veh_type;
    _veh_throttle = A->_veh_throttle;
    _veh_brake_pressure = A->_veh_brake_pressure;
    _veh_state = VehicleState::NOT_SET;
    _veh_behind = nullptr;
    return *this;
  }

  void ApplyThrottle()
  {
    cout << EnumToString(_veh_type) << " applying throttle " << _veh_throttle << endl;
    _veh_state = VehicleState::DRIVING;
    if (_veh_behind.use_count() != 0)
    {
      _veh_behind->ApplyThrottle();
    }
  }

  void ApplyBrake()
  {
    cout << EnumToString(_veh_type) << " applying brake " << _veh_brake_pressure << endl;
    _veh_state = VehicleState::STOPPED;
    if (_veh_behind.use_count() != 0)
    {
      _veh_behind->ApplyBrake();
    }
  }

  VehicleType GetType()
  {
    return _veh_type;
  }

  VehicleState GetState()
  {
    return _veh_state;
  }
};



// ------ TASK 6 ------
/* Create a factory class "VehicleFactory" with two functions:
   - CreateCar - should take as parameters vehicle type and pointer
                 to its successor. Returns pointer to the created object. Parameters of each car:
                   - SEDAN: throttle = 15, brake = 35,
                   - SMALL_TRUCK: throttle = 50, brake = 180
                   - LARGE_TRUCK: throttle = 77, brake = 320
   - CreateCarFleet - should return vector containing 3 elements
                      being pointers to all three types of
                      vehicles. Order of cars in the line: sedan (leader), small_truck, large_truck.
*/
class VehicleFactory {
  public:
  shared_ptr<AutonomousVehicle> CreateCar(VehicleType veh_type, shared_ptr<AutonomousVehicle> veh_behind) {
    AutonomousVehicle veh_current(VehicleType veh_behind->veh_type, shared_ptr<AutonomousVehicle> veh_behind, int veh_throttle, int veh_brake_pressure) : _veh_type(veh_type), _veh_behind(veh_behind), _veh_throttle(veh_throttle), _veh_brake_pressure(veh_brake_pressure);
    if (EnumToString(veh_type)) == "SEDAN")
    {
      veh_behind->_veh_throttle = 15;

    }
    return B;
  }
};


// ------ TASK 7 ------
/* Extend AutonomousVehicle class with a move constructor. Ensure that values of all the members of original object are reset 
(type UNKNOWN, state NOT_SET, successor ptr to nullptr, throttle and brake values zeroed). */



// ------ TASK 8 ------
/* Modify CreateCar function in CarFactory class - make vehicle type a template parameter. */



int main(int argc, char** argv)
{
  // ------ TASK 9 ------
  /* Use the factory you've implemented to create a vector of pointers to cars. */



  // ------ TASK 10 ------
  /* Create a loop within which you invoke ApplyThrottle on the leading vehicle, wait a second, invoke ApplyBreak on the 
  leading vehicle and then one more time wait one second (perform 3 iterations). You can find expected output after main 
  function marked as "FIRST VERSION EXPECTED OUTPUT". */



  // ------ TASK 11 ------
  /* Make this loop infinite and move it to a function called "SimulationLoop". Output should be the same as above. */



  // ------ TASK 12 ------
  /* Move "SimulationLoop" function to a separate thread. Output to should be the same as above. */



  // ------ TASK 13 ------
  /* Create a function called "ObserveStates" which runs in a separate thread. Its responsibility is to constantly monitor 
  the state of all vehicles and to react on the state changes. If a state of a vehicle has changed, the function should print: 
  "STATE OBSERVER: Vehicle <vehicle_type> changed state to <state_name>". You may find useful to implement an overloaded version 
  of EnumToString function dedicated for VehicleState enum. */



    // ------ TASK 14 ------
    /* Create inside the SimulationLoop a local integer variable "n" and assign to it some number between 3 and 5. 
    Print here below the information when function ApplyThrottle inside the SimulationLoop has been invoked N times.
    You can find expected output at the bottom marked as "FINAL EXPECTED OUTPUT". */
    std::cout << /* [YOUR CODE] */ " times invoked!" << std::endl;
}

/* ------ FIRST VERSION EXPECTED OUTPUT ------ */
/*
SEDAN: applying throttle = 15
SMALL_TRUCK: applying throttle = 50
LARGE_TRUCK: applying throttle = 77
SEDAN: applying brake = 35
SMALL_TRUCK: applying brake = 180
LARGE_TRUCK: applying brake = 320
SEDAN: applying throttle = 15
SMALL_TRUCK: applying throttle = 50
LARGE_TRUCK: applying throttle = 77
SEDAN: applying brake = 35
SMALL_TRUCK: applying brake = 180
LARGE_TRUCK: applying brake = 320
SEDAN: applying throttle = 15
SMALL_TRUCK: applying throttle = 50
LARGE_TRUCK: applying throttle = 77
SEDAN: applying brake = 35
SMALL_TRUCK: applying brake = 180
LARGE_TRUCK: applying brake = 320
 times invoked!
*/


/* --------------------------------------- FINAL EXPECTED OUTPUT -------------------------------------- */
/*
sedan: applying throttle = 15
small_truck: applying throttle = 25
large_truck: applying throttle = 38
STATE OBSERVER: Vehicle sedan changed status to DRIVING
STATE OBSERVER: Vehicle large_truck changed status to DRIVING
STATE OBSERVER: Vehicle small_truck changed status to DRIVING
sedan: applying brake = 250
small_truck: applying brake = 380
large_truck: applying brake = 420
STATE OBSERVER: Vehicle sedan changed status to STOPPED
STATE OBSERVER: Vehicle large_truck changed status to STOPPED
STATE OBSERVER: Vehicle small_truck changed status to STOPPED
sedan: applying throttle = 15
small_truck: applying throttle = 25
large_truck: applying throttle = 38
STATE OBSERVER: Vehicle sedan changed status to DRIVING
STATE OBSERVER: Vehicle large_truck changed status to DRIVING
STATE OBSERVER: Vehicle small_truck changed status to DRIVING
sedan: applying brake = 250
small_truck: applying brake = 380
large_truck: applying brake = 420
STATE OBSERVER: Vehicle sedan changed status to STOPPED
STATE OBSERVER: Vehicle large_truck changed status to STOPPED
STATE OBSERVER: Vehicle small_truck changed status to STOPPED
sedan: applying throttle = 15
small_truck: applying throttle = 25
large_truck: applying throttle = 38
STATE OBSERVER: Vehicle sedan changed status to DRIVING
STATE OBSERVER: Vehicle large_truck changed status to DRIVING
STATE OBSERVER: Vehicle small_truck changed status to DRIVING
sedan: applying brake = 250
small_truck: applying brake = 380
large_truck: applying brake = 420
STATE OBSERVER: Vehicle sedan changed status to STOPPED
STATE OBSERVER: Vehicle large_truck changed status to STOPPED
STATE OBSERVER: Vehicle small_truck changed status to STOPPED
sedan: applying throttle = 15
small_truck: applying throttle = 25
large_truck: applying throttle = 38
4 times invoked!
STATE OBSERVER: Vehicle sedan changed status to DRIVING
STATE OBSERVER: Vehicle large_truck changed status to DRIVING
STATE OBSERVER: Vehicle small_truck changed status to DRIVING
 */
