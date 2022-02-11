#include <gtest/gtest.h>

extern "C" {
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
		free(exec_info->srcfile);
		free(exec_info->dstfile);
		free(exec_info);
	}
	void build_cmd(std::string cmds[], int size);
};

void ExecTest::build_cmd(std::string cmds[], int size) {
	exec_info->cmds = (char ***)calloc(size, sizeof(char **));
	exec_info->cmds[0] = ft_split(cmds[0].c_str(), ' ');
}

TEST_F(ExecTest, single_command)
{
	std::string cmds[] = {
			"/bin/cat"
	};
	build_cmd(cmds, 1);

	actual_status_code = execute(exec_info);
	expect_status_code = system("< infile /bin/cat > expected");
	ASSERT_EQ(expect_status_code, actual_status_code);
	ASSERT_EQ(system("diff actual expected"), 0);
}
