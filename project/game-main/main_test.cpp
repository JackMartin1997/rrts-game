#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Import tests for running

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

