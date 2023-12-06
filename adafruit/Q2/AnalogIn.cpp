// File name: AnalogIn.cpp
// This is the implementation file for the AnalogIn.h
//

#include "AnalogIn.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

AnalogIn::AnalogIn()
{

}

AnalogIn::AnalogIn(unsigned int n)
{       
	number = n;
}  

void AnalogIn::setNumber(unsigned int n)
{       
	        
}  

int AnalogIn::readAdcSample()
{      
        int adc_value	
	stringstream ss;
	ss << ADC_PATH << number << "_raw"; // from exploringBB/chp11/tmp36adc
	fstream fs;
	fs.open(ss.str().c_str(), fstream::in);
	fs >> adc_value;
	fs.close();
	return adc_value;
}  

AnalogIn::~AnalogIn()
{       
	        
}  
