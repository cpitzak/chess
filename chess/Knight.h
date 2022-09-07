#pragma once
#include "Piece.h"

namespace Aqua_chess
{
	class Knight : public Piece
	{
	public:
		Knight(Coordinate rank_, Coordinate file_, Piece_color color_);
		~Knight();
		
		std::vector<Move> get_possible_moves(Board &board);
	};
}
