#!/bin/sh
python seweolo140416.py "$1" "$2" "$3" && grep -C 5 "$2" README.md
