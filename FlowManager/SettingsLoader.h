#pragma once
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <qdebug.h>

namespace fm2 {
    class ConfigLoader {
    public:
        ConfigLoader();
        bool LoadConfigFile(const std::string& file_path, const std::string& file_name);
        template <typename T>
        bool getValue(std::string yaml_name, std::vector<std::string> path, T* value);
    private:
        std::unordered_map<std::string, YAML::Node> yamls;
    };

    template <typename T>
    bool ConfigLoader::getValue(
            std::string yaml_name, 
            std::vector<std::string> path, 
            T* value) {
        YAML::Node Config = yamls.find(yaml_name)->second;
        if (!Config) {
            qDebug() << "No aviliable config.\n";
            return false;
        }
        auto father_pair = Config;
        auto son_pair = Config[""];
        auto p = path[0];
        for (int i = 0; i < path.size(); i++) {
            p = path[i];
            if (Config[p]) {
                son_pair = father_pair[p];
            }
            else {
                qDebug() << "Config has no " << p.c_str() << "\n";
                return false;
            }
            if (i == path.size() - 1) {
                *value = son_pair.as<T>();
            }
            else {
                father_pair = son_pair;
            }   
        }
        return true;
    }
}

