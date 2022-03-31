#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {
#include "heredoc.h"
}

class HeredocTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}

	void SetUp() {
	}
	void TearDown() {
	}
};

// actualをfreeするためのラッパー関数。actualとexpectは逆だけど仕方なし。
static void	assert_streq_wrap(char *actual, char *expect)
{
	ASSERT_STREQ(actual, expect);
	free(actual);
}

TEST_F(HeredocTest, is_quoted_false)
{
	ASSERT_EQ(is_quoted("test"), false);
}

TEST_F(HeredocTest, is_quoted_dquote)
{
	ASSERT_EQ(is_quoted("\"test\""), true);
}

TEST_F(HeredocTest, is_quoted_squote)
{
	ASSERT_EQ(is_quoted("\'test\'"), true);
}

TEST_F(HeredocTest, extract_quote)
{
	assert_streq_wrap(extract_quote("test"), "test");
}


TEST_F(HeredocTest, extract_quote_dquote)
{
	assert_streq_wrap(extract_quote("\"test\""), "test");
}

TEST_F(HeredocTest, extract_quote_squote)
{
	assert_streq_wrap(extract_quote("\'test\'"), "test");
}

TEST_F(HeredocTest, extract_quote_squote2)
{
	assert_streq_wrap(extract_quote("\'\'test"), "test");
}

