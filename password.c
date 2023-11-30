#!/bin/bash

generate_password() {
    length=$1

    lowercase="abcdefghijklmnopqrstuvwxyz"
    uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    numbers="0123456789"
    special_chars="!@#$%^&*()-_+="

    all_chars="${lowercase}${uppercase}${numbers}${special_chars}"

    password=""
    for ((i = 0; i < length; i++)); do
        char="${all_chars:RANDOM % ${#all_chars}:1}"
        password="${password}${char}"
    done

    echo "$password"
}

echo -n "Enter the length of the password: "
read password_length

if [ $password_length -lt 8 ]; then
    echo "Password length should be at least 8 characters."
else
    generated_password=$(generate_password $password_length)
    echo "Generated strong password: $generated_password"
fi
