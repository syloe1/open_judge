#ifndef TAG_H
#define TAG_H
#include <jsoncpp/json/json.h>

class Tag
{
public:
    // 局部静态特性的方式实现单实例
    static Tag *GetInstance();
        // 初始化
    void InitProblemTags();
    // 获取题目的所有标签
    Json::Value getProblemTags();
    Json::Value problemtags;
private:
    Tag();
    ~Tag();
};
#endif