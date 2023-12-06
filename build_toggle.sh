#!/bin/bash
echo "Building file for the toggle.cpp"
g++ GPIO.cpp toggle.cpp -o toggle -pthread -lpaho-mqtt3c
echo "Done. The name is toggle"

