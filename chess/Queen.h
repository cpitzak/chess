#pragma once
#include "Piece.h"

namespace Aqua_chess
{
	class Queen : public Piece
	{
	public:
		Queen(Coordinate rank_, Coordinate file_, Piece_color color_);
		~Queen();

		std::vector<Move> get_possible_moves(Board &board);
	};
}
