#pragma once
#include <string>
#include "Move.h"


namespace Aqua_chess
{
	class Move_factory
	{
	public:
		~Move_factory();
		static Move create(std::string move_coordinates);
	private:
		Move_factory() {}
		static Coordinate coordinate_from_str(char coordinate);
	};
}
