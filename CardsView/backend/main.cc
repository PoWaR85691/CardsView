#include <drogon/drogon.h>
int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("127.0.0.1",8088);
    drogon::app().createDbClient("postgresql", "127.0.0.1", 5432, "CardsView", "postgres", "admin");
    drogon::app().run();
    return 0;
}
