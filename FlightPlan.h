#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#ifndef IVAO_PROJECT_FLIGHTPLAN_H
#define IVAO_PROJECT_FLIGHTPLAN_H

class FlightPlan{
private:
    string _aircraft;
    string _cruising_speed;
    string _departure;
    string _cruising_level;
    string _destination;
    string _revision;
    string _flight_rules;
    string _departure_time;
    string _actual_departure_time;
    string _eet_hours;
    string _eet_minutes;
    string _endurance_hours;
    string _endurance_minutes;
    string _alternate_aerodrome;
    string _other_info;
    string _route;
    string _alternative_aerodrome_2;
    char _type_of_flight;
    string _persons_on_board;
public:

    //Constructor
    FlightPlan(){
        _eet_hours = '-';
        _eet_minutes = '-';
        _endurance_hours = '-';
        _endurance_minutes = '-';
    }

    //Class methods
    void flightInfo(vector<string> words);
    void toString();
};

#endif //IVAO_PROJECT_FLIGHTPLAN_H
