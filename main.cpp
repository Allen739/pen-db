#include <iostream>
#include "db.hpp"

int main() {
    MiniDB db;
    db.set("name", "Lulu");
    db.set("project", "mini-ai-db");

    auto val = db.get("name");
    if(val) std::cout << "name: " << *val << std::endl;

    db.del("project");

    return 0;
}
