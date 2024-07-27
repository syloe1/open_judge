#ifndef COMMENTLIST_H
#define COMMENTLIST_H
#include <jsoncpp/json/json.h>
#include <string>
class CommentList{
public:
    static CommentList *GetInstance();
private:
    CommentList();
    ~CommentList();
};
#endif