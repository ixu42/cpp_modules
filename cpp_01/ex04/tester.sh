#!/bin/bash

make re

PROG="./sed"

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

check_replacement()
{
	local	FILE="$1"
	local	S1="$2"
	local	S2="$3"

	echo "Replace $S1 with $S2 in $FILE"
	"$PROG" "$FILE" "$S1" "$S2"

	sed "s/$S1/$S2/g" "$FILE" > "expectedFile"

	if cmp -s "${FILE}.replace" "expectedFile"; then
		echo -e "${GREEN}OK${RESET}"
	else
		echo -e "${RED}KO${RESET}"
	fi

	rm "expectedFile"
	rm "${FILE}.replace"
}

FILE_DIR="./test_files"

check_replacement "${FILE_DIR}/SedIsForLosers" "Sed" "Perl"
check_replacement "${FILE_DIR}/FooLand" "FooLand" "WonderLand"
check_replacement "${FILE_DIR}/FooLand" "bar" "baz"
