// Name: derek_LED.h
//This is the header file form the makeLESs.cpp

#include <string>

using namespace std;

class LED
{
      private:
	   string path;
	   int number;
	   virtual void writeLED(string filename, string value);
	   virtual void removeTrigger();
					     
      public:
	   LED(int number);// Constructor (same name with the class)	
	   virtual void turnOn();
           virtual void turnOff();
	   virtual void flash(string delayms);
	   virtual void outputState();
	   virtual ~LED();
};
