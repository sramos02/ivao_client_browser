#include "FlightPlan.h"

using namespace std;

void FlightPlan::toString() {
    cout << "Airline: " << setw(10);
    cout << "Departure: ";
    cout << "Destination: ";
    cout << "Departure time: ";
    cout << "Total EET: ";
    cout << "Endurance: ";
    cout << "Type ";
    cout << "Cruising level: ";
    cout << "Cruising speed: ";
    cout << "Route: ";
    cout << "Remarks: ";
}

void FlightPlan::flightInfo(vector<string> words){
    _aircraft = words[9];
    _cruising_speed = words[10];
    _departure = words[11];
    _cruising_level = words[12];
    _destination = words[13];
    _revision = words[20];
    _flight_rules = words[21][0];
    _departure_time = stoi(words[22]);
    _actual_departure_time = stoi(words[23]);
    _eet_hours = stoi(words[24]);
    _eet_minutes = stoi(words[25]);
    _endurance_hours = stoi(words[26]);
    _endurance_minutes = stoi(words[27]);
    _alternate_aerodrome = words[28];
    _other_info = words[29];
    _route = words[30];
    _alternative_aerodrome_2 = words[40];
    _type_of_flight = words[41][0];
    _persons_on_board = stoi(words[42]);
}
