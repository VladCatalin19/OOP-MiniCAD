#! /bin/sh

EXECUTABLE_PATH="../build/tema2"
INPUT_FOLDER_PATH="input"
OUTPUT_FOLDER_PATH="output"

for input_file in $(ls "$INPUT_FOLDER_PATH"); do
    output_image="$(basename $input_file .in).png"
    "$EXECUTABLE_PATH" "$INPUT_FOLDER_PATH/$input_file" "$OUTPUT_FOLDER_PATH/$output_image"
    echo "Processed $input_file"
done
