#include <iostream>
#include <sstream>
#include "db.hpp"

int main() {
    MiniDB db;
    std::string line;

    std::cout << "Welcome to MiniDB! Type 'exit' to quit.\n";

    while (true) {
        std::cout << "db> ";
        std::getline(std::cin, line);

        if (line == "exit") break;

        std::istringstream iss(line);
        std::string command, key, value;
        iss >> command >> key;

        if (command == "SET") {
            iss >> value;
            db.set(key, value);
            std::cout << "OK\n";
        }

        else if (command == "GET") {
            auto val = db.get(key);
            if (val) std::cout << *val << "\n";
            else std::cout << "NULL\n";
        }

        else if (command == "DEL") {
            if (db.del(key)) std::cout << "OK\n";
            else std::cout << "NULL\n";
        }

        else {
            std::cout << "Unknown command\n";
        }

    }

    return 0;
}
