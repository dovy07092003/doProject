#!/bin/bash
echo "Building the build_temp.sh file"
g++ AnalogIn.cpp publish_temp.cpp -o publish_tempcpp -lpaho-mqtt3c
echo "The compilation file's name is publish_tempcpp"
echo "Done"
