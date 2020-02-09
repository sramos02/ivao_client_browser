#include <iostream>
#include "FlightPlan.h"
using namespace std;

#ifndef IVAO_PROJECT_STATUS_H
#define IVAO_PROJECT_STATUS_H

enum clientType{PILOT, ATC, FOLME};
enum facilities{OBS, INF, DEL, GND, TWR, APP, ACC, DEP};
enum administrativeVersion{SUS, vOBS, USR, v3, v4, v5, v6, v7, v8, v9, v10, SUP, ADM};
enum clientVersion{pilotType, atcType};
enum pilotType{x0, pOBS, AS1, AS2, AS3, ADC, APC, pAAC, SEC, SAI, CAI};
enum atcType{a0, aOBS, FS1, FS2, FS3, PP, SPP, CP, ATP, SFI, CFI};
enum simulator{UNK, FS95, FS98, MCFS, FS2000, MCFS2, FS2002, CFS3, FS2004, FSX, s10, XPU, XP8, XP9, XP10, PS1, XP11, XP12, x18, x19, FLY, FLY2, x22, x23, x24, FLTG, x26, x27, x28, x29, P3D};

class Client {
private:
    string _callsign;
    string _vid;
    string _name;
    clientType _client_type;
    float _latitude;
    float _longitude;
    int _altitude;
    string _server;
    string _protocol;
    string _combined_rating;
    long int _connection_time;
    string _software_name;
    string _software_version;
    administrativeVersion _administrative_version;
    clientVersion _client_version;

    //ATC
    string _frecuency;
    string _frecuency_cont;
    facilities _facility_type;
    float _visual_range;
    string _atis;
    string _atis_time;

    //Pilot
    string _gnd_speed;
    FlightPlan _flt_plan;
    string _transponder;
    string _heading;
    bool _on_gnd;
    simulator _simulator;
    string _plane;

public:
    //Empty Constructor
    Client();

    //ATC Constructor
    Client(string callsign, string vid, string name, clientType client_type, float latitude, float longitude,
           int altitude, string server, string protocol, string combined_rating, long int connection_time,
           string software_name, string software_version, administrativeVersion administrative_version, clientVersion client_version,
           string frecuency, string frecuency_cont, facilities facility_type, float visual_range, string atis, string atis_time){

        _callsign = callsign;
        _vid = vid;
        _name = name;
        _client_type = client_type;
        _latitude = latitude;
        _longitude = longitude;
        _altitude = altitude;
        _server = server;
        _protocol = protocol;
        _combined_rating = combined_rating;
        _connection_time = connection_time;
        _software_name = software_name;
        _software_version = software_version;
        _administrative_version = administrative_version;
        _client_version = client_version;
        _frecuency = frecuency;
        _frecuency_cont = frecuency_cont;
        _facility_type = facility_type;
        _visual_range = visual_range;
        _atis = atis;
        _atis_time = atis_time;
    }

    //Pilot Constructor
    Client(string callsign, string vid, string name, clientType client_type, float latitude, float longitude,
           int altitude, string server, string protocol, string combined_rating, long int connection_time,
           string software_name, string software_version, administrativeVersion administrative_version, clientVersion client_version,
           string gnd_speed, FlightPlan flt_plan, string transponder, string heading, bool on_gnd, simulator simulator, string plane){

        _callsign = callsign;
        _vid = vid;
        _name = name;
        _client_type = client_type;
        _latitude = latitude;
        _longitude = longitude;
        _altitude = altitude;
        _server = server;
        _protocol = protocol;
        _combined_rating = combined_rating;
        _connection_time = connection_time;
        _software_name = software_name;
        _software_version = software_version;
        _administrative_version = administrative_version;
        _client_version = client_version;
        _gnd_speed = gnd_speed;
        _flt_plan = flt_plan;
        _transponder = transponder;
        _heading = heading;
        _on_gnd = on_gnd;
        _simulator = simulator;
        _plane = plane;
    }

    //Observer Constructor
    Client(string callsign, string vid, string name, clientType client_type, float latitude, float longitude,
           int altitude, string server, string protocol, string combined_rating, long int connection_time,
           string software_name, string software_version, administrativeVersion administrative_version, clientVersion client_version){

        _callsign = callsign;
        _vid = vid;
        _name = name;
        _client_type = client_type;
        _latitude = latitude;
        _longitude = longitude;
        _altitude = altitude;
        _server = server;
        _protocol = protocol;
        _combined_rating = combined_rating;
        _connection_time = connection_time;
        _software_name = software_name;
        _software_version = software_version;
        _administrative_version = administrative_version;
        _client_version = client_version;
    }

    //Shared methods between atc and pilot
    bool found();
    void toString();

};

#endif //IVAO_PROJECT_STATUS_H
