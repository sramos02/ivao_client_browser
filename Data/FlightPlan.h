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
    char _flight_rules;
    int _departure_time;
    int _actual_departure_time;
    int _eet_hours;
    int _eet_minutes;
    int _endurance_hours;
    int _endurance_minutes;
    string _alternate_aerodrome;
    string _other_info;
    string _route;
    string _alternative_aerodrome_2;
    char _type_of_flight;
    int _persons_on_board;
public:

    //Empty Constructor
    FlightPlan(){}

    void flightInfo(vector<string> words);
    void toString();
};


#endif //IVAO_PROJECT_FLIGHTPLAN_H
