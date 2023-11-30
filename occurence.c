#!/bin/bash

count_occurrences() {
    string=$1
    substring=$2
    count=$(grep -o $substring <<< $string | wc -l)
    echo $count
}

echo -n "Enter a string: "
read input_string

echo -n "Enter the substring to search for: "
read search_substring

result=$(count_occurrences "$input_string" "$search_substring")

echo "The substring '$search_substring' occurs $result times in the string '$input_string'."
