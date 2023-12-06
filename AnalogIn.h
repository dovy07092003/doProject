// File name: Analogln.h
// This is the header file for the analog-to-digital converter
//
#include <iostream>
#include <sstream>
using namespace std;
class AnalogIn
{
	private:
		unsigned int number;
	public:
		AnalogIn();
		AnalogIn(unsigned int n);
		virtual unsigned int getNumber() {return number;}// Inline function implementation
		virtual void setNumber(unsigned int n);
		virtual int readAdcSample();
		virtual~AnalogIn();

};

