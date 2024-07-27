#include "httplib.h"           // HTTP库
#include <jsoncpp/json/json.h> // JSON库
#include <iostream>
#include <string>

using namespace std;
void doTestGet(const httplib::Request &req, httplib::Response &res)
{
    cout << "执行doTestGet" << endl;
    // 获取请求头参数
    string userid = req.get_param_value("userid");

    // 处理逻辑......

    // 返回数据
    Json::Value resjson;
    if (userid == "1")
    {
        resjson["userid"] = userid;
        resjson["name"] = "坤坤";
        resjson["composition"] = "只因你太美";
        resjson["hobby"].append("唱");
        resjson["hobby"].append("跳");
        resjson["hobby"].append("rap");
        resjson["hobby"].append("篮球");
    }
    else
    {
        res.status = 404;
    }

    res.set_content(resjson.toStyledString(), "json");
}
void doTestPost(const httplib::Request &req, httplib::Response &res)
{
    cout << "执行doTestPost" << endl;
    // 获取请求体
    Json::Value jsonvalue;
    Json::Reader reader;
    // 解析传入的json
    reader.parse(req.body, jsonvalue);

    cout << "获取请求体信息：" << endl;
    cout << jsonvalue.toStyledString() << endl;

    // 处理逻辑......

    Json::Value resjson;
    resjson["result"] = "处理成功";
    resjson["info"] = jsonvalue;

    res.set_content(resjson.toStyledString(), "json");
}

int main()
{
    using namespace httplib;
    Server server;
    // Get请求
    server.Get("/test/get", doTestGet);
    // Post请求
    server.Post("/test/post", doTestPost);
    // 设置监听端口
    server.listen("0.0.0.0", 8081);
}
