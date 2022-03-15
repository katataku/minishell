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

//TEST_F(ExpansionTest, expand_with_no_quotes)
//{
//	ASSERT_STREQ(get_env("USER"), "takkatao");
//}
