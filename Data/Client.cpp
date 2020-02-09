#include "Client.h"

bool Client::found(const string vid) {
    return vid == _vid;
}

void Client::toString() {
    cout << "--------User information---------\n";
    cout << "Callsign: " << _callsign < endl;
    cout << "VID     : " << _vid < endl;
    cout << "Name    : " << _name < endl;

    if (_client_type == "PILOT") {
        cout << "Type    : Pilot\n";
        cout << "\n--------Flight details--------\n"
        cout << "Aircraft Type: " << _plane << endl;
        cout << "Altitude: " << _altitude << " ft AMSL\n";
        cout << "Ground Speed: " << _gnd_speed << " kts\n";
        cout << "Transponder: " << _transponder << endl;

        cout << "\n--------Flight plan--------\n"
        //TODO flight plan

    }
    else if (_client_type == "CLIENT"){
        cout << "Type    : ATC\n\n";
        cout << "\n--------Position details--------\n"
        //TODO ATC details
    }
    else cout << "Type    : Observer\n";
    //TODO Other information
}
