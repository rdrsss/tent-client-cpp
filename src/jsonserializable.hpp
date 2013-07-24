#ifndef JSONSERIALIZABLE_HPP_
#define JSONSERIALIZABLE_HPP_
#pragma once

#include <string>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

namespace tent {

typedef rapidjson::Value JsonVal;
typedef rapidjson::Document JsonDoc;
typedef rapidjson::Document::AllocatorType JsonAllocator;

class JsonSerializable {
public:
    JsonSerializable() {}
    virtual ~JsonSerializable() {}

    virtual void Serialize(JsonVal& root, JsonAllocator& alloc) = 0;
    virtual void Deserialize(JsonVal& root, JsonAllocator& alloc) = 0;
    virtual std::string SerializeAsString() = 0;
};

static bool SerializeObject(JsonSerializable* obj, std::string& out) {
    bool ret = false;
    if(obj) {
        JsonDoc doc;
        doc.SetObject();

        JsonVal root(rapidjson::kObjectType);
        obj->Serialize(root, doc.GetAllocator());
        rapidjson::StringBuffer strbuf;
        rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
        root.Accept(writer);
        out = strbuf.GetString();
        ret = true;
    }
    return ret;
}


}// namespace
#endif

