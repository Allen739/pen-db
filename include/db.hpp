#pragma once
#include <unordered_map>
#include <string>
#include <optional>


class MiniDB  {
    private:
        std::unordered_map<std::string, std::string> store;

    public:
        void set(const std::string&  key, const std::string& value);
        std::optional<std::string> get(const std::string& key);
        bool del(const std::string& key);
};