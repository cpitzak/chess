#pragma once
#include "Piece.h"
namespace Aqua_chess 
{
	class King : public Piece
	{
	public:
		King(Coordinate rank_, Coordinate file_, Piece_color color_);
		~King();

		std::vector<Move> get_possible_moves(Board &board);
	};
}
