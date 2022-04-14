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
	echo "${INPUT_CMDS}" | ./minishell > "${ACTUAL_PATH}${TEST_NAME}" 2>&1

	if [ $? -eq "${EXPECTED_EXIT_STATUS}" ] ;then
	  echo -n "[${TEST_NAME}] status: "
		printf "OK, "
	else
	  echo -n "[${TEST_NAME}] status: "
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
		echo `diff "${ACTUAL_PATH}${TEST_NAME}" "${EXPECTED_PATH}${TEST_NAME}"`
	fi
}

# input, test_name
function do_exit_status_test() {
	IS_OK=1
	echo "${INPUT_CMDS}" | ./minishell > "${ACTUAL_PATH}${TEST_NAME}" 2>&1

	if [ $? -eq "${EXPECTED_EXIT_STATUS}" ] ;then
	  echo -n "[${TEST_NAME}] status: "
		printf "OK, "
	else
	  echo -n "[${TEST_NAME}] status: "
		printf "${RED}NG${NC}, "
		IS_OK=0
	fi

	if [ $IS_OK -eq 1 ] ; then
		printf " ${GREEN}[✓]${NC}\n"
	else
		printf " ${RED}[-]${NC}\n"
		echo `diff "${ACTUAL_PATH}${TEST_NAME}" "${EXPECTED_PATH}${TEST_NAME}"`
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
TEST_NAME=builtin_env.txt
echo "minishell> env" > ${EXPECTED_PATH}/${TEST_NAME}
env | grep -v "_=">> ${EXPECTED_PATH}/${TEST_NAME}
echo _=./minishell >> ${EXPECTED_PATH}/${TEST_NAME}
echo LINES=24 >> ${EXPECTED_PATH}/${TEST_NAME}
echo COLUMNS=80 >> ${EXPECTED_PATH}/${TEST_NAME}
echo "minishell> exit" >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS="env"
EXPECTED_EXIT_STATUS=0
do_test

# builtin cd関数(相対パスの場合）
# 終了ステータスのみを確認
TEST_NAME=builtin_cd_relative.txt
echo "minishell> cd ./tests/google_tests" > ${EXPECTED_PATH}/${TEST_NAME}
echo "minishell> exit" >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS="cd ./tests/google_tests"
EXPECTED_EXIT_STATUS=0
do_test

# builtin cd関数(絶対パスの場合）
# 終了ステータスのみを確認
TEST_NAME=builtin_cd_absolute.txt
echo "> cd /tmp" > ${EXPECTED_PATH}/${TEST_NAME}
echo "> exit" >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS="cd /tmp"

TEST_NAME=builtin_pwd.txt
echo "minishell> pwd" > ${EXPECTED_PATH}/${TEST_NAME}
pwd >> ${EXPECTED_PATH}/${TEST_NAME}
echo "minishell> exit" >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS="pwd"
EXPECTED_EXIT_STATUS=0
do_test

TEST_NAME=builtin_exit.txt
INPUT_CMDS="exit 1"
EXPECTED_EXIT_STATUS=1
do_test

TEST_NAME=builtin_exit_to_many_args.txt
INPUT_CMDS="exit 1 2"
EXPECTED_EXIT_STATUS=1
do_test

TEST_NAME=builtin_exit_not_valid_string.txt
INPUT_CMDS="exit abc"
EXPECTED_EXIT_STATUS=255
do_test

# heredoc
TEST_NAME=heredoc_normal.txt
INPUT_CMDS="<< EOF cat
abc
EOF"
EXPECTED_EXIT_STATUS=0
do_test

# heredocとリダイレクトの重複
TEST_NAME=heredoc_duplicate_single.txt
INPUT_CMDS="<< EOF < ./tests/shell_scripts/infile.txt cat"
EXPECTED_EXIT_STATUS=0
do_test

# heredocとリダイレクトの重複
TEST_NAME=heredoc_duplicate_double.txt
INPUT_CMDS="< ./tests/shell_scripts/infile.txt << EOF cat
abc
EOF"
EXPECTED_EXIT_STATUS=0
do_test

# heredoc $展開
TEST_NAME=heredoc_extract.txt
echo 'minishell> << EOF cat' > ${EXPECTED_PATH}/${TEST_NAME}
echo '> $USER' >> ${EXPECTED_PATH}/${TEST_NAME}
echo '> EOF' >> ${EXPECTED_PATH}/${TEST_NAME}
<< EOF cat >> ${EXPECTED_PATH}/${TEST_NAME}
$USER
EOF
echo "minishell> exit" >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS='<< EOF cat
$USER
EOF'
EXPECTED_EXIT_STATUS=0
do_test

# heredoc $展開
TEST_NAME=heredoc_extract_with_dquote.txt
echo 'minishell> << "EOF" cat' > ${EXPECTED_PATH}/${TEST_NAME}
echo '> $USER' >> ${EXPECTED_PATH}/${TEST_NAME}
echo '> EOF' >> ${EXPECTED_PATH}/${TEST_NAME}
<< "EOF" cat >> ${EXPECTED_PATH}/${TEST_NAME}
$USER
EOF
echo "minishell> exit" >> ${EXPECTED_PATH}/${TEST_NAME}
INPUT_CMDS='<< "EOF" cat
$USER
EOF'
EXPECTED_EXIT_STATUS=0
do_test

# heredoc $展開
TEST_NAME=heredoc_extract_with_squote.txt
INPUT_CMDS='<< '\'EOF\'' cat
$USER
EOF'
EXPECTED_EXIT_STATUS=0
do_test

# heredoc $展開
TEST_NAME=heredoc_extract_with_squote2.txt
INPUT_CMDS='<< '\'\'EOF' cat
$USER
EOF'
EXPECTED_EXIT_STATUS=0
do_test

# do_command 子プロセスへの環境変数伝播
TEST_NAME=do_command_env.txt
INPUT_CMDS='export FT=42
bash -c env | grep FT'

# unset
TEST_NAME=unset_single_command.txt
INPUT_CMDS='unset HOME
env | grep HOME='
EXPECTED_EXIT_STATUS=1
do_test

# unset
TEST_NAME=unset_multi_commands.txt
INPUT_CMDS='unset HOME USER
env | grep HOME=
env | grep USER='
EXPECTED_EXIT_STATUS=1
do_test

# unset PATHしてgetfullpath
TEST_NAME=unset_path.txt
INPUT_CMDS='unset PATH
ls'
EXPECTED_EXIT_STATUS=127
do_test

TEST_NAME=expansion.txt
export FT=42
INPUT_CMDS="echo \$FT\"\$FT\"'\$FT'"
EXPECTED_EXIT_STATUS=0
do_test

TEST_NAME=no_cmd1.txt
INPUT_CMDS="<< HOGE"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd2.txt
INPUT_CMDS="<<"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd3.txt
INPUT_CMDS="<"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd4.txt
INPUT_CMDS="|"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd5.txt
INPUT_CMDS=">"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd6.txt
INPUT_CMDS="<< HOGE |"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd7.txt
INPUT_CMDS="ls |"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd8.txt
INPUT_CMDS=">>"
EXPECTED_EXIT_STATUS=2
do_exit_status_test

TEST_NAME=no_cmd9.txt
INPUT_CMDS="<< |"
EXPECTED_EXIT_STATUS=2
do_exit_status_test
