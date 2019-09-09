#!/bin/bash

date
echo "cmd:$0 $1";

opt=$1
dir="_build"

if [ ${opt} == "all" ]
then
    rm -rf ${dir} 
    mkdir ${dir} 
    cd ${dir} 
    cmake ..
    make 
elif [ ${opt} == "clean" ]
then
    cd ${dir} 
    make clean
else
    cd ${dir} 
    make
fi

