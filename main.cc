#include "crow_all.h"

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")
  ([]() {
    return "<!DOCTYPE HTML><head>"
           "</head><body>"
           "<p>External image:</p>"
           "<img src=\"static/image.svg\"></img>"
           "<p><a href=\"/static/site.html\">static</a></p>"
           "<p><a href=\"/route/site.html\">via route</a></p>"
           "</body>";
  });

  CROW_ROUTE(app, "/route/site.html")
  ([]() {
    return "<!DOCTYPE HTML><head>"
           "</head><body>"
           "<p>External image:</p>"
           "<img src=\"image.svg\"></img>"
           "<p><a href=\"/route/site.html\">static</a></p>"
           "<p><a href=\"/\">back to template</a></span>"
           "</body>";
  });

  CROW_ROUTE(app, "/route/image.svg")
  ([](const crow::request&, crow::response &res) {
    res.set_static_file_info("static/image.svg");
    res.end();
  });

  app.port(8080).run();
}
