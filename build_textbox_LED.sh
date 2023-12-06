#!/bin/bash
echo "Building file for the textbox_LED.cpp"
g++ derek_LED.cpp textbox_LED.cpp -o textboxLED -lpaho-mqtt3c
echo "Done. The name is textboxLED"

