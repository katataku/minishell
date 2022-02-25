#include <gtest/gtest.h>

extern "C" {
#include "builtin.h"
}

class BuiltinTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}
	int status_code;
	std::string output;

	void SetUp() {}
	void TearDown() {}
};

TEST_F(BuiltinTest, echo_one_argument)
{
	int	argc = 2;
	char *argv[] = {"echo", "hello", NULL};

	testing::internal::CaptureStdout();
	status_code = echo(argc, argv);
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, status_code);
	ASSERT_STREQ("hello\n", output.c_str());
}

TEST_F(BuiltinTest, echo_multiple_arguments)
{
	int	argc = 4;
	char *argv[] = {"echo", "hello", "world", "!", NULL};

	testing::internal::CaptureStdout();
	status_code = echo(argc, argv);
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, status_code);
	ASSERT_STREQ("hello world !\n", output.c_str());
}

TEST_F(BuiltinTest, echo_no_argument)
{
	int	argc = 1;
	char *argv[] = {"echo", NULL};

	testing::internal::CaptureStdout();
	status_code = echo(argc, argv);
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, status_code);
	ASSERT_STREQ("\n", output.c_str());
}

TEST_F(BuiltinTest, echo_only_n_option)
{
	int	argc = 2;
	char *argv[] = {"echo", "-n", NULL};

	testing::internal::CaptureStdout();
	status_code = echo(argc, argv);
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, status_code);
	ASSERT_STREQ("", output.c_str());
}

TEST_F(BuiltinTest, echo_n_option)
{
	int	argc = 3;
	char *argv[] = {"echo", "-n", "hello", NULL};

	testing::internal::CaptureStdout();
	status_code = echo(argc, argv);
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, status_code);
	ASSERT_STREQ("hello", output.c_str());
}

TEST_F(BuiltinTest, echo_n_option_multiple_arguments)
{
	int	argc = 5;
	char *argv[] = {"echo", "-n", "hello", "world", "!", NULL};

	testing::internal::CaptureStdout();
	status_code = echo(argc, argv);
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, status_code);
	ASSERT_STREQ("hello world !", output.c_str());
}
