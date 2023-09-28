#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class CardsView : public drogon::HttpController<CardsView>
{
  private:
    static drogon::HttpResponsePtr staticView;
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(CardsView::get, "/{2}/{1}", Get); // path is /CardsView/{arg2}/{arg1}
    // METHOD_ADD(CardsView::your_method_name, "/{1}/{2}/list", Get); // path is /CardsView/{arg1}/{arg2}/list
    // ADD_METHOD_TO(CardsView::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

        ADD_METHOD_TO(CardsView::mainHandler, "/", Get);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

    void mainHandler(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);

    void updateStaticView();
    const drogon::HttpResponsePtr &getStaticView();
};
