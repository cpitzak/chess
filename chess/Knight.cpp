#include "Knight.h"

namespace Aqua_chess
{
	Aqua_chess::Knight::Knight(Coordinate rank_, Coordinate file_, Piece_color color_) : Piece(rank_, file_, color_)
	{
	}

	Knight::~Knight()
	{
		//std::cout << "deleted Knight" << std::endl;
	}
	std::vector<Move> Knight::get_possible_moves(Board &board)
	{
		return std::vector<Move>();
	}
}
