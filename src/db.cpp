#include "db.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor
MiniDB::MiniDB(const std::string& file) : filename(file) {
    loadFromFile();
}

// Load existing data
void MiniDB::loadFromFile() {
    std::ifstream infile(filename);
    if (!infile.is_open()) return;

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            store[key] = value;
        }
    }
    infile.close();
}

// Save all data to file
void MiniDB::saveToFile() {
    std::ofstream outfile(filename);
    for (auto& [key, value] : store) {
        outfile << key << "=" << value << "\n";
    }
    outfile.close();
}

void MiniDB::set(const std::string& key, const std::string& value) {
    store[key] = value;
    saveToFile();
}

std::optional<std::string> MiniDB::get(const std::string& key) {
    if(store.find(key) != store.end()) {
        return store[key];
    }
    return std::nullopt;
}

bool MiniDB::del(const std::string& key) {
    bool existed = store.erase(key) > 0;
    if(existed) saveToFile();
    return existed;
}
