#include "Piece.h"
#include "Board.h"

namespace Aqua_chess 
{
	Piece::Piece(Coordinate rank_, Coordinate file_, Piece_color color_) : rank{ rank_ }, file{ file_ }, color{ color_ }
	{

	}

	Piece::~Piece()
	{
	}

	Piece_color Piece::get_color() const
	{
		return color;
	}
	void Piece::set_rank(Coordinate rank_)
	{
		rank = rank_;
	}
	void Piece::set_file(Coordinate file_)
	{
		file = file_;
	}
}
