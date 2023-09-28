#include "GetData.h"
#include "drogon/orm/DbClient.h"
#include <sstream>

// Add definition of your processing function here
template<typename T>
void GetData::fromDbToJson(const drogon::orm::Row::Reference &from, Json::Value &to)
{
    if (!from.isNull())
    {
        to = from.as<T>();
    }
    else
    {
        to.nullSingleton();
    }
}

template<typename T>
void GetData::fromDbToJson_array(const drogon::orm::Row::Reference &from, Json::Value &to)
{
    if (!from.isNull())
    {
        to.resize(0); // Пустой массив
        to = from.asArray<T>();
    }
    else
    {
        to.nullSingleton();
    }
}

template<>
void GetData::fromDbToJson_array<std::string>(const drogon::orm::Row::Reference &from, Json::Value &to)
{
    if (!from.isNull())
    {
        to.resize(0); // Пустой массив
        auto parser = from.getArrayParser();
        parser.getNext(); // Вход в массив
        auto next = parser.getNext();
        while (next.first != parser.row_end)
        {
            to.append(next.second);
            next = parser.getNext();
        }
    }
    else
    {
        to.nullSingleton();
    }
}

// Получение данных из БД
Json::Value GetData::getData(int fromId, int count)
{
    // Получаем данные из БД
    auto dbClient = drogon::app().getDbClient();
    auto selectResult = dbClient->execSqlSync(
        "SELECT id, link, name, image, video, logo, description, additional_mark, price, discount, links_to_description_stores, platforms, genres\n"
	    "FROM cards_view\n"
        "WHERE id >= $1\n"
        "ORDER BY id ASC\n"
        "LIMIT $2;", std::to_string(fromId), std::to_string(count)
    );

    // Формируем ответ
    Json::Value json;
    json["finalId"] = (selectResult.size() > 0) ? selectResult.back().at("id").as<int>() : fromId;
    json["data"].resize(0);
    for (auto &row : selectResult)
    {
        Json::Value item;

        fromDbToJson<std::string>(row.at("link"), item["link"]);
        fromDbToJson<std::string>(row.at("name"), item["name"]);
        fromDbToJson<std::string>(row.at("image"), item["image"]);
        fromDbToJson<std::string>(row.at("video"), item["video"]);
        fromDbToJson<std::string>(row.at("logo"), item["logo"]);
        fromDbToJson<std::string>(row.at("description"), item["description"]);
        fromDbToJson<std::string>(row.at("additional_mark"), item["additionalMark"]);
        fromDbToJson<float>(row.at("price"), item["price"]);
        fromDbToJson<float>(row.at("discount"), item["discount"]);
        // linksToDescriptionStores: { string: string }
        Json::Value array;
        fromDbToJson_array<std::string>(row.at("links_to_description_stores"), array);
        item["linksToDescriptionStores"] = Json::Value(Json::objectValue); // Пустой объект
        for (auto it = array.begin(); it != array.end();)
        {
            auto storeIt = it;
            ++it;
            auto linkIt = it;
            ++it;
            item["linksToDescriptionStores"][storeIt->asString()] = linkIt->asString(); 
        }
        // linksToDescriptionStores //
        fromDbToJson_array<std::string>(row.at("platforms"), item["platforms"]);
        fromDbToJson_array<std::string>(row.at("genres"), item["genres"]);
            
        json["data"].append(item);
    }

    return json;
}

// Обработчик запросов
void GetData::getDataHandler(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // Параметры запроса
    int fromId = req->jsonObject()->get("fromId", 0).asInt();
    int count = req->jsonObject()->get("count", 0).asInt();

    Json::Value json = getData(fromId, count);
    
    // Отправка ответа
    auto resp=HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}