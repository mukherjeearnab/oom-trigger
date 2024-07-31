#!/bin/bash

gcc -o memproc ./memproc.c

counter=0

while :; do
    # run an instance of memproc in the background
    ./memproc &

    # sleep for some time
    # sleep 0.01

    # if memory is low, pkill and exit
    if [ $(awk '/^MemAvailable:/ { print $2; }' /proc/meminfo) -lt 16 ]; then

        if [ $(awk '/^SwapFree:/ { print $2; }' /proc/meminfo) -lt 16 ]; then
            ((counter++))
        fi

        if [ $((counter)) -eq 10 ]; then
            pkill -u $USER
        fi
    fi
done