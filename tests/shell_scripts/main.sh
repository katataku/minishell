#!/bin/bash

ACTUAL_PATH=./tests/shell_scripts/actual/
EXPECTED_PATH=./tests/shell_scripts/expected/

# input, test_name
function do_test() {
	echo "${INPUT_CMDS}" | ./minishell > "${ACTUAL_PATH}${TEST_NAME}"

    echo -n "[${TEST_NAME}] status: "
    if [ $? -eq "${EXPECTED_EXIT_STATUS}" ] ;then
		echo -n "OK, "
	else
		echo -n "NG, "
	fi

    echo -n "feature: "
	if  diff "${ACTUAL_PATH}${TEST_NAME}" "${EXPECTED_PATH}${TEST_NAME}"  ;then
		echo "OK"
	else
		echo "NG"
	fi
}

# 単一コマンド＆パス解決なし
TEST_NAME=0001.txt
INPUT_CMDS=$(cat << EOS
/bin/echo hello
EOS
)
EXPECTED_EXIT_STATUS=0

do_test

# パイプ&パス解決なし
#TEST_NAME=0002.txt
#INPUT_CMDS=$(cat << EOS
#/bin/echo hello2
#EOS
#)
#EXPECTED_EXIT_STATUS=0
#do_test
