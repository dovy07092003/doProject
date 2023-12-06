# Name: process_data.py
# The program parse the feed data for the temperature 
# Print out min, max, average values 
# Run: ./build_process_data.sh data_file.csv

import sys
import csv # To process csv file

f_data = open(sys.argv[1])
reader = csv.reader(f_data)
headings = []
headings = next(reader)

out = []
for line in reader:
    out.append(float(line[1]))

print("The temperature value is")
print(out)

sum = 0
ele = len(out)
print("There are ",ele, " temperature value")
i = 0
while(i < ele):
    sum+=out[i]
    i+=1
print("Sum",sum)

average = sum/ele
print("The average temperature is ", average)

a = out[0]
k = 1
# Find MIN
while(k < ele):
    if (a > out[k]):
        a = out[k]
    k = k + 1
print("The minimum temperature is ",a)

# Find MAX
b = out[0]
n = 1
while(n < ele):
    if (b < out[n]):
            b = out[n]
    n = n + 1
print("The maximum temperature is ", b)
