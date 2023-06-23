#!/bin/bash
wget -q --output-document=$PWD/libfile.so https://github.com/catherinekimani/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libfile.so
export LD_PRELOAD=$PWD/libfile.so