#include <gtest/gtest.h>

TEST(INITIAL, TEST) {

}

int main(int argc, char** argv) {
    // Init gtestframework
    testing::InitGoogleTest(&argc, argv);
    // All tests are setup, run them
    return RUN_ALL_TESTS();
}

