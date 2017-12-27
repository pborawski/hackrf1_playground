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

    std::cout << endl << "Antennas: |";
    vector<string> antennas = hackrf->listAntennas(SOAPY_SDR_RX,0);
    for (auto const& antenna : antennas){
        std::cout << antenna << "|";
    }

    std::cout <<endl << "Gains: |";
    vector<string> gains = hackrf->listGains(SOAPY_SDR_RX,0);
    for (auto const& gain : gains){
        std::cout << gain << "|";
    }

    std::cout <<endl << "Bandwidths (Mhz): |";
    vector<double> bandwidths = hackrf->listBandwidths(SOAPY_SDR_RX,0);
    for (auto const& bandwidth : bandwidths){
        std::cout << bandwidth/1.0e6 << "|";
    }

    std::cout <<endl << "Frequencies: |";
    vector<string> frequencies = hackrf->listFrequencies(SOAPY_SDR_RX,0);
    for (auto const& frequency : frequencies){
        std::cout << frequency << "|";
    }



    std::cout <<endl;
}

void SoapyHackRF::disconnect(){
    if(hackrf != NULL){
         Device::unmake(hackrf);
    }
}
