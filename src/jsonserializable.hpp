#ifndef JSONSERIALIZABLE_HPP_
#define JSONSERIALIZABLE_HPP_
#pragma once

#include "rapidjson/document.h"

namespace tent {

typedef rapidjson::Value JsonVal;
typedef rapidjson::Document JsonDoc;

class JsonSerializable {
public:
    JsonSerializable() {}
    virtual ~JsonSerializable() {}

    virtual bool Serialize(JsonDoc& doc) = 0;
    virtual bool Deserialize(JsonDoc& doc) = 0;
};

}// namespace

#endif

