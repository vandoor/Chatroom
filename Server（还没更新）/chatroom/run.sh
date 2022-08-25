#!/bin/bash
chmod +x ./run.sh
g++ ./CJsonObject/cJSON.c -c
g++ ./CJsonObject/CJsonObject.cpp -c
g++ main.cpp  -c
g++ Database.cpp -c
g++ cJSON.o CJsonObject.o main.o Database.o -lpthread -lsqlite3 -o main.out
rm cJSON.o
rm main.o
rm CJsonObject.o
./main.out


