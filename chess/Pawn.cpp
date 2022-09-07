#include <assert.h>
#include <iostream>
#include "Pawn.h"
#include "Board.h"

namespace Aqua_chess
{
	Pawn::Pawn(Coordinate rank_, Coordinate file_, Piece_color color_) : Piece(rank_, file_, color_)
	{
	}

	Pawn::~Pawn()
	{
		//std::cout << "deleted Pawn" << std::endl;
	}

	std::vector<Move> Pawn::get_possible_moves(Board &board)
	{
		assert(board.get_piece(rank, file) == this);
		std::vector<Move> moves = std::vector<Move>();
		// north
		if (rank > Coordinate::RANK_8) {
			Coordinate next_rank = static_cast<Coordinate>(rank - 1);
			Piece *piece = board.get_piece(next_rank, file);
			if (!piece) {
				Move move = Move(rank, file, next_rank, file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, next_rank, file);
				moves.push_back(move);
			}
		}
		// first move so move twice

		// en passant

		return moves;
	}

}
