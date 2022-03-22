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
		remove_env();
		set_env("HOME","/Users/takkatao");
		set_env("PATH","/bin");
		set_env("PS1","\s-\v\$");
	}
	void TearDown() {
		remove_env();
	}
};

TEST_F(EnvTest, normal_1)
{
	set_env("USER","takkatao");
	ASSERT_STREQ(get_env("USER"), "takkatao");
}

TEST_F(EnvTest, normal_2)
{
	set_env("USER","takkatao");
	set_env("SHELL","/bin/bash");
	ASSERT_STREQ(get_env("USER"), "takkatao");
	ASSERT_STREQ(get_env("SHELL"), "/bin/bash");
}

TEST_F(EnvTest, update_1)
{
	set_env("HOME","/bin");
	ASSERT_STREQ(get_env("HOME"), "/bin");
}

TEST_F(EnvTest, remove_1)
{
	unset_env("PATH");
	ASSERT_STREQ(get_env("HOME"), "/Users/takkatao");
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), "\s-\v\$");

	unset_env("HOME");
	ASSERT_STREQ(get_env("HOME"), NULL);
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), "\s-\v\$");

	unset_env("PS1");
	ASSERT_STREQ(get_env("HOME"), NULL);
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), NULL);
}

TEST_F(EnvTest, remove_last_element)
{
	unset_env("PATH");
	ASSERT_STREQ(get_env("HOME"), "/Users/takkatao");
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), "\s-\v\$");

	unset_env("PS1");
	ASSERT_STREQ(get_env("HOME"), "/Users/takkatao");
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), NULL);
}

TEST_F(EnvTest, remove_all_1)
{
	remove_env();
	ASSERT_STREQ(get_env("HOME"), NULL);
	ASSERT_STREQ(get_env("PATH"), NULL);
	ASSERT_STREQ(get_env("PS1"), NULL);
}

TEST_F(EnvTest, init_env_1)
{
	remove_env();
	init_env();
	ASSERT_STREQ(get_env("LANG"), std::getenv("LANG"));
}

TEST_F(EnvTest, get_envp)
{
	char **envp = get_envp();
	ASSERT_STREQ(envp[0], "HOME=/Users/takkatao");
	ASSERT_STREQ(envp[1], "PATH=/bin");
	ASSERT_STREQ(envp[2], "PS1=\s-\v\$");
	ASSERT_EQ(envp[3], (char *)NULL);
}

TEST(GetEnvKeyTest, simple)
{
	char *input = strdup("$HOME");
	char *output = get_env_key(input);
	ASSERT_STREQ(output, "HOME");
	free(input);
	free(output);
}

TEST(GetEnvKeyTest, contain_underscore_and_numbers)
{
	char *input = strdup("$HOME_2**");
	char *output = get_env_key(input);
	ASSERT_STREQ(output, "HOME_2");
	free(input);
	free(output);
}

TEST(GetEnvKeyTest, start_with_underscore)
{
	char *input = strdup("$_HOME");
	char *output = get_env_key(input);
	ASSERT_STREQ(output, "_HOME");
	free(input);
	free(output);
}

TEST(GetEnvKeyTest, no_dollar)
{
	char *input = strdup("HOME");
	char *output = get_env_key(input);
	ASSERT_STREQ(output, NULL);
	free(input);
	free(output);
}

TEST(GetEnvKeyTest, key_must_not_start_number)
{
	char *input = strdup("$2HOME");
	char *output = get_env_key(input);
	ASSERT_STREQ(output, NULL);
	free(input);
	free(output);
}
