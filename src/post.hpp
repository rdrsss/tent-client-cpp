#ifndef POST_HPP_
#define POST_HPP_
#pragma once

#include <string>
#include <vector>
#include "jsonserializable.hpp"

namespace tent { 

struct Parent;
struct Mention; 
struct Ref;
struct License;
struct Attachment;
struct Group;

typedef std::vector<Parent>         ParentList;
typedef std::vector<Mention>        MentionList;
typedef std::vector<Ref>            RefList; 
typedef std::vector<License>        LicenseList;
typedef std::vector<Attachment>     AttachmentList;
typedef std::vector<Group>          GroupList;
typedef std::vector<std::string>    EntityList;

struct Group : public JsonSerializable {
    std::string post;
    EntityList  entities;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct Permissions : public JsonSerializable {
    bool is_public;
    GroupList groups;
 
    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();   
};

struct App : public JsonSerializable {
    std::string id;
    std::string name;
    std::string url;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct Attachment : public JsonSerializable {
    std::string category;
    std::string content_type;
    std::string name;
    std::string digest;
    std::string size;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct Content : public JsonSerializable {
    JsonVal content;

    void PushBackValue(const std::string& key, JsonVal& val);
    void PushBackValue(const std::string& key, const std::string& val);

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct License : public JsonSerializable {
    std::string url;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct Ref : public JsonSerializable {
    std::string entity;
    std::string original_entity;
    std::string post;
    std::string version;
    std::string type;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct Mention : public JsonSerializable { // The entities and posts that this post mentions
    std::string entity;
    std::string original_entity;
    std::string post;
    std::string version;
    std::string type;
    bool is_public;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct Parent : public JsonSerializable { // Parent versions
    std::string version;
    std::string entity;
    std::string original_entity;
    std::string post;
    std::string message;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

struct Version : public JsonSerializable { // Post version object
    std::string     id;
    std::string     published_at;
    std::string     received_at;
    ParentList      parents; 

    void ClearParents()             { parents.clear(); }
    void PushBackParent(Parent& p)  { parents.push_back(p); }

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
};

class Post : public JsonSerializable {
public:
    Post();
    ~Post();

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
    JsonVal SerializeToValue();
private:
    std::string id_;                
    std::string entity_;            
    std::string original_entity_;   
    std::string published_at_;      
    std::string received_at_;        
    std::string type_;

    Version         version_;
    MentionList     mentions_;
    RefList         refs_;
    LicenseList     licenses_;
    AttachmentList  attachments_;

    App             app_;
    Permissions     permissions_;
    Content         content_;
};


} //namespace 
#endif

