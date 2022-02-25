#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {
#include "env.h"
}

class EnvTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}

	void SetUp() {
		set_env("HOME","/Users/takkatao");
		set_env("PATH","/bin");
		set_env("PS1","\s-\v\$");
	}
	void TearDown() {
		remove_all_env();
	}
};


TEST_F(EnvTest, normal_1)
{
	set_env("HOME","/Users/takkatao");
	ASSERT_STREQ(get_env("HOME"), "/Users/takkatao");
}

TEST_F(EnvTest, normal_2)
{
	set_env("HOME","/Users/takkatao");
	set_env("PATH","/bin");
	ASSERT_STREQ(get_env("HOME"), "/Users/takkatao");
	ASSERT_STREQ(get_env("PATH"), "/bin");
}

TEST_F(EnvTest, update_1)
{
	set_env("HOME","/bin");
	ASSERT_STREQ(get_env("HOME"), "/bin");
}

TEST_F(EnvTest, remove_1)
{
	remove_env("PATH");
	ASSERT_STREQ(get_env("HOME"), "/Users/takkatao");
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), "\s-\v\$");

	remove_env("HOME");
	ASSERT_STREQ(get_env("HOME"), NULL);
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), "\s-\v\$");

	remove_env("PS1");
	ASSERT_STREQ(get_env("HOME"), NULL);
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), NULL);
}

TEST_F(EnvTest, remove_all_1)
{
	remove_all_env();
	ASSERT_STREQ(get_env("HOME"), NULL);
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), NULL);
}

TEST_F(EnvTest, init_env_1)
{
	remove_all_env();
	init_env();
	ASSERT_STREQ(get_env("LANG"), std::getenv("LANG"));

}
