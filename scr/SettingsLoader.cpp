#include "FlowManager/SettingsLoader.h"

namespace fm2 {
    ConfigLoader::ConfigLoader() {

    }
    
    bool ConfigLoader::LoadConfigFile(
        const std::string& file_path, const std::string& file_name
    ) {
        auto Config = YAML::LoadFile(file_path);
        if (!Config) {
            std::cout << "Open config File:" << file_name << " failed.";
            return false;
        }
        yamls.insert({ file_name, Config });

        return true;
    }
    
}