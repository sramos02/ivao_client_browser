#include "FlightPlan.h"

using namespace std;

void FlightPlan::toString() {
    cout << "Departure: " << setw(10) << _departure << endl;
    cout << "Destination: " << setw(8) << _destination << endl;
    cout << "Departure time: " << setw(5) << _departure_time << endl;
    cout << "Total EET: " << setw(7) << _eet_hours << "." << _eet_minutes << " hours\n";
    cout << "Endurance: " << setw(7) << _endurance_hours << "." << _endurance_minutes << " hours\n";
    cout << "Type " << setw(13) << _type_of_flight << endl;
    cout << "Cruising level: " << setw(4) << _cruising_level << endl;
    cout << "Cruising speed: " << setw(4) << _cruising_speed << endl;
    cout << "Route:          " << _route << endl;
    cout << "Remarks:        " << _other_info << endl;
}

void FlightPlan::flightInfo(vector<string> words){
    _aircraft = words[9];
    _cruising_speed = words[10];
    _departure = words[11];
    _cruising_level = words[12];
    _destination = words[13];
    _revision = words[20];
    _flight_rules = words[21][0];
    _departure_time = words[22];
    _actual_departure_time = words[23];
    if(words[24] != "") _eet_hours = stoi(words[24]);
    if(words[25] != "") _eet_minutes = stoi(words[25]);
    if(words[26] != "")_endurance_hours = stoi(words[26]);
    if(words[27] != "")_endurance_minutes = stoi(words[27]);
    _alternate_aerodrome = words[28];
    _other_info = words[29];
    _route = words[30];
    _alternative_aerodrome_2 = words[40];
    _type_of_flight = words[41][0];
    _persons_on_board = words[42];
}
