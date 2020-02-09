#include <iostream>
#include <string>
using namespace std;

#ifndef IVAO_PROJECT_STATUS_H
#define IVAO_PROJECT_STATUS_H

enum clientType{PILOT, ATC};

class Client {
private:
    string callsign;
    string vid;
    string name;
    clientType client_type;
    string latitude;
    string longitude;
    string altitude;
    string server;
    string protocol;
    string combined_rating;
    string connection_time;
    string software_name;
    string software_version;
    string administrative_version;
    string client_version;

public:
    //Constructor
    Client();

    //Shared methods between atc and pilot

    //Auxiliar

};

#endif //IVAO_PROJECT_STATUS_H
