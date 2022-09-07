#pragma once
#include<vector>
#include "Piece.h"
#include "Piece_color.h"
namespace Aqua_chess
{
	class Pawn : public Piece
	{
	public:
		Pawn(Coordinate rank_, Coordinate file_, Piece_color color_);
		~Pawn();

		std::vector<Move> get_possible_moves(Board &board);
	};
}


