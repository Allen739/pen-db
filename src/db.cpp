#include "db.hpp"

void MiniDB::set(const std::string& key, const std::string& value) {
    store[key] = value;
}

std::optional<std::string> MiniDB::get(const std::string& key) {
    if(store.find(key) != store.end()) {
        return store[key];
    }
    return std::nullopt;
}

bool MiniDB::del(const std::string& key) {
    return store.erase(key) > 0;
}
