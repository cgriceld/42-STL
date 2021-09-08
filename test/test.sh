#!/bin/bash

WHITE="\033[0m\n"
GREEN="\033[1;32m"
YELLOW_BOLD="\033[1;33m"
YELLOW="\033[0;33m"
RED="\033[1;31m"
CYAN="\033[0;36m"

FLAGS="-Wall -Wextra -Werror -std=c++98"

function run()
{
	clang++ $FLAGS $2_test.cpp -o $1_$2_test
}

function change_space()
{
	sed -i '' -e "s/$1::$3/$2::$3/g" -e "s/$1::swap/$2::swap/g" $3_test.cpp test_utils.hpp
}

function check()
{
	diff std_$1.txt ft_$1.txt > log_$1.txt && echo -e "✅ $GREEN TEST PASSED ! $WHITE" || echo -e "❌ $RED ERROR, CHECK OUT log_$1.txt FILE ! $WHITE"
	if [ ! -s log_$1.txt ]
	then
		rm log_$1.txt
	fi
	echo -e "⏰ $CYAN TIME TEST "
	echo "std : " `(time ./std_$1_test) 2>&1 | grep real | cut -f 2`
	echo -e "ft :  " `(time ./ft_$1_test) 2>&1 | grep real | cut -f 2` $WHITE
}

function routine()
{
	echo -e "$YELLOW_BOLD ============== $1 TEST ============== \n"

	run ft $1
	change_space ft std $1
	run std $1
	change_space std ft $1

	./std_$1_test > std_$1.txt 2>&1
	./ft_$1_test > ft_$1.txt 2>&1

	check $1
}

echo -e "\n$YELLOW Runs all tests first with ft::, then change to std::, runs same tests again and compare outputs $WHITE"

declare -a cntr=("vector" "stack");

for i in "${cntr[@]}"
do
	routine "$i"
done
