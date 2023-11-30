#!/bin/bash

is_prime() {
    num=$1
    if [ $num -lt 2 ]; then
        return 1
    fi
    for ((i = 2; i*i <= num; i++)); do
        if [ $((num % i)) -eq 0 ]; then
            return 1
        fi
    done
    return 0
}

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

is_prime $number

if [ $? -eq 0 ]; then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi

reversed=$(reverse_number $number)
echo "Reverse of $number is $reversed"
