#!/bin/bash
echo "Building for the build_pushbutton.sh"
g++ GPIO.cpp pushbutton.cpp -o pushbutton -pthread -lpaho-mqtt3c
config-pin -q p8.16
config-pin p8.16 gpio_pu
config-pin -q p8.16 
echo "Done. The file name is pushbutton"
