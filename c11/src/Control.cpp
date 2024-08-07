#include "Control.h"
#include "ProblemList.h"
#include "UserList.h"
#include "StatusRecordList.h"
#include "DiscussList.h"
#include "CommentList.h"
#include "SolutionList.h"
#include "AnnouncementList.h"
#include "Tag.h"
#include "Judger.h"
#include <iostream>
using namespace std;
Json::Value Control::RegisterUser(Json::Value &registerjson)
{
    return UserList::GetInstance()->RegisterUser(registerjson);
}

Json::Value Control::LoginUser(Json::Value &loginjson)
{
    return UserList::GetInstance()->LoginUser(loginjson);
}

Json::Value Control::SelectUserRank(Json::Value &queryjson)
{
    return UserList::GetInstance()->SelectUserRank(queryjson);
}

Json::Value Control::SelectUserInfo(Json::Value &queryjson)
{
    return UserList::GetInstance()->SelectUserInfo(queryjson);
}

Json::Value Control::UpdateUserInfo(Json::Value &updatejson)
{
    return UserList::GetInstance()->UpdateUserInfo(updatejson);
}

Json::Value Control::SelectUserUpdateInfo(Json::Value &queryjson)
{
    return UserList::GetInstance()->SelectUserUpdateInfo(queryjson);
}

Json::Value Control::SelectUserSetInfo(Json::Value &queryjson)
{
    return UserList::GetInstance()->SelectUserSetInfo(queryjson);
}

Json::Value Control::DeleteUser(Json::Value &deletejson)
{
    return UserList::GetInstance()->DeleteUser(deletejson);
}
Json::Value Control::SelectProblemInfoByAdmin(Json::Value &queryjson)
{
    return ProblemList::GetInstance()->SelectProblemInfoByAdmin(queryjson);
}

Json::Value Control::SelectProblem(Json::Value &queryjson)
{
    return ProblemList::GetInstance()->SelectProblem(queryjson);
}

Json::Value Control::EditProblem(Json::Value &insertjson)
{
    Json::Value resjson;
    if (insertjson["EditType"].asString() == "Insert")
    {
        resjson = ProblemList::GetInstance()->InsertProblem(insertjson);
    }
    else if (insertjson["EditType"].asString() == "Update")
    {
        resjson = ProblemList::GetInstance()->UpdateProblem(insertjson);
    }
    Tag::GetInstance()->InitProblemTags();
    return resjson;
}
Json::Value Control::DeleteProblem(Json::Value &deletejson)
{
    return ProblemList::GetInstance()->DeleteProblem(deletejson);
}

Json::Value Control::SelectProblemList(Json::Value &queryjson)
{
    return ProblemList::GetInstance()->SelectProblemList(queryjson);
}

Json::Value Control::SelectProblemListByAdmin(Json::Value &queryjson)
{
    return ProblemList::GetInstance()->SelectProblemListByAdmin(queryjson);
}

Json::Value Control::GetTags(Json::Value &queryjson)
{
    if (queryjson["TagType"].asString() == "Problem")
    {
        return Tag::GetInstance()->getProblemTags();
    }
}
// --------------------公告------------------------
Json::Value Control::SelectAnnouncementList(Json::Value &queryjson)
{
    return AnnouncementList::GetInstance()->SelectAnnouncementList(queryjson);
}

Json::Value Control::SelectAnnouncementListByAdmin(Json::Value &queryjson)
{
    return AnnouncementList::GetInstance()->SelectAnnouncementListByAdmin(queryjson);
}

Json::Value Control::SelectAnnouncement(Json::Value &queryjson)
{
    return AnnouncementList::GetInstance()->SelectAnnouncement(queryjson);
}

Json::Value Control::SelectAnnouncementByEdit(Json::Value &queryjson)
{
    return AnnouncementList::GetInstance()->SelectAnnouncementByEdit(queryjson);
}

Json::Value Control::InsertAnnouncement(Json::Value &insertjson)
{
    return AnnouncementList::GetInstance()->InsertAnnouncement(insertjson);
}

Json::Value Control::UpdateAnnouncement(Json::Value &updatejson)
{
    return AnnouncementList::GetInstance()->UpdateAnnouncement(updatejson);
}
Json::Value Control::DeleteAnnouncement(Json::Value &deletejson)
{
    Json::Value resjson = AnnouncementList::GetInstance()->DeleteAnnouncement(deletejson);

    // 当评论模块完成时，将下面注释去掉
    // if (resjson["Result"].asString() == "Success")
    // {
    //     Json::Value json;
    //     json["ArticleId"] = deletejson["AnnouncementId"];
    //     CommentList::GetInstance()->DeleteArticleComment(json);
    // }
    return resjson;
}
// ----------------------讨论----------------------------
Json::Value Control::SelectDiscussList(Json::Value &queryjson)
{
    return DiscussList::GetInstance()->SelectDiscussList(queryjson);
}

Json::Value Control::SelectDiscussListByAdmin(Json::Value &queryjson)
{
    return DiscussList::GetInstance()->SelectDiscussListByAdmin(queryjson);
}

Json::Value Control::SelectDiscuss(Json::Value &queryjson)
{
    return DiscussList::GetInstance()->SelectDiscuss(queryjson);
}

Json::Value Control::SelectDiscussByEdit(Json::Value &queryjson)
{
    return DiscussList::GetInstance()->SelectDiscussByEdit(queryjson);
}

Json::Value Control::InsertDiscuss(Json::Value &insertjson)
{
    return DiscussList::GetInstance()->InsertDiscuss(insertjson);
}

Json::Value Control::UpdateDiscuss(Json::Value &updatejson)
{
    return DiscussList::GetInstance()->UpdateDiscuss(updatejson);
}
Json::Value Control::DeleteDiscuss(Json::Value &deletejson)
{
    Json::Value resjson = DiscussList::GetInstance()->DeleteDiscuss(deletejson);

    // 当评论模块完成时，将下面注释去掉
    // if (resjson["Result"].asString() == "Success")
    // {
    //     Json::Value json;
    //     json["ArticleId"] = deletejson["DiscussId"];
    //     CommentList::GetInstance()->DeleteArticleComment(json);
    // }
    return resjson;
}



Control::Control()
{
    Tag::GetInstance()->InitProblemTags();
}

Control::~Control()
{
}