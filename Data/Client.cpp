#include "Client.h"

//Return if the client callsign is the searched one
bool Client::found(const string callsign) {
    return callsign == _callsign;
}


//Print all information about a client
void Client::toString() {
    cout << "--------User information---------\n";
    cout << "Callsign:" << setw(10) << _callsign << endl;
    cout << "VID:" << setw(16) << _vid << endl;
    cout << "Name:" << setw(15) << _name << endl;

    if (_client_type == my_enums::clientType::PILOT) {
        cout << "Type:" << setw(15) << "Pilot\n";
        cout << "\n--------Flight details--------\n";
        cout << "Aircraft Type:" << setw(2) << _plane << endl;
        cout << "Altitude:" << setw(11) << _altitude << " ft AMSL\n";
        cout << "Ground Speed:" << setw(5) << _gnd_speed << " kts\n";
        cout << "Transponder:" << setw(7) << _transponder << endl;

        cout << "\n--------Flight plan--------\n";
        _flt_plan.toString();

    }
    else if (_client_type == my_enums::clientType::ATC){
        cout << "Type    : ATC\n\n";
        cout << "\n--------Position details--------\n";
        cout << "TODO" << endl;
        //TODO ATC details
    }
    else cout << "Type    : Follow Me Car\n";
    cout << "TODO" << endl;
    //TODO Other information
}

//Create a PILOT with the information recieved
void Client::createPilot(vector<string> atributes){
    _client_type = my_enums::clientType::PILOT;
    _latitude = stof(atributes[5]);
    _longitude = stof(atributes[6]);
    _altitude = stof(atributes[7]);
    _gnd_speed = atributes[8];
    _server = atributes[14];
    _protocol = atributes[15];
    _combined_rating = atributes[16];
    _transponder = atributes[17];
    _connection_time = stoll(atributes[37]);
    _software_name = atributes[38];
    _software_version = atributes[39];
    _administrative_version = my_enums::administrativeVersion(stoi(atributes[40]));
    _pilot_version = my_enums::pilotVersion (stoi(atributes[41]));;
    _heading = atributes[36];
    (stoi(atributes[46]) == 1)? _on_gnd = true: _on_gnd = false;
    _simulator = my_enums::simulator(stoi(atributes[47]));
    _plane = atributes[39];

    FlightPlan flt_plan = FlightPlan();
    flt_plan.flightInfo(atributes);
    _flt_plan = flt_plan;
}

//Create a ATC with the information recieved
void Client::createATC(vector<string> atributes){
    _client_type = my_enums::clientType::ATC;
    _frecuency = atributes[4];
    _frecuency_cont = atributes[5];
    _latitude = stof(atributes[6]);
    _longitude = stof(atributes[7]);
    _altitude = stof(atributes[8]);
    _server = atributes[9];
    _protocol = atributes[10];
    _combined_rating = atributes[11];
    //_facility_type = atributes[12];
    _visual_range = stof(atributes[13]);
    _atis = atributes[14];
    _atis_time = atributes[15];
    _connection_time = stol(atributes[16]);
    _software_name = atributes[17];
    _software_version = atributes[18];
    //_administrative_version = atributes[19];
    //_client_version = atributes[20];
}

//Create a FOLLOW ME with the information recieved
void Client::createObserver(vector<string> atributes){
    _client_type = my_enums::clientType::FOLME;
    _latitude = stof(atributes[5]);
    _longitude = stof(atributes[6]);
    _altitude = stof(atributes[7]);
    _server = atributes[8];
    _protocol = atributes[9];
    _combined_rating = atributes[10];
    _connection_time = stol(atributes[11]);
    _software_name = atributes[12];
    _software_version = atributes[13];
    //_administrative_version = atributes[14];
    //_client_version = atributes[15];
}

