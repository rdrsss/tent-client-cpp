#include <iostream>
#include <gtest/gtest.h>

#include "rapidjson/rapidjson.h"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"

#include "post.hpp"

TEST(RAPIDJSON, READIN) {
    tent::Post p;
    p.set_id("102859238jf");
    p.set_entity("http://localhost");
    p.set_type("some_post_type");
    p.version()->id = "ID IS YES";

    tent::Parent rent;
    rent.version = "TWO";
    rent.entity = "SOME OTHER ENTITY";
    p.version()->PushBackParent(rent);

    tent::Parent rent_two;
    rent_two.version = "THREE";
    rent_two.entity = "SOME OTHER OTHER ENTITY";
    p.version()->PushBackParent(rent_two);

    std::string buffer;
    SerializeObject(&p, buffer);
    std::cout<< buffer << std::endl;

}

TEST(RAPIDJSON, WRITER_TEST) {
    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Value m(rapidjson::kObjectType);
    //doc.AddMember("something", m);
    m.AddMember("test","something", doc.GetAllocator());
    
    rapidjson::Value j(rapidjson::kObjectType);
    j.AddMember("some thing", m, doc.GetAllocator());

    doc.AddMember("object", j, doc.GetAllocator());

    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    doc.Accept(writer);
    std::cout << strbuf.GetString() << std::endl;
}

TEST(INITIAL, TEST) {

}

int main(int argc, char** argv) {
    // Init gtestframework
    testing::InitGoogleTest(&argc, argv);
    // All tests are setup, run them
    return RUN_ALL_TESTS();
}

