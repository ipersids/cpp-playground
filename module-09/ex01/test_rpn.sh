#!/bin/bash

RPN_EXEC=./RPN

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

run_test() {
  local expr="$1"
  local expected="$2"

  echo -n "Test: \"$expr\" ... "

  output=$($RPN_EXEC "$expr" 2>&1)

  # Compare output ignoring ANSI color codes (strip them with sed)
  clean_output=$(echo "$output" | sed -r 's/\x1B\[[0-9;]*[mK]//g')

  if [ "$clean_output" == "$expected" ]; then
    echo -e "${GREEN}PASS${NC}"
  else
    echo -e "${RED}FAIL${NC}"
    echo -e "  Expected: $expected"
    echo -e "  Got:      $clean_output"
  fi
}

# Basic operations
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "3 4 +" "7"
run_test "5 1 2 + 4 * + 3 -" "14"

run_test "2 3 + 5 * 6 2 / -" "22"
run_test "1 2 + 3 4 + *" "21" 
run_test "7 2 3 * - 4 +" "5"


# Division by zero
run_test "9 0 /" "Error: Division by zero"

# Invalid operands
run_test "10 2 +" "Error: Invalid symbol: 10"
run_test "a 2 +" "Error: Invalid symbol: a"

# Invalid operators
run_test "2 3 ^" "Error: Invalid symbol: ^"
run_test "2 3" "Error: Too many operands left: 2"

# Not enough operands
run_test "+" "Error: Invalid operation: Not enough operands"
run_test "1 +" "Error: Invalid operation: Not enough operands"

# Overflowing Expression
run_test "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "Error: Out of range: Integer overflow"

# Complex nested expression
run_test "4 5 + 2 3 + * 7 -" "38"
run_test "9 8 + 7 - 6 * 5 /" "12"
run_test "1 2 + 3 4 + * 5 6 + * 7 8 + * 9 9 + *" "62370"


# Multiple pushes without operators
run_test "1 2 3 4 5" "Error: Too many operands left: 5"

# Division results in integer division
run_test "9 4 /" "2"  # 9/4 = 2 integer division

# Multiplying zero
run_test "0 3 *" "0"

# Longer expression (~40 tokens)
run_test "1 2 + 3 4 + * 5 6 + * 7 8 + * 9 9 + * 1 1 + * 2 2 + * 3 3 + *" "2993760"
run_test "1 2 3 4 5 6 7 8 9 + + + + + + + +" "45"

echo "All tests done."