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

TEST_F(BuiltinTest, echo_normal)
{
	int	argc = 2;
	char *argv[] = {"echo", "hello"};

	testing::internal::CaptureStdout();
	status_code = echo(argc, argv);
	output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(0, status_code);
	ASSERT_STREQ("hello\n", output.c_str());
}