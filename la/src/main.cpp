#include "pch.h"
#include "App.h"

int main(int argc, char** argv)
{
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
