#!/bin/bash

# Define constants
SUBJECT_CODE="44"
SECTION="ncc"

# Prompt user for workshop number with input validation
while true; do
    read -p "Enter the Milstone number (1-10): " MILSTONE_NUMBER
    if [[ "$MILSTONE_NUMBER" =~ ^(10|[1-9])$ ]]; then
        break  # Valid input, exit the loop
    else
        echo "Invalid Milstone number. Please enter a number between 1 and 10."
    fi
done

COMMAND="~reza.khojasteh/submit 2$SUBJECT_CODE/prj/m$MILSTONE_NUMBER"

# Output the command
echo "Your submission command is:"
echo "$COMMAND"

# Execute the submission command
eval "$COMMAND"