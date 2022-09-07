#include "Move.h"

namespace Aqua_chess
{
	Move::Move(Coordinate f_rank, Coordinate f_file, Coordinate t_rank, Coordinate t_file) : from_rank{f_rank}, from_file{f_file}, to_rank{t_rank}, to_file{t_file}
	{
	}

	Move::~Move()
	{
	}
	Coordinate Move::get_from_file() const
	{
		return from_file;
	}
	Coordinate Move::get_from_rank() const
	{
		return from_rank;
	}
	Coordinate Move::get_to_file() const
	{
		return to_file;
	}
	Coordinate Move::get_to_rank() const
	{
		return to_rank;
	}
}
