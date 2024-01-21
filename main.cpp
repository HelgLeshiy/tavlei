/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "framework/app.hpp"
#include "states/root_state.hpp"
#include <algorithm>
#include <memory>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main( int argc, char* args[] )
{
	framework::Configuration conf {
		"tavlei",
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0
	};


	framework::App app{std::move(conf)};
	auto root_state = std::make_unique<tavlei::states::RootState>();
	app.Run(std::move(root_state));

	return 0;
}
