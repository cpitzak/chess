#pragma once
#include <map>
#include <string>
#include <utility>
#include "Coordinate.h"

namespace Aqua_chess
{
	class Console_ui
	{
	public:
		Console_ui();
		~Console_ui();
	private:
		std::map<std::string, std::pair<Coordinate, Coordinate>> str_to_coords = { 
			{"e2", std::make_pair(Coordinate::FILE_E, Coordinate::RANK_2)},
			{"e4", std::make_pair(Coordinate::FILE_A, Coordinate::RANK_4)}
		};
	};
}
