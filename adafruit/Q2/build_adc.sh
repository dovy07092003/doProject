# File name: build_adc.sh
# This is the build file for the analog to digital converter

#!/bin/bash
echo Compiling AnalogIn.cpp and test_analog.cpp
g++ -Wall AnalogIn.cpp test_analog.cpp -o test_analogcpp
echo "Done.The name of the executed file is test_analogcpp"

