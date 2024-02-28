#!/bin/bash

EXECUTABLE="./bin/diarrhea"

# Run the executable in the background, not sure 2>&1 is for but it works
$EXECUTABLE > /dev/null 2>&1 &
