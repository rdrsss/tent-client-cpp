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
};

struct Permissions : public JsonSerializable {
    bool is_public;
    GroupList groups;
 
    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
};

struct App : public JsonSerializable {
    std::string id;
    std::string name;
    std::string url;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
};

struct Attachment : public JsonSerializable {
    std::string category;
    std::string content_type;
    std::string name;
    std::string digest;
    std::string size;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
};

struct Content : public JsonSerializable {
    JsonVal content;

    void PushBackValue(const std::string& key, JsonVal& val);
    void PushBackValue(const std::string& key, const std::string& val);

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
};

struct License : public JsonSerializable {
    std::string url;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
};

struct Ref : public JsonSerializable {
    std::string entity;
    std::string original_entity;
    std::string post;
    std::string version;
    std::string type;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
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
};

struct Parent : public JsonSerializable { // Parent versions
    std::string version;
    std::string entity;
    std::string original_entity;
    std::string post;
    std::string message;

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);
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
};

class Post : public JsonSerializable {
public:
    Post();
    ~Post();

    bool Serialize(JsonDoc& doc);
    bool Deserialize(JsonDoc& doc);

    const std::string& id() const               { return id_; }
    const std::string& entity() const           { return entity_; } 
    const std::string& original_entity() const  { return original_entity_; }
    const std::string& published_at() const     { return published_at_; }
    const std::string& received_at() const      { return received_at_; }
    const std::string& type() const             { return type_; }

    Version* version()          { return &version_; }
    App* app()                  { return &app_; }
    Permissions* permissions()  { return &permissions_; }
    Content* content()          { return &content_; }

    MentionList* mentions()         { return &mentions_; }
    RefList*     refs()             { return &refs_; }
    LicenseList* licenses()         { return &licenses_; }
    AttachmentList* attachments()   { return &attachments_; }

    void set_id(const std::string& id)                  { id_ = id; }
    void set_entity(const std::string& ent)             { entity_ = ent; }
    void set_original_entity(const std::string& ent)    { original_entity_ = ent; }
    void set_type(const std::string& type)              { type_ = type; }

    void set_public(const bool p) { permissions_.is_public = p; }

private:
    std::string id_;                
    std::string entity_;            
    std::string original_entity_;   
    std::string published_at_;      
    std::string received_at_;        
    std::string type_;

    std::string base_type_;
    std::string fragment_;

    MentionList     mentions_;
    RefList         refs_;
    LicenseList     licenses_;
    AttachmentList  attachments_;

    Version         version_;
    App             app_;
    Permissions     permissions_;
    Content         content_;
};


} //namespace 
#endif

