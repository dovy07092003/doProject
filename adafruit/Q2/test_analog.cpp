// File name: test_analog.cpp
// This is the testing file for the AnalogIn.cpp
//
#include "AnalogIn.h"

int main(int argc, char *argv[])
{
	AnalogIn temp_ss(0);
	short int num = temp_ss.getNumber();
	cout << "The pin number is "<<num<<endl;
	short int adc = temp_ss.readAdcSample();
	cout << "The status of the pin " <<num<<" is "<<adc<<endl;
	
}

