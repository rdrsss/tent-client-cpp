#include "post.hpp"

#include <iostream>

namespace tent {

void Group::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!post.empty())               root.AddMember("post", post.c_str(), alloc);
    if(entities.size())
        SerializeEntityList(root, alloc);
}

void Group::SerializeEntityList(JsonVal& root, JsonAllocator& alloc) {
    JsonVal pval(rapidjson::kArrayType);
    auto itr = entities.begin();
    for(;itr!=entities.end(); itr++) {
        JsonVal p(rapidjson::kObjectType);
        itr->Serialize(p, alloc);
        pval.PushBack(p, alloc);
    }
    root.AddMember("entities", pval, alloc);
}

void Group::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Group::SerializeAsString(){
    std::string str;
    return str;
}

void Permissions::Serialize(JsonVal& root, JsonAllocator& alloc) {
    root.AddMember("public", is_public, alloc);
    if(groups.size())
        SerializeGroupList(root, alloc);
}

void Permissions::SerializeGroupList(JsonVal& root, JsonAllocator& alloc) {
    JsonVal pval(rapidjson::kArrayType);
    auto itr = groups.begin();
    for(;itr!=groups.end(); itr++) {
        JsonVal p(rapidjson::kObjectType);
        itr->Serialize(p, alloc);
        pval.PushBack(p, alloc);
    }
    root.AddMember("groups", pval, alloc);
}

void Permissions::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Permissions::SerializeAsString(){
    std::string str;
    return str;
}

void App::Serialize(JsonVal& root, JsonAllocator& alloc) {}
void App::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string App::SerializeAsString(){
    std::string str;
    return str;
}

void Attachment::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!category.empty())       root.AddMember("category", category.c_str(), alloc);
    if(!content_type.empty())   root.AddMember("content_type", content_type.c_str(), alloc);
    if(!name.empty())           root.AddMember("name", name.c_str(), alloc);
}

void Attachment::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Attachment::SerializeAsString(){
    std::string str;
    return str;
}

void Content::Serialize(JsonVal& root, JsonAllocator& alloc) {}
void Content::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Content::SerializeAsString(){
    std::string str;
    return str;
}

void License::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!url.empty()) root.AddMember("url", url.c_str(), alloc);
}

void License::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string License::SerializeAsString(){
    std::string str;
    return str;
}

void Ref::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!entity.empty())             root.AddMember("entity", entity.c_str(), alloc);
    if(!original_entity.empty())    root.AddMember("original_entity", 
                                        original_entity.c_str(), 
                                        alloc);
    if(!post.empty())               root.AddMember("post", post.c_str(), alloc);
    if(!version.empty())            root.AddMember("version", version.c_str(), alloc);
    if(!type.empty())               root.AddMember("type", type.c_str(), alloc);
}

void Ref::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Ref::SerializeAsString(){
    std::string str;
    return str;
}

void Mention::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!entity.empty())             root.AddMember("entity", entity.c_str(), alloc);
    if(!original_entity.empty())    root.AddMember("original_entity", 
                                        original_entity.c_str(), 
                                        alloc);
    if(!post.empty())               root.AddMember("post", post.c_str(), alloc);
    if(!version.empty())            root.AddMember("version", version.c_str(), alloc);
    if(!type.empty())               root.AddMember("type", type.c_str(), alloc);
    root.AddMember("public", is_public, alloc);
}

void Mention::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Mention::SerializeAsString(){
    std::string str;
    return str;
}

void Parent::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!version.empty())            root.AddMember("version", version.c_str(), alloc);
    if(!entity.empty())             root.AddMember("entity", entity.c_str(), alloc);
    if(!original_entity.empty())    root.AddMember("original_entity", 
                                        original_entity.c_str(), 
                                        alloc);
    if(!post.empty())               root.AddMember("post", post.c_str(), alloc);
    if(!message.empty())            root.AddMember("message", message.c_str(), alloc);
}

void Parent::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Parent::SerializeAsString(){
    std::string str;
    return str;
}

void Version::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!id.empty())             root.AddMember("id", id.c_str(), alloc);
    if(!published_at.empty())   root.AddMember("published_at", published_at.c_str(), alloc);
    if(!received_at.empty())    root.AddMember("received_at", received_at.c_str(), alloc);

    if(parents.size())
        SerializeParentList(root, alloc);
}

void Version::SerializeParentList(JsonVal& root, JsonAllocator& alloc) {
    JsonVal pval(rapidjson::kArrayType);
    auto itr = parents.begin();
    for(;itr!=parents.end(); itr++) {
        JsonVal p(rapidjson::kObjectType);
        itr->Serialize(p, alloc);
        pval.PushBack(p, alloc);
    }
    root.AddMember("parents", pval, alloc);
}

void Version::Deserialize(JsonVal& root, JsonAllocator& alloc) {}
std::string Version::SerializeAsString(){
    std::string str;
    return str;
}

Post::Post() {
}

Post::~Post() {}

void Post::Serialize(JsonVal& root, JsonAllocator& alloc) {
    if(!id_.empty())                root.AddMember("id", id_.c_str(), alloc);
    if(!entity_.empty())            root.AddMember("entity", entity_.c_str(), alloc);
    if(!original_entity_.empty())   root.AddMember("original_entity", 
                                        original_entity_.c_str(), 
                                        alloc);
    if(!published_at_.empty())      root.AddMember("published_at", published_at_.c_str(), alloc);
    if(!received_at_.empty())       root.AddMember("received_at", received_at_.c_str(), alloc);
    if(!type_.empty())              root.AddMember("type", type_.c_str(), alloc);

    JsonVal version(rapidjson::kObjectType);
    version_.Serialize(version, alloc);
    root.AddMember("version", version, alloc);

    JsonVal app(rapidjson::kObjectType);
    app_.Serialize(app, alloc);
    root.AddMember("app", app, alloc);

    JsonVal permissions(rapidjson::kObjectType);
    permissions_.Serialize(permissions, alloc);
    root.AddMember("permissions", permissions, alloc);

    JsonVal content(rapidjson::kObjectType);
    content_.Serialize(content, alloc);
    root.AddMember("content", content, alloc);

}

void Post::Deserialize(JsonVal& root, JsonAllocator& alloc) {
}

std::string Post::SerializeAsString() {
    std::string str;
    return str;
}


}//namespace

