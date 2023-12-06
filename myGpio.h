// File name: myGpio.h
// This is the header file for a simple gpio class
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
#ifndef MYGPIO_H
#define MYGPIO_H

enum GPIO_DIRECTION{ INPUT, OUTPUT };
enum GPIO_VALUE {LOW, HIGH};

class MYGPIO
{
	private:
		int number;
		int dir_val;
		string name, path;
		int write(string path, string filename, string value);
		int write(string path, string filename, int value);
		string read(string path, string filename);
		ofstream stream;

	public:
		MYGPIO(int number);// constructor
		int getNumber();
		void setDirection(GPIO_DIRECTION dir);
		GPIO_DIRECTION getDirection();
		int setValue(GPIO_VALUE val);
		GPIO_VALUE getValue();
		void toggleOutput();
		~MYGPIO(); // destructor



};
#endif
