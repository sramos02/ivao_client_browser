#include <fstream>
#include <sstream>
#include "Client.h"

//Program methods
void updateFile();
void getCallsign(string & callsign);
void searchEngine(ifstream & file, const string callsign);
Client readClient(ifstream & file, const string line);


int main() {
    ifstream file;
    string callsign;
    vector<string> information;

    updateFile();
    getCallsign(callsign);
    searchEngine(file, callsign);

    return 0;
}

//Get the callsign information from input and return it
void getCallsign(string & callsign) {
    cout << "Search for a Callsign: ";
    cin >> callsign;
    for(int i= 0; i < callsign.length(); i++) toupper(callsign[i]);

}

//Search for a callsign in the file text file provided and print information about client id exists
void searchEngine(ifstream & file, const string callsign) {
    file.open("status.txt");
    if(!file.is_open()) {
        cout << "Can't openfile, try again.\n";
        exit(1);
    }


    //Read header
    string line;
    while (line != "!CLIENTS"){
        getline(file, line);
    }

    //Read Clients
    //TODO LONGITUD 0 NO CONTEMLPADA
    getline(file, line);
    Client clt = readClient(file, line);
    bool found = clt.found(callsign);

    while (line != "!SERVERS" && !found){
        getline(file, line);
        clt = readClient(file, line);
        found |= clt.found(callsign);
    }

    file.close();
    if(found) clt.toString();
    cout << "\nThis VID do not match with any online user.\n";
}

//Update the file txt from webpage
//TODO update system
void updateFile() {
    char buf[BUFSIZ];
    size_t size;

    FILE * source = fopen("http://api.ivao.aero/getdata/whazzup/whazzup.txt", "rb");
    FILE * output = fopen("cmake-build.debug/file.txt", "wb");

    while (size = fread(buf, 1, BUFSIZ, source)) {
        fwrite(buf, 1, size, output);
    }

    fclose(source);
    fclose(output);
}

//Recieve a client information and split it by ":" returning it if exists in the file
Client readClient(ifstream &file, const string line) {
    vector<string> words;


    stringstream ss(line);
    string aux;
    while (getline(ss, aux, ':')){
        words.push_back(aux);
    }

    //Start with basic data, enough for know about callsign and connection type
    string callsign = words[0], vid = words[1], name = words[2];

    Client ret = Client(callsign, vid, name);
    if (words.at(3) == "PILOT") ret.createPilot(words);
    else if (words.at(3) == "ATC") ret.createATC(words);
    else ret.createObserver(words);

    return ret;
}