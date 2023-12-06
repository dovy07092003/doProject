// File name: myGpio.cpp
// This is the implement file from myGpio.h
//
#include "myGpio.h"

// Private
int MYGPIO::write(string path, string filename, string value)
{
	ofstream fs;
	fs.open((path+filename)).c_str();
	if(!fs.is_open())
	{
		perror("GPIO: write failed to open file");
		return -1;
	}
	fs <<value;
	fs.close();
	return 0;
}


int MYGPIO::write(string path, string filename, int value)
{       
	/*stringstream s;
	s<<value;
	return write(path,filename,s.str());*/
}

string MYGPIO::read(string path, string filename)
{       
	ifstream fs;
	fs.open((path+filename).c_str());
	if (!fs.open())
	{
		perror("GPIO: read failed to open file");

	}
	/*string input;
	getline(fs,input);
	fs.close();*/
}


// Public
MYGPIO::MYGPIO(int number)
{       
 number = number;
}

int MYGPIO::getNumber()
{       
 return number;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir)
{       

}

GPIO_DIRECTION MYGPIO:: getDirection()
{

}
int MYGPIO::setValue(GPIO_VALUE val)
{       
 dir_val =val;
}

GPIO_VALUE MYGPIO:: getValue()
{
  string input = read(path, "value");
  if (input == "0")
  {
	  return LOW;
  }
  else
  {
	  return HIGH;
  }
}
void MYGPIO::toggleOutput()
{       

}

MYGPIO::~MYGPIO()
{       

}

