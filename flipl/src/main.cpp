#include <iostream>
#include <fstream>
#include <string>

#include "application.h"

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cout << "Usage: fc <path-to-file>" << std::endl;
        return 0;
    }

    std::ifstream in (argv[1]);

    std::string token;
    while (std::getline(in, token))
    {
        std::cout << token;
    }

    return 0;
}
