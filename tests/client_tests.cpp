#include <gtest/gtest.h>

#include "rapidjson/document.h"

#include "post.hpp"

TEST(INITIAL, TEST) {
    rapidjson::Document doc;

    rapidjson::Value m("message");
    //doc.AddMember("something", m);
}

int main(int argc, char** argv) {
    // Init gtestframework
    testing::InitGoogleTest(&argc, argv);
    // All tests are setup, run them
    return RUN_ALL_TESTS();
}

