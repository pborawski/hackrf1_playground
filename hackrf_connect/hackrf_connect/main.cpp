#include <iostream>
#include <SoapySDR/Device.hpp>
#include <soapyhackrf.h>

using namespace std;
using namespace SoapySDR;

int main()
{
    try{
        SoapyHackRF* hackrf = new SoapyHackRF();
        hackrf->probe();
        hackrf->connect();
        hackrf->listInfo();
        hackrf->disconnect();
    }
    catch(runtime_error& ex){
        cerr << ex.what() << endl;
        return -1;
    }

    return 0;
}
