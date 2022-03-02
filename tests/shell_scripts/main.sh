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
INFILE_PATH=./tests/shell_scripts/

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

# 単一コマンド＆パス解決あり
TEST_NAME=0007.txt
INPUT_CMDS="cat ./tests/shell_scripts/infile.txt"
EXPECTED_EXIT_STATUS=0
do_test

# パイプ&パス解決あり
TEST_NAME=0008.txt
INPUT_CMDS="cat ./tests/shell_scripts/infile.txt | grep ab"
EXPECTED_EXIT_STATUS=0
do_test

# 単一コマンド＆パス解決あり&infileあり
TEST_NAME=0009.txt
INPUT_CMDS="< ./tests/shell_scripts/infile.txt grep ab"
EXPECTED_EXIT_STATUS=0
do_test

# パイプ&パス解決なし&infileあり
TEST_NAME=0010.txt
INPUT_CMDS="< ./tests/shell_scripts/infile.txt grep ab | wc -c"
EXPECTED_EXIT_STATUS=0
do_test

# builtin env関数
TEST_NAME=buitlin_env.txt
echo "> env" > ${EXPECTED_PATH}/${TEST_NAME}
env | grep -v "_=">> ${EXPECTED_PATH}/${TEST_NAME}
echo _=./minishell >> ${EXPECTED_PATH}/${TEST_NAME}
echo LINES=24 >> ${EXPECTED_PATH}/${TEST_NAME}
echo  COLUMNS=80 >> ${EXPECTED_PATH}/${TEST_NAME}
echo  -n "> " >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS="env"
EXPECTED_EXIT_STATUS=0
do_test

# builtin cd関数(相対パスの場合）
# 終了ステータスのみを確認
TEST_NAME=buitlin_cd_relative.txt
echo "> cd ./tests/google_tests" > ${EXPECTED_PATH}/${TEST_NAME}
echo  -n "> " >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS="cd ./tests/google_tests"
EXPECTED_EXIT_STATUS=0
do_test

# builtin cd関数(絶対パスの場合）
# 終了ステータスのみを確認
TEST_NAME=buitlin_cd_absolute.txt
echo "> cd /tmp" > ${EXPECTED_PATH}/${TEST_NAME}
echo  -n "> " >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS="cd /tmp"
EXPECTED_EXIT_STATUS=0
do_test
