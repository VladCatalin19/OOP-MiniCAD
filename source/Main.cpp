#include "Utils/Constants.h"
#include "App/App.h"

#include <iostream>

// http://elf.cs.pub.ro/poo/arhiva/teme/2017/tema2
int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <input file> <output file>\n";
		return Errors::NotEnoughArguments;
	}

	App app = App();
	app.ReadFromFile(argv[1]);
	app.Run();
	app.WriteToFile(argv[2]);

	return 0;
}