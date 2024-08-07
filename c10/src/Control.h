#ifndef CONTROL_H
#define CONTROL_H
#include <jsoncpp/json/json.h>
#include <string>
class Control
{
public:
    // ----------------用户表 User-----------------
    // 注册用户
    Json::Value RegisterUser(Json::Value &registerjson);

    // 登录用户
    Json::Value LoginUser(Json::Value &loginjson);

    // 获取用户Rank排名
    Json::Value SelectUserRank(Json::Value &queryjson);

    // 获取用户大部分信息
    Json::Value SelectUserInfo(Json::Value &queryjson);

    // 更新用户信息
    Json::Value UpdateUserInfo(Json::Value &updatejson);

    // 获取用户信息，以供修改
    Json::Value SelectUserUpdateInfo(Json::Value &queryjson);

    // 分页获取用户信息
    Json::Value SelectUserSetInfo(Json::Value &queryjson);

    // 删除用户
    Json::Value DeleteUser(Json::Value &deletejson);
        // ---------------题目 Problem -------------------

    // 管理员查看题目数据
    Json::Value SelectProblemInfoByAdmin(Json::Value &queryjson);

    // 用户查询题目信息
    Json::Value SelectProblem(Json::Value &queryjson);

    // 编辑题目
    Json::Value EditProblem(Json::Value &insertjson);

    // 删除题目
    Json::Value DeleteProblem(Json::Value &deletejson);

    // 返回题库
    Json::Value SelectProblemList(Json::Value &queryjson);

    // 管理员查询列表
    Json::Value SelectProblemListByAdmin(Json::Value &queryjson);

    // 获取标签
    Json::Value GetTags(Json::Value &queryjson);

    // ----------------------公告---------------------------
    // 查询公告列表
    Json::Value SelectAnnouncementList(Json::Value &queryjson);

    // 管理员查询公告列表
    Json::Value SelectAnnouncementListByAdmin(Json::Value &queryjson);

    // 查询公告
    Json::Value SelectAnnouncement(Json::Value &queryjson);

    // 查询公告 进行编辑
    Json::Value SelectAnnouncementByEdit(Json::Value &queryjson);

    // 插入公告
    Json::Value InsertAnnouncement(Json::Value &insertjson);

    // 更新公告
    Json::Value UpdateAnnouncement(Json::Value &updatejson);

    // 删除公告
    Json::Value DeleteAnnouncement(Json::Value &deletejson);

    Control();

    ~Control();

private:
};

#endif