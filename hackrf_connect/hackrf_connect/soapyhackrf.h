#ifndef SOAPYHACKRF_H
#define SOAPYHACKRF_H

#include <SoapySDR/Device.hpp>

class SoapyHackRF
{
private:
    SoapySDR::Device* hackrf;

public:
    SoapyHackRF();

    void probe();

    void connect();

    void disconnect();

    void listInfo();
};

#endif // SOAPYHACKRF_H
