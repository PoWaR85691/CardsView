#include "CardsView.h"
#include "GetData.h"

// Add definition of your processing function here
drogon::HttpResponsePtr CardsView::staticView = nullptr;
const int STATIC_COUNT = 12;

void CardsView::updateStaticView()
{
    LOG_DEBUG << "StaticView updated\n";
    Json::Value staticData = GetData::getData(0, STATIC_COUNT);
    HttpViewData param;
    param.insert("staticData", staticData);
    staticView = HttpResponse::newHttpViewResponse("CardsView.csp", param);
}

const drogon::HttpResponsePtr &CardsView::getStaticView()
{
    if (!staticView)
    {
        updateStaticView();
    }
    return staticView;
}

void CardsView::mainHandler(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    callback(getStaticView());
}
