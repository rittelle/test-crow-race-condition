#include "crow_all.h"

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")
  ([]() {
    return "<!DOCTYPE HTML><head>"
           "</head><body>"
           "<span>External image:</span>"
           "<img src=\"static/image.svg\"></img>"
           "<span><a href=\"/static/site.html\">static</a></span>"
           "</body>";
  });

  app.port(8080).run();
}
