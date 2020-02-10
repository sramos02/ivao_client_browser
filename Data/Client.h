#include "FlightPlan.h"
#include "enum.h"

#ifndef IVAO_PROJECT_STATUS_H
#define IVAO_PROJECT_STATUS_H

class Client {
private:
    //Shared atributes
    string _callsign;
    string _vid;
    string _name;
    my_enums::clientType _client_type;
    float _latitude;
    float _longitude;
    int _altitude;
    string _server;
    string _protocol;
    string _combined_rating;
    unsigned long long  _connection_time;
    string _software_name;
    string _software_version;
    my_enums::administrativeVersion _administrative_version;

    //ATC atributes
    string _frecuency;
    string _frecuency_cont;
    my_enums::facilities _facility_type;
    float _visual_range;
    string _atis;
    string _atis_time;
    my_enums::atcVersion _atc_version;

    //Pilot atributes
    string _gnd_speed;
    FlightPlan _flt_plan;
    string _transponder;
    string _heading;
    bool _on_gnd;
    my_enums::simulator _simulator;
    my_enums::pilotVersion _pilot_version;
    string _plane;

public:
    //Constructor
    Client(string callsign, string vid, string name){
        _callsign = callsign;
        _vid = vid;
        _name = name;
    }

    //Class methods
    bool found(const string callsign);
    void toString();

    void createPilot(vector<string> atributes);
    void createATC(vector<string> atributes);
    void createObserver(vector<string> atributes);
};

#endif //IVAO_PROJECT_STATUS_H
