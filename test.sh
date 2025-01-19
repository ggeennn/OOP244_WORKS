#!/bin/bash

# Compile the code
g++ -Wall -std=c++11 -g -o ws *.cpp

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful, running the program..."
    
    # Run the program and use valgrind to check for memory leaks
    # Start recording the session, redirecting valgrind output to a log file and ensuring only ws interaction is captured in program_output.txt
    script -q -c "valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws" program_output.txt

    # Check if output.txt exists
    if [ -f "correct_output.txt" ]; then
        echo "Comparing program output with output.txt..."
        diff program_output.txt correct_output.txt
        
        # Check if diff found any differences
        if [ $? -eq 0 ]; then
            echo "No differences found. The outputs are identical."
        else
            echo "Differences found between program output and output.txt."
        fi
    else
        echo "No standard output to compare."
    fi
else
    echo "Compilation failed, please check the code."
fi

# Check if the compiled file exists and prompt for overwrite
if [ -f "ws" ]; then
    echo "The compiled file 'ws' already exists. It will be overwritten."
fi