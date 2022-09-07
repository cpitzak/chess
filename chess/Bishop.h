#pragma once
#include "Piece.h"

namespace Aqua_chess
{
	class Bishop : public Piece
	{
	public:
		Bishop(Coordinate rank_, Coordinate file_, Piece_color color_);
		~Bishop();

		std::vector<Move> get_possible_moves(Board &board);
	};
}
