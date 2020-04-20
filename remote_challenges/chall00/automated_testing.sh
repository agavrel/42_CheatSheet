#!/usr/bin/env bash

# Continuous testing, ctrl+c to interrupt
if [ $# -eq 0 ]; then
    echo "provide 1 file to watch as argument\n"
    exit 1
fi

# only for VS code
code $1 && 
# check if the file provided as argument has changed, recompile file and run it
while inotifywait -e close_write $1; do echo -e "\n" && gcc $1 && ./a.out && echo -e "\n"; done		
