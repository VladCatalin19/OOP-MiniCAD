#ifndef MINICAD_SOURCE_APP_APP_HPP_INCLUDED
#define MINICAD_SOURCE_APP_APP_HPP_INCLUDED

#include <string>				// std::string

namespace MiniCAD
{
    class App
    {
    public:
        static void Run(const std::string &input_file_name, const std::string &output_file_name);
    };
}

#endif // MINICAD_SOURCE_APP_APP_HPP_INCLUDED
