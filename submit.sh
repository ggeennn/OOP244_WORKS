#!/bin/bash

# Define constants
SUBJECT_CODE="44"
SECTION="ncc"

# Prompt user for workshop number
read -p "Enter the workshop number (1-10): " WORKSHOP_NUMBER

# Validate workshop number
if [[ ! "$WORKSHOP_NUMBER" =~ ^(10|[1-9])$ ]]; then
    echo "Invalid workshop number. Please enter a number between 1 and 10."
    exit 1
fi

# Prompt user for submission type
read -p "Do you want to submit lab or reflection? (lab/ref): " SUBMISSION_TYPE

# Construct the submission command
if [[ "$SUBMISSION_TYPE" == "lab" ]]; then
    COMMAND="~reza.khojasteh/submit 2$SUBJECT_CODE/w$WORKSHOP_NUMBER/lab_$SECTION"
elif [[ "$SUBMISSION_TYPE" == "ref" ]]; then
    COMMAND="~reza.khojasteh/submit 2$SUBJECT_CODE/w$WORKSHOP_NUMBER/ref_$SECTION"
else
    echo "Invalid submission type. Please enter 'lab' or 'ref'."
    exit 1
fi

# Output the command
echo "Your submission command is:"
echo "$COMMAND"

# Execute the submission command
eval "$COMMAND"