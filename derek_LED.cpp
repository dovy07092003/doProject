// Name: derek_LED.cpp
// This file contains the implementation code for the derek_LED.h (from the makeLEDs.cpp)

#include <iostream>
#include <fstream>
#include <sstream>
#include "derek_LED.h"

using namespace std;
#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

LED::LED(int number)
{
	this->number = number;// Deferencing, use "this" as a pointer to use the function in number
	ostringstream s;// Using a strema to conduct a path
	s << LED_PATH << number;// append LED number to LED path
	path = string(s.str());//convert back from stream to string
}

void LED::writeLED(string filename, string value)
{
	ofstream fs;
	fs.open((path + filename).c_str());
     	fs << value;
        fs.close();
}

void LED::removeTrigger()
{
	   writeLED("/trigger", "none");
}

void LED::turnOn()
{
	   cout << "Turning LED" << number << " on." << endl;
	      removeTrigger();
	         writeLED("/brightness", "1");
}

void LED::turnOff()
{
	   cout << "Turning LED" << number << " off." << endl;
	   removeTrigger();
	   writeLED("/brightness", "0");
}

void LED::flash(string delayms = "50")
{
	   cout << "Making LED" << number << " flash." << endl;
	      writeLED("/trigger", "timer");
	         writeLED("/delay_on", delayms);
		    writeLED("/delay_off", delayms);
}

void LED::outputState()
{
	   ifstream fs;
	      fs.open( (path + "/trigger").c_str());
	         string line;
		    while(getline(fs,line)) cout << line << endl;
		       fs.close();
}

LED::~LED()
{// AUTOMATICALLY CALLED 
	   cout << "destroying the LED with path: " << path << endl;
}
