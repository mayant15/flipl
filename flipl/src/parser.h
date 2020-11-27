#pragma once

#include <yaml-cpp/yaml.h>
#include <fstream>

namespace flipl
{
    struct AST
    {
        YAML::Node root;
        std::string fileDir;

        AST(const std::string& infile)
        {
            root = YAML::LoadFile(infile);
            fileDir =  infile.substr(0, infile.find_last_of('/') + 1);
        }
    };
}
