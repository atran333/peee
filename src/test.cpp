#include <iostream>
#include <gtest/gtest.h>

TEST(Tests, Test0) {
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}