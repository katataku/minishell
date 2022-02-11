#include <gtest/gtest.h>

extern "C" {
#include "executer.h"
}

class ExecTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}

	t_exec_info	*exec_info;

	void SetUp() {
		system("echo bc > infile");
		system("echo ab >> infile");

		exec_info = (t_exec_info *)calloc(1, sizeof(t_exec_info));
		exec_info->srcfile = strdup("infile");
		exec_info->dstfile = strdup("actual");
	}
	void TearDown() {
		unlink("actual");
		unlink("expected");
		free(exec_info->srcfile);
		free(exec_info->dstfile);
		free(exec_info);
	}
	std::string build_cmd(std::string *cmds);
};

std::string ExecTest::build_cmd(std::string *cmds) {
	exec_info->cmds = (char ***)calloc(cmds->size(), sizeof(char **));
	exec_info->cmds[0] = ft_split("/bin/cat", ' ');
}

TEST_F(ExecTest, single_command)
{
	std::array<std::string, 1> cmds = {
			"/bin/cat"
	};
	ASSERT_EQ(0, execute(exec_info));
}
