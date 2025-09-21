#pragma once
#include <unordered_map>
#include <string>
#include <optional>

class MiniDB {
private:
    std::unordered_map<std::string, std::string> store;
    std::string filename;

    void loadFromFile();
    void saveToFile();

public:
    MiniDB(const std::string& file);
    void set(const std::string& key, const std::string& value);
    std::optional<std::string> get(const std::string& key);
    bool del(const std::string& key);
    std::unordered_map<std::string, std::string> getAll(); // for frontend
};
