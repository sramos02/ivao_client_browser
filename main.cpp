#include <fstream>
#include <sstream>
#include <algorithm>
#include "Data/Client.h"

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

    //Make it upperCase
    transform(callsign.begin(), callsign.end(),callsign.begin(), ::toupper);
}

//Search for a callsign in the file text file provided and print information about client id exists
void searchEngine(ifstream & file, const string callsign) {
    file.open("status.txt");
    if(!file.is_open()) {
        cout << "Can't open file, try again.\n";
        exit(1);
    }


    //Read header
    string line;
    while (line != "!CLIENTS"){
        getline(file, line);
    }

    //Read Clients
    Client clt = Client();
    bool found = false, end = false;

    while (!found && !end){
        getline(file, line);
        if (line == "!AIRPORTS") end = true;
        else {
            clt = readClient(file, line);
            found |= clt.found(callsign);
        }
    }

    file.close();

    if(found) clt.toString();
    else cout << "\nThis VID do not match with any online user.\n";
}

//Update the file txt from webpage
//TODO update system
void updateFile() {
    /*
    string url = "http://api.ivao.aero/getdata/whazzup/whazzup.txt";
    CURL * curl;
    CURLcode result;
    curl = curl_easy_init();
    char buf[BUFSIZ];
    size_t size;
    FILE * source = fopen("http://api.ivao.aero/getdata/whazzup/whazzup.txt", "rb");
    FILE * output = fopen("cmake-build.debug/file.txt", "wb");
    while (size = fread(buf, 1, BUFSIZ, source)) {
        fwrite(buf, 1, size, output);
    }
    fclose(source);
    fclose(output);
    */
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
    if (words.at(3) == "PILOT" || words.at(3) == "FOLME") ret.createPilot(words);
    else if (words.at(3) == "ATC") ret.createATC(words);
    else ret.createObserver(words);

    return ret;
}