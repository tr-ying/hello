#!/bin/bash

reverse_number() {
    num=$1
    rev=0
    while [ $num -gt 0 ]; do
        digit=$((num % 10))
        rev=$((rev * 10 + digit))
        num=$((num / 10))
    done
    echo $rev
}

echo -n "Enter a number: "
read number

reverse=$(reverse_number $number)

if [ $number -eq $reverse ]; then
    echo "$number is a palindrome."
else
    echo "$number is not a palindrome."
fi

echo "Reverse of $number is $reverse"
