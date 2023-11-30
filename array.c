#!/bin/bash

print_array() {
    for element in "${array[@]}"; do
        echo -n "$element "
    done
    echo
}

array=(7 2 10 5 3)

echo "Original array:"
print_array

sorted_array=($(for element in "${array[@]}"; do echo "$element"; done | sort -n))

echo "Sorted array in ascending order:"
for element in "${sorted_array[@]}"; do
    echo -n "$element "
done
echo
