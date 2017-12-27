#include "soapyhackrf.h"
#include <iostream>
#include <stdexcept>

#include <soapyhackrf.h>

using namespace std;
using namespace SoapySDR;

SoapyHackRF::SoapyHackRF()
{

}

void SoapyHackRF::probe(){
    KwargsList devices = Device::enumerate();
    for (size_t i = 0; i < devices.size(); i++){
        cout << "Found device: " << (int)i << endl;
        map<string, string>::iterator it;

        for (auto const& p : devices.at(i)){
            std::cout << p.first << ":" << p.second << endl;
        }
    }
}

void SoapyHackRF::connect(){
    Kwargs args;
    args["driver"] = "hackrf";
    hackrf = Device::make(args);

    if(hackrf == NULL){
         throw runtime_error("device make failed!");
    }
}

void SoapyHackRF::listInfo(){
    if(hackrf == NULL){
        return;
    }

    vector<string> antennas = hackrf->listAntennas(SOAPY_SDR_RX,0);
    for (auto const& antenna : antennas){
        std::cout << antenna << endl;
    }
}

void SoapyHackRF::disconnect(){
    if(hackrf != NULL){
         Device::unmake(hackrf);
    }
}
