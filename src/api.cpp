#include "db.hpp"
#include "httplib.h"
#include <iostream>

int main() {
    MiniDB db("data.txt"); // persistent backend
    httplib::Server svr;

    // SET key=value
    svr.Post("/set", [&](const httplib::Request& req, httplib::Response& res){
        auto key = req.get_param_value("key");
        auto value = req.get_param_value("value");
        db.set(key, value);
        res.set_content("OK", "text/plain");
    });

    // GET key
    svr.Get("/get", [&](const httplib::Request& req, httplib::Response& res){
        auto key = req.get_param_value("key");
        auto val = db.get(key);
        if(val) res.set_content(*val, "text/plain");
        else res.set_content("NULL", "text/plain");
    });

    // DELETE key
    svr.Post("/delete", [&](const httplib::Request& req, httplib::Response& res){
        auto key = req.get_param_value("key");
        if(db.del(key)) res.set_content("OK", "text/plain");
        else res.set_content("NULL", "text/plain");
    });

    // VIEW ALL key-value pairs
    svr.Get("/all", [&](const httplib::Request& req, httplib::Response& res){
        (void)req; // unused
        auto allData = db.getAll();
        std::string result;
        for(auto& [key, value] : allData) {
            result += key + " = " + value + "\n";
        }
        res.set_content(result.empty() ? "No data" : result, "text/plain");
    });

    std::cout << "MiniAI-DB API running on http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);
}
