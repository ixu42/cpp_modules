#!/bin/bash

make re

PROG=./RPN

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
RESET='\033[0m'

OUTFILE='output.log'
ERRFILE='error.log'
EXPECTED_OUT='expected_output.log'
EXPECTED_ERR='expected_error.log'
ERROR_COUNT=0

test_error()
{
	EXP="$1"
	touch $EXPECTED_OUT

	echo -e "${CYAN}\"${EXP}\"${RESET}"

	"$PROG" "$EXP" > $OUTFILE 2> $ERRFILE
	cat $ERRFILE

	if diff $OUTFILE $EXPECTED_OUT > /dev/null \
		&& grep -q "Error" $ERRFILE; then
		echo -e "${GREEN}OK${RESET}"
	else
		echo -e "${RED}KO${RESET}"
		ERROR_COUNT=$((ERROR_COUNT + 1))
	fi

	rm -f $OUTFILE
	rm -f $EXPECTED_OUT
	rm -f $ERRFILE
}

test_valid()
{
	EXP="$1"
	echo "$2" > $EXPECTED_OUT
	touch $EXPECTED_ERR

	echo -e "${CYAN}\"${EXP}\"${RESET}"

	"$PROG" "$EXP" > $OUTFILE 2> $ERRFILE
	cat $OUTFILE

	if diff $OUTFILE $EXPECTED_OUT > /dev/null \
		&& diff $ERRFILE $EXPECTED_ERR > /dev/null; then
		echo -e "${GREEN}OK${RESET}"
	else
		echo -e "${RED}KO${RESET}"
		ERROR_COUNT=$((ERROR_COUNT + 1))
	fi

	rm -f $OUTFILE
	rm -f $EXPECTED_OUT
	rm -f $ERRFILE
	rm -f $EXPECTED_ERR
}

echo -e "${CYAN}\n=== TEST INVALID CASES ===${RESET}"
test_error ''
test_error '(1 + 1)'
test_error '0 42 +'
test_error '0 4+'
test_error '0'
test_error '0 +'
test_error '0 1 + 2'
test_error '1 0 /'

echo -e "${CYAN}\n=== TEST VALID CASES ===${RESET}"
test_valid '8 9 * 9 - 9 - 9 - 4 - 1 +' '42'
test_valid '7 7 * 7 -' '42'
test_valid '1 2 * 2 / 2 * 2 4 - +' '0'
test_valid '  1 2 3 4 5  	+ - * / 	' '-0.0833333'
test_valid '6 7 * 5 6 + - 3 / 4 1 + + 9 * 1 / 1 - 8 + 6 *' '870'
test_valid '9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 5 *' '1.9371e+09'
test_valid '6 7 + 5 * 4 * 3 + 8 * 5 * 1 - 5 * 5 * 2 * 3 + 5 * 5 * 2 * 8 * 3 + 1 - 9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 5 * +' '2.14748e+09'
test_valid '6 7 + 5 * 4 * 3 + 8 * 5 * 1 - 5 * 5 * 2 * 3 + 5 * 5 * 2 * 8 * 3 + 1 - 9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 5 * + 1 2 - * 1 -' '-2.14748e+09'

echo -e "${CYAN}\n=== SUMMARY ===${RESET}"
if [ $ERROR_COUNT -eq 0 ]; then
	echo -e "${GREEN}All tests passed! 😎\n${RESET}"
else
	echo -e "${RED}$ERROR_COUNT test(s) failed 🥹\n${RESET}"
fi

make fclean