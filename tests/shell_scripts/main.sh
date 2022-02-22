#!/bin/bash

echo "/bin/echo hello" | ./minishell > actual_output
echo "/bin/echo hello" | /bin/bash > expect_output

if  diff actual_output ./tests/shell_scripts/expect/0001.txt  ;then
echo "OK"
else
 echo "NG"
fi

#テスト名
#inputがあって
#実行される OK, NG
