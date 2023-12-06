#!/bin/bash
echo "Building in process for the build_receive_temp.sh file"
g++ AnalogIn.cpp derek_LED.cpp receive_temp.cpp -o receivetemp -lpaho-mqtt3c
echo "Done. The name of the file is receivetemp"
