#include "Client.h"

//Return if the client callsign is the searched one
bool Client::found(const string callsign) {
    return callsign == _callsign;
}


//Print all information about a client
void Client::toString() {
    cout << "--------User information---------\n";
    cout << setfill(' ') << left;

    cout << setw(15)  << "Callsign: " << _callsign << endl;
    cout << setw(15) <<  "VID: " <<  _vid << endl;
    cout << setw(15) << "Name: " << _name << endl;
    cout << setw(15) << "Type";

    switch (_client_type) {
        case 0: cout << "Pilot" << endl;
            break;
        case 1: cout << "ATC" << endl;
            break;
        case 2: cout << "Follow Me Car" << endl;
            break;
    }

    if (_client_type == my_enums::clientType::PILOT || _client_type == my_enums::clientType::FOLME) {
        cout << "\n--------Flight details--------\n";
        cout << setw(15) << "Aircraft Type:" << _plane << endl;
        cout << setw(15) << "Altitude:" <<  _altitude << " ft AMSL\n";
        cout << setw(15) << "Ground Speed:" << _gnd_speed << " kts\n";
        cout << setw(15) << "Transponder:" << _transponder << endl;

        cout << "\n--------Flight plan--------\n";
        _flt_plan.toString();

    }

    else if (_client_type == my_enums::clientType::ATC){
        cout << "\n--------Position details--------\n";
        cout << setw(15) << "Position: "  << my_enums::facilities(_facility_type) << endl;
        cout << setw(15) << "Frecuency: " << _frecuency << endl;
        cout << setw(15) << "ATIS: "  << _atis << endl;
    }

    //Here may print other information like server, protocol...
}

//Create a PILOT with the information recieved
void Client::createPilot(vector<string> atributes){

    if (atributes[3] == "PILOT") _client_type = my_enums::clientType::PILOT;
    else _client_type = my_enums::clientType::FOLME;

    _latitude = atributes[5];
    _longitude = atributes[6];
    _altitude = atributes[7];
    _gnd_speed = atributes[8];
    _server = atributes[14];
    _protocol = atributes[15];
    _combined_rating = atributes[16];
    _transponder = atributes[17];
    _heading = atributes[36];
    _connection_time = stoll(atributes[37]);
    _software_name = atributes[38];
    _software_version = atributes[39];
    _administrative_version = my_enums::administrativeVersion(stoi(atributes[40]));
    _pilot_version = my_enums::pilotVersion (stoi(atributes[41]));
    //atribute 42
    (stoi(atributes[46]) == 1)? _on_gnd = true: _on_gnd = false;
    _simulator = my_enums::simulator(stoi(atributes[47]));
    FlightPlan flt_plan = FlightPlan();
    flt_plan.flightInfo(atributes);
    _flt_plan = flt_plan;
    //_plane
}

//Create a ATC with the information recieved
void Client::createATC(vector<string> atributes){
    _client_type = my_enums::clientType::ATC;
    _frecuency = atributes[4];
    _latitude = stof(atributes[5]);
    _longitude = stof(atributes[6]);
    _altitude = stof(atributes[7]);
    _frecuency_cont = atributes[8];
    _server = atributes[14];
    _protocol = atributes[15];
    _combined_rating = atributes[16];
    //atribute 17
    _facility_type = my_enums::facilities(stoi(atributes[18]));
    _visual_range = atributes[19];

    if (atributes[40] != "" && atributes[41] != "") {
        //_atis = atributes[35];
        _atis_time = atributes[36];
        _connection_time = atributes[37];
        _software_name = atributes[38];
        _software_version = atributes[39];
        _administrative_version = my_enums::administrativeVersion(stoi(atributes[40]));
        _atc_version = my_enums::atcVersion(stoi(atributes[41]));
    }
    else {
        _connection_time = atributes[35];
        _software_name = atributes[36];
        _software_version = atributes[37];
        _administrative_version = my_enums::administrativeVersion(stoi(atributes[38]));
        _atc_version = my_enums::atcVersion(stoi(atributes[39]));
    }
}

//Create a FOLLOW ME with the information recieved
void Client::createObserver(vector<string> atributes){
    _latitude = stof(atributes[5]);
    _longitude = stof(atributes[6]);
    _altitude = stof(atributes[7]);
    _server = atributes[14];
    _protocol = atributes[15];
    _combined_rating = atributes[16];
    _connection_time = atributes[37];
    _software_name = atributes[38];
    _software_version = atributes[39];
    _administrative_version = my_enums::administrativeVersion(stoi(atributes[40]));
    //_client_version = atributes[41];
}
