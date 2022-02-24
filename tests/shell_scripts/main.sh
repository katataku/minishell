#!/bin/bash

NC="\033[0m"
BOLD="\033[1m"
ULINE="\033[4m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"

ACTUAL_PATH=./tests/shell_scripts/actual/
EXPECTED_PATH=./tests/shell_scripts/expected/

# input, test_name
function do_test() {
	IS_OK=1
	echo "${INPUT_CMDS}" | ./minishell > "${ACTUAL_PATH}${TEST_NAME}"

	echo -n "[${TEST_NAME}] status: "
	if [ $? -eq "${EXPECTED_EXIT_STATUS}" ] ;then
		printf "OK, "
	else
		printf "${RED}NG${NC}, "
		IS_OK=0
	fi

	echo -n "feature: "
	if  diff "${ACTUAL_PATH}${TEST_NAME}" "${EXPECTED_PATH}${TEST_NAME}" > /dev/null ;then
		echo -n "OK"
	else
		printf "${RED}NG${NC}"
		IS_OK=0
	fi

	if [ $IS_OK -eq 1 ] ; then
		printf " ${GREEN}[✓]${NC}\n"
	else
		printf " ${RED}[-]${NC}\n"
	fi
}

# 単一コマンド＆パス解決なし
TEST_NAME=0001.txt
INPUT_CMDS="/bin/echo hello"
EXPECTED_EXIT_STATUS=0
do_test

# パイプ&パス解決なし
TEST_NAME=0002.txt
INPUT_CMDS="/bin/echo hello | /usr/bin/rev"
EXPECTED_EXIT_STATUS=0
do_test

# 単一コマンド＆パス解決なし&infileあり
TEST_NAME=0003.txt
INPUT_CMDS="< ./tests/shell_scripts/infile.txt /usr/bin/grep ab"
EXPECTED_EXIT_STATUS=0
do_test

# パイプ&パス解決なし&infileあり
TEST_NAME=0004.txt
INPUT_CMDS="< ./tests/shell_scripts/infile.txt /usr/bin/grep ab | /usr/bin/wc -c"
EXPECTED_EXIT_STATUS=0
do_test

# builtin関数単体
TEST_NAME=0005.txt
INPUT_CMDS="echo -n Hello World !"
EXPECTED_EXIT_STATUS=0
do_test

# builtin関数withパイプ
TEST_NAME=0006.txt
INPUT_CMDS="echo -n Hello World ! | /bin/cat"
EXPECTED_EXIT_STATUS=0
do_test
