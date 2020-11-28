#include <iostream>

#include "parser.h"
#include "timeline.h"
#include "generator.h"

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

    try
    {
        flipl::AST ast (sourceFile);
        flipl::Timeline timeline (ast);
        flipl::Generator gen;
        if (gen.GenerateFrames(timeline))
        {
            gen.WriteOut("sample.gif");
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
