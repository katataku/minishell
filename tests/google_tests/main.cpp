#include <gtest/gtest.h>

extern "C" {
int	g_last_exit_status;
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	int rtv = RUN_ALL_TESTS();
	return rtv;
}
