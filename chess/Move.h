#pragma once
#include "Coordinate.h"

namespace Aqua_chess
{
	class Move
	{
	public:
		Move(Coordinate f_rank, Coordinate f_file, Coordinate t_rank, Coordinate t_file);
		~Move();

		Coordinate get_from_rank() const;
		Coordinate get_from_file() const;
		Coordinate get_to_rank() const;
		Coordinate get_to_file() const;

	private:
		Coordinate from_rank;
		Coordinate from_file;
		Coordinate to_rank;
		Coordinate to_file;
	};
}


