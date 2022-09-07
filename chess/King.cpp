#include <assert.h>
#include "King.h"
#include "Board.h"

namespace Aqua_chess 
{
	King::King(Coordinate rank_, Coordinate file_, Piece_color color_) : Piece(rank_, file_, color_)
	{
	}
	King::~King()
	{
		//std::cout << "deleted King" << std::endl;
	}

	std::vector<Move> King::get_possible_moves(Board &board)
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
		// south
		if (rank < Coordinate::RANK_1) {
			Coordinate next_rank = static_cast<Coordinate>(rank + 1);
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
		// east
		if (file < Coordinate::FILE_H) {
			Coordinate next_file = static_cast<Coordinate>(file + 1);
			Piece *piece = board.get_piece(rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
			}
		}
		// west
		if (file > Coordinate::FILE_A) {
			Coordinate next_file = static_cast<Coordinate>(file - 1);
			Piece *piece = board.get_piece(rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
			}
		}
		return moves;
	}

}
