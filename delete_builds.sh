#!/usr/bin/env bash

rm src/main.o
rm src/ui.o
rm src/network.o
rm src/models.o
rm m3

if [ "$1" = "--and-rebuild" ]; then
    make
fi

if [ "$1" = "--and-rebuild-with-run" ]; then
    make
    ./m3
fi
