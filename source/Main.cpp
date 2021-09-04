#include "Utils/Constants.hpp"
#include <App/App.hpp>

#include <iostream>

// http://elf.cs.pub.ro/poo/arhiva/teme/2017/tema2
int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <input file> <output file>\n";
        return MiniCAD::Errors::NotEnoughArguments;
    }

    MiniCAD::App app = MiniCAD::App();
    app.ReadFromFile(argv[1]);
    app.Run();
    app.WriteToFile(argv[2]);

    return 0;
}
