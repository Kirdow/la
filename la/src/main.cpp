#include "pch.h"
#include "App.h"
#include "Flags.h"

int main(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if (arg == "-C")
			LA::SetFlags(LA::LAFlags_NoCLS, true);
	}

	auto app = LA::App::Get();
	if (!app)
	{
		std::cout << "Execution failed!\n";
		return 1;
	}

	app->Run();

	LA::App::Destroy();

	std::cout << "\nGoodbye!\n";

	return 0;
}
