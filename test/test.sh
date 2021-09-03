#!/bin/bash

WHITE="\033[0m\n"
GREEN="\033[1;32m"
YELLOW_BOLD="\033[1;33m"
YELLOW="\033[0;33m"
RED="\033[1;31m"

FLAGS="-Wall -Wextra -Werror -std=c++98"

function run()
{
	clang++ $FLAGS $2_test.cpp -o $1_$2_test
}

function change_space()
{
	sed -i '' "s/$1::$3/$2::$3/" $3_test.cpp test_utils.hpp
}

function check()
{
	diff std_$1.txt ft_$1.txt > log_$1.txt && echo -e "✅ $GREEN TEST PASSED ! $WHITE" || echo "❌ $RED ERROR, CHECK OUT log_$1.txt FILE ! $WHITE"
	if [ ! -s log_$1.txt ]
	then
		rm log_$1.txt
	fi
}

echo -e "\n $YELLOW_BOLD ============== VECTOR TEST ============== \n"
echo -e "$YELLOW Runs tests first with ft::, then change to std::, runs tests again and compare outputs $WHITE"

run ft vector
change_space ft std vector
run std vector
change_space std ft vector

./std_vector_test > std_vector.txt
./ft_vector_test > ft_vector.txt

check vector
