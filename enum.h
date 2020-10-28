
#ifndef UNTITLED_ENUM_H
#define UNTITLED_ENUM_H

namespace my_enums
{
    enum clientType{PILOT = 0, ATC = 1, FOLME = 2};
    enum facilities{OBS = 0, INF = 1, DEL = 2, GND = 3, TWR = 4, APP = 5, ACC = 6, DEP = 7};
    enum administrativeVersion{SUS = 0, vOBS = 1, USR = 2, SUP = 11, ADM = 12};
    enum pilotVersion{pOBS = 1, AS1 = 2, AS2 = 3, AS3 = 4, ADC = 5, APC =6, pAAC = 7, SEC = 8, SAI = 9, CAI = 10};
    enum atcVersion{aOBS = 1, FS1 = 2, FS2 = 3, FS3 = 4, PP = 5, SPP = 6, CP = 7, ATP = 8, SFI = 9, CFI = 10};
    enum simulator{UNK = 0, FS95 = 1, FS98 = 2, MCFS = 3, FS2000 = 4, MCFS2 = 5, FS2002 = 6, CFS3 = 7, FS2004 = 8, FSX = 9, XPU = 11, XP8 = 12, XP9 = 13, XP10 = 14, PS1 = 15, XP11 = 16, XP12 = 17, FLY = 20, FLY2 = 21, FLTG = 25, P3D = 30};

}

#endif //UNTITLED_ENUM_H