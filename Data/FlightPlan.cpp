#include "FlightPlan.h"

using namespace std;

void FlightPlan::toString() {
    if (_departure == "" && _destination == "") {
        cout << "No flight plan sent\n";
    }
    else {
        cout << setfill(' ') << left;

        cout << setw(15) << "Departure: " << _departure << endl;
        cout << setw(15) << "Destination: " << _destination << endl;
        cout << setw(15) << "Departure time: " << _departure_time << endl;
        cout << setw(15) << "Total EET: " << _eet_hours << "." << _eet_minutes << " hours\n";
        cout << setw(15) << "Endurance: " << _endurance_hours << "." << _endurance_minutes << " hours\n";
        cout << setw(15) << "Type: " << _type_of_flight << endl;
        cout << setw(15) << "Cruise level: " << _cruising_level << endl;
        cout << setw(15) << "Cruise speed: " << _cruising_speed << endl;
        cout << setw(15) << "Route: " << _route << endl;
        cout << setw(15) << "Remarks: " << _other_info << endl;
    }
}

void FlightPlan::flightInfo(vector<string> words){
    _aircraft = words[9]; //With other information
    _cruising_speed = words[10];
    _departure = words[11];
    _cruising_level = words[12];
    _destination = words[13];
    //18, 19 ?
    _revision = words[20];
    _flight_rules = words[21][0];
    _departure_time = words[22];
    _actual_departure_time = words[23];
    _eet_hours = words[24];
    _eet_minutes = words[25];
    _endurance_hours = words[26];
    _endurance_minutes = words[27];
    _alternate_aerodrome = words[28];
    _other_info = words[29];
    _route = words[30];
    _alternative_aerodrome_2 = words[42];
    _type_of_flight = words[43][0];
    _persons_on_board = words[44];
}