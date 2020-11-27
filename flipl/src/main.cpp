#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Magick++.h"

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cout << "Usage: flipl <path-to-file>" << std::endl;
        return 0;
    }

    std::string sourceFile (argv[1]);

#ifdef _WIN32
    // Replace slash for Windows filepaths
    std::replace(sourceFile.begin(), sourceFile.end(), '\\', '/');
#endif

    std::string rootDir =  sourceFile.substr(0, sourceFile.find_last_of('/') + 1);

    std::cout << rootDir << std::endl;

    // Read image paths
    std::ifstream in (argv[1]);
    std::string line;
    std::vector<std::string> framePaths;
    while (std::getline(in, line))
    {
        framePaths.push_back(rootDir + line);
    }

#ifdef _WIN32
    // Magick must be initialized on Windows
    Magick::InitializeMagick(MAGICK_DLLS);
#endif

    std::vector<Magick::Image> frames;

    for (const auto& path : framePaths)
    {
        frames.emplace_back(path);
    }

    Magick::writeImages(frames.begin(), frames.end(), "sample.gif");

    return 0;
}
