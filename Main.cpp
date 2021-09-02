#include "Program.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Program program;
    switch(argc)
    {
        case 1:
            // Create empty window
            break;
        case 2:
            // Load pathname and project image onto window
            if (!program.LoadCellsFromImage(argv[1]))
            {
                std::cout << "Failure reading \"" << argv[1] << "\". " << "Invalid pathname or file type" << std::endl;
                return -1;
            }
            break;
        default:
            // invalid usage
            std::cout << "Usage: Game-Of-Life.exe [path to image]" << std::endl;
            return -1;
    }
}