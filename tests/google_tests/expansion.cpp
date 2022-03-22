#include <gtest/gtest.h>

extern "C" {
#include "expansion.h"
}

class ExpansionTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}

	char *input;
	char *output;

	void SetUp() {
		set_env("HOME","/usr/nop");
	}
	void TearDown() {
//		free(input);
//		free(output);
		remove_env();
	}
};

TEST_F(ExpansionTest, not_expand)
{
	input = strdup("NOT");
	output = expand(input);
	ASSERT_STREQ("NOT", output);
}

TEST_F(ExpansionTest, simple_expand_with_no_quotes)
{
	input = strdup("HOME$HOME+HOME");
	output = expand(input);
	ASSERT_STREQ("HOME/usr/nop+HOME", output);
}

TEST_F(ExpansionTest, simple_double_quote)
{
	input = strdup("\"$HOME\"");
	output = expand(input);
	ASSERT_STREQ("/usr/nop", output);
}

TEST_F(ExpansionTest, simple_single_quote)
{
	input = strdup("'$HOME'");
	output = expand(input);
	ASSERT_STREQ("$HOME", output);
}

TEST_F(ExpansionTest, single_quote_in_double_quote)
{
	input = strdup("\"'$HOME\"");
	output = expand(input);
	ASSERT_STREQ("'/usr/nop", output);
}

TEST_F(ExpansionTest, double_quote_in_single_quote)
{
	input = strdup("'\"$HOME\"'");
	output = expand(input);
	ASSERT_STREQ("\"$HOME\"", output);
}

TEST_F(ExpansionTest, single_quotes_after_double_quotes)
{
	input = strdup("a$HOME\"b$HOME\"'c$HOME'");
	output = expand(input);
	ASSERT_STREQ("a/usr/nopb/usr/nopc$HOME", output);
}

TEST_F(ExpansionTest, double_quotes_after_single_quotes)
{
	input = strdup("a$HOME'b$HOME'\"c$HOME\"");
	output = expand(input);
	ASSERT_STREQ("a/usr/nopb$HOMEc/usr/nop", output);
}
