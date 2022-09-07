#pragma once
#include "Piece.h"

namespace Aqua_chess
{
	class Rook : public Piece
	{
	public:
		Rook(Coordinate rank_, Coordinate file_, Piece_color color_);
		~Rook();

		std::vector<Move> get_possible_moves(Board &board);
	};
}
