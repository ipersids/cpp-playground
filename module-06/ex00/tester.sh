#!/bin/bash

# Path to your converter executable
CONVERTER="./convert"

# List of test inputs
tests=(
  "0"
  "42"
  "-42"
  "a"
  "Z"
  " "
  "nonprintable"
  "127"
  "128"
  "256"
  "2147483647"      # INT_MAX
  "-2147483648"     # INT_MIN
  "3.14"
  "-0.001"
  "1.0e2"
  "1.23e+4"
  "45.0000"
  "45.0000e+2"
  "45.0000e-2"
  "nan"
  "inf"
  "-inf"
  "+inf"
  "NAN"
  "INF"
  "nanf"
  "inff"
  "notanumber"
  "123.0000e+2"
  " "
  ""
)

# Run each test
for input in "${tests[@]}"; do
  echo "==== Input: '$input' ===="
  $CONVERTER "$input"
  echo ""
done
