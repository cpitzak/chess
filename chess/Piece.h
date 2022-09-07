#pragma once
#include <iostream>
#include<vector>
#include "Move.h"
#include "Piece_color.h"

namespace Aqua_chess
{
	// forward delcaration of Board to resolve circular dependency
	class Board;

	class Piece
	{
	public:
		Piece(Coordinate rank_, Coordinate file_, Piece_color color_);
		virtual ~Piece() = 0; // Piece is now an abstract class

		Piece_color get_color() const;
		void set_rank(Coordinate rank_);
		void set_file(Coordinate file_);
		/*
		In C++11 the preferred way is to return the vector by value. With C++11, std::vector has move-semantics,
		which means the local vector declared in your function will be moved on return and in some cases even the 
		move can be elided by the compiler.
		*/
		virtual std::vector<Move> get_possible_moves(Board &board) = 0; // pure virtual function

	protected:
		Coordinate rank;
		Coordinate file;
		Piece_color color;
	};
}
