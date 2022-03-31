#include <gtest/gtest.h>

extern "C" {
#include "parser.h"
#include "executer.h"
}

class ExecTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}

	t_exec_info *exec_info;
	int actual_status_code;
	int expect_status_code;

	void SetUp() {
		system("echo bc > infile");
		system("echo ab >> infile");

		exec_info = (t_exec_info *)calloc(1, sizeof(t_exec_info));
		exec_info->srcfile = strdup("infile");
		exec_info->dstfile = strdup("actual");
		exec_info->o_flag = O_WRONLY | O_CREAT | O_TRUNC;
	}
	void TearDown() {
		unlink("actual");
		unlink("expected");
		free_exec_info(exec_info);
	}
	void to_exec_info_cmd(std::string cmds[], int size);
	std::string build_cmd(std::string cmds[], int size);
	void do_execute(std::string cmds[], int size);
	void do_execute(std::string cmd);
};

void ExecTest::to_exec_info_cmd(std::string cmds[], int size) {
	exec_info->cmd_num = size;
	exec_info->cmds = (char ***)calloc(size, sizeof(char **));
	for (int i = 0; i < size; i++)
	{
		exec_info->cmds[i] = ft_split(cmds[i].c_str(), ' ');
	}
}

std::string ExecTest::build_cmd(std::string *cmds, int size) {
	std::string cmd;

	cmd = "< ";
	cmd += exec_info->srcfile;
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
			cmd += " | ";
		else
			cmd += " ";
		cmd += cmds[i];
	}
	cmd += " > expected";
	return (cmd);
}

void ExecTest::do_execute(std::string *cmds, int size) {
	std::string cmd;

	to_exec_info_cmd(cmds, size);
	cmd = build_cmd(cmds, size);
	do_execute(cmd);
}

void ExecTest::do_execute(std::string cmd) {
	actual_status_code = execute(exec_info);
	expect_status_code = system(cmd.c_str());
	ASSERT_EQ(expect_status_code, actual_status_code);
	ASSERT_EQ(system("diff actual expected"), 0);
}

TEST_F(ExecTest, single_command)
{
	std::string cmds[] = {
			"/bin/cat"
	};

	do_execute(cmds, 1);
}

TEST_F(ExecTest, single_command_with_args)
{
	std::string cmds[] = {
			"/usr/bin/grep ab"
	};

	do_execute(cmds, 1);
}

TEST_F(ExecTest, simple_pipe)
{
	std::string cmds[] = {
			"/bin/cat",
			"/usr/bin/grep ab"
	};

	do_execute(cmds, 2);
}

TEST_F(ExecTest, multiple_pipe_odd)
{
	std::string cmds[] = {
			"/bin/cat",
			"/usr/bin/rev",
			"/usr/bin/tr a x",
			"/usr/bin/grep bx",
			"/bin/cat",
	};

	do_execute(cmds, 5);
}

TEST_F(ExecTest, multiple_pipe_even)
{
	std::string cmds[] = {
			"/bin/cat",
			"/usr/bin/rev",
			"/usr/bin/tr a x",
			"/usr/bin/grep bx",
			"/usr/bin/rev",
			"/bin/cat",
	};

	do_execute(cmds, 6);
}

TEST_F(ExecTest, single_builtin)
{
	std::string cmds[] = {
			"echo hello world !",
	};
	do_execute(cmds, 1);
}

// TEST_F(ExecTest, builtin_with_pipe)
// {
// 	std::string cmds[] = {
// 			"echo hello world !",
// 			"/bin/cat"
// 	};
// 	do_execute(cmds, 2);
// }
