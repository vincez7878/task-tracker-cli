#include "readwrite.hpp"

using json = nlohmann::json;

json ReadFile(const std::string& filename) {
    std::ifstream ifs{filename};
    if (!ifs.is_open()) {
        return json::array();
    }
    json j = json::parse(ifs);
    return j;
}


void WriteFile(const nlohmann::json& j, const std::string& filename) {
    std::ofstream ofs(filename);
    if (ofs.is_open()) {
        ofs << j.dump(4);
    }
    else {
        throw std::runtime_error("couldn't open json file");
    }
}