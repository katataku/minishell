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
	ASSERT_STREQ(extract_quote("test"), "test");
}


TEST_F(HeredocTest, extract_quote_dquote)
{
	ASSERT_STREQ(extract_quote("\"test\""), "test");
}

TEST_F(HeredocTest, extract_quote_squote)
{
	ASSERT_STREQ(extract_quote("\'test\'"), "test");
}

TEST_F(HeredocTest, extract_quote_squote2)
{
	ASSERT_STREQ(extract_quote("\'\'test"), "test");
}

