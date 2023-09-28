#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class GetData : public drogon::HttpController<GetData>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(GetData::get, "/{2}/{1}", Get); // path is /GetData/{arg2}/{arg1}
    // METHOD_ADD(GetData::your_method_name, "/{1}/{2}/list", Get); // path is /GetData/{arg1}/{arg2}/list
    // ADD_METHOD_TO(GetData::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

        ADD_METHOD_TO(GetData::getDataHandler, "/getdata", Post);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

    static Json::Value getData(int fromId, int count);
    void getDataHandler(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);

  private:
    // Для формирования json
    template<typename T>
    static void fromDbToJson(const drogon::orm::Row::Reference &from, Json::Value &to);
    template<typename T>
    static void fromDbToJson_array(const drogon::orm::Row::Reference &from, Json::Value &to);
    template<>
    static void fromDbToJson_array<std::string>(const drogon::orm::Row::Reference &from, Json::Value &to);
};
