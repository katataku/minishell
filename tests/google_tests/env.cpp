#include <gtest/gtest.h>

extern "C" {
#include "env.h"
}

class EnvTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {}
	static void TearDownTestCase() {}

	void SetUp() {
	}
	void TearDown() {
	}
};


TEST_F(EnvTest, normal_1)
{
	set_env("testkey","testval");
	ASSERT_STREQ(get_env("testkey"), "testval");
}

TEST_F(EnvTest, normal_2)
{
	set_env("testkey","testval");
	set_env("testkey2","testval2");
	ASSERT_STREQ(get_env("testkey"), "testval");
	ASSERT_STREQ(get_env("testkey2"), "testval2");
	ASSERT_STREQ(get_env("testkey3"), NULL);
}

TEST_F(EnvTest, update_1)
{
	set_env("testkey","testval");
	set_env("testkey","testval2");
	ASSERT_STREQ(get_env("testkey"), "testval2");
}

TEST_F(EnvTest, remove_1)
{
	set_env("testkey","testval");
	set_env("testkey2","testval2");
	set_env("testkey3","testval3");

	ASSERT_STREQ(get_env("testkey"), "testval");
	ASSERT_STREQ(get_env("testkey2"), "testval2");
	ASSERT_STREQ(get_env("testkey3"), "testval3");

	remove_env("testkey2");
	ASSERT_STREQ(get_env("testkey"), "testval");
	ASSERT_STREQ(get_env("testkey2"), NULL);
	ASSERT_STREQ(get_env("testkey3"), "testval3");

	remove_env("testkey");
	ASSERT_STREQ(get_env("testkey"), NULL);
	ASSERT_STREQ(get_env("]testkey2"), NULL);
	ASSERT_STREQ(get_env("testkey3"), "testval3");

	remove_env("testkey3");
	ASSERT_STREQ(get_env("testkey"), NULL);
	ASSERT_STREQ(get_env("testkey2"), NULL);
	ASSERT_STREQ(get_env("testkey3"), NULL);
}
