#include <fstream>
#include <exception>
#include "Data/Client.h"

//Exceptions
class openFileException: public exception
{
    virtual const char* what() const throw(){
        return "Something goes wrong, try again.";
    }
} myex;


int main() {
    //Write statux.txt from web
    //TODO

    //Open the file and get the information from status.txt
    ifstream status;
    try {
        status.open("status.txt");
        cout << "File loaded successfully\n";

        //Read header
        string readed;
        while (readed != "!CLIENTS"){
            getline(status, readed);
        }

        //Read Clients
        while (readed != "!SERVERS"){


            if(readed !=  "!SERVERS") getline(status, readed);
        }

    }
    catch (exception &e){
        cout << e.what() << endl;
        return 1;
    }

    int callsign;
    cout << "Search for a Callsign: ";
    cin >> callsign;

    return 0;
}
