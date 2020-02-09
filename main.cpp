#include <fstream>
#include <exception>
#include <vector>
#include "Data/Client.h"


//Program methods
Client readClient();
Client clientParse(ifstream status, string line);

int main() {

    //TODO Write status.txt from web
    //Open the file and get the information from status.txt
    ifstream status;
    int callsign;

    try {
        status.open("status.txt");
    }  catch (exception& e){
        cout << "Can't open file, try again.\n";
    }

    cout << "Search for a Callsign: ";
    cin >> callsign;

    //Read header
    string line;

    while (line != "!CLIENTS"){
        if (line != "!CLIENTS") getline(status, line); //Do not read the first Client section line
    }

    //Read Clients
    Client clt = clientParse(status, line);
    bool found = false;

    while (line != "!SERVERS"){
        if(line !=  "!SERVERS") clientParse(status, line);
        found |= clt.found();

    }

    if(found) clt.toString();
    else cout << "This VID do not match with any online user.\n";

    status.close();
    return 0;
}

Client clientParse(fstream status, string line) {
    vector<string> words;
    int i = 1;

    getline(status, words[0], ":");
    while(words.at(i-1) != "!SERVERS"){
        getline(status, words[i], ":");
        i++;
    }
    //TODO create a new Client
}


//TODO long 0 en clientes
//TODO revisar variables, constantes, punteros, referencias
//TODO comentar todo el programa