#include "../Client.h"
#include "../FlightPlan.h"

#ifndef IVAO_PROJECT_PILOTS_H
#define IVAO_PROJECT_PILOTS_H

class Pilots: public Client {
private:
    string gnd_speed;
    FlightPlan flt_plan;
    string transponder;
    string facility;
    string visual_range;
    string heading;
    string on_gnd;
    string simulator;
    string plane;
public:

};
#endif //IVAO_PROJECT_PILOTS_H
