#!/bin/bash

val=0
for i in "$@";do
    if [ $i != 1 ]
    then
        echo $i" != 1: true"
    else
        echo $i" != 1: false"
    fi
    done
