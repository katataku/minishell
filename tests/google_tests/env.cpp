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

// actualをfreeするためのラッパー関数。actualとexpectは逆だけど仕方なし。
void	assert_streq_wrap(char *actual, char *expect)
{
	ASSERT_STREQ(actual, expect);
	free(actual);
}

TEST_F(EnvTest, normal_1)
{
	char	*tmp;
	set_env("USER","takkatao");
	assert_streq_wrap(get_env("USER"), "takkatao");
}

TEST_F(EnvTest, normal_2)
{
	set_env("USER","takkatao");
	set_env("SHELL","/bin/bash");
	assert_streq_wrap(get_env("USER"), "takkatao");
	assert_streq_wrap(get_env("SHELL"), "/bin/bash");
}

TEST_F(EnvTest, update_1)
{
	set_env("HOME","/bin");
	assert_streq_wrap(get_env("HOME"), "/bin");
}

TEST_F(EnvTest, remove_1)
{
	unset_env("PATH");
	assert_streq_wrap(get_env("HOME"), "/Users/takkatao");
	assert_streq_wrap(get_env("PATH"), NULL);
	assert_streq_wrap(get_env("PS1"), "\s-\v\$");

	unset_env("HOME");
	assert_streq_wrap(get_env("HOME"), NULL);
	assert_streq_wrap(get_env("PATH"), NULL);
	assert_streq_wrap(get_env("PS1"), "\s-\v\$");

	unset_env("PS1");
	assert_streq_wrap(get_env("HOME"), NULL);
	assert_streq_wrap(get_env("PATH"), NULL);
	assert_streq_wrap(get_env("PS1"), NULL);
}

TEST_F(EnvTest, remove_last_element)
{
	unset_env("PATH");
	assert_streq_wrap(get_env("HOME"), "/Users/takkatao");
	assert_streq_wrap(get_env("PATH"), NULL);
	assert_streq_wrap(get_env("PS1"), "\s-\v\$");

	unset_env("PS1");
	assert_streq_wrap(get_env("HOME"), "/Users/takkatao");
	assert_streq_wrap(get_env("PATH"), NULL);
	assert_streq_wrap(get_env("PS1"), NULL);
}

TEST_F(EnvTest, remove_all_1)
{
	remove_env();
	assert_streq_wrap(get_env("HOME"), NULL);
	assert_streq_wrap(get_env("PATH"), NULL);
	assert_streq_wrap(get_env("PS1"), NULL);
}

TEST_F(EnvTest, init_env_1)
{
	remove_env();
	init_env();
	assert_streq_wrap(get_env("LANG"), std::getenv("LANG"));
}

TEST_F(EnvTest, get_envp)
{
	char **envp = get_envp();
	assert_streq_wrap(envp[0], "HOME=/Users/takkatao");
	assert_streq_wrap(envp[1], "PATH=/bin");
	assert_streq_wrap(envp[2], "PS1=\s-\v\$");
	ASSERT_STREQ(envp[3], (char *)NULL);
	free(envp);
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

TEST(GetEnvKeyTest, special_variable_name)
{
	char *input = strdup("$?");
	char *output = get_env_key(input);
	ASSERT_STREQ(output, "?");
	free(input);
	free(output);
}
