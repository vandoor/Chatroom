#!/bin/bash
chmod +x ./run.sh
g++ ../cJSON.c -c
g++ ../CJsonObject.cpp -c
g++ demo.cpp -c
g++ cJSON.o CJsonObject.o demo.o -o demo.out
rm cJSON.o
rm demo.o
rm CJsonObject.o
./demo.out

