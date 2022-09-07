#include <assert.h>
#include "Rook.h"
#include "Board.h"
#include "Move.h"

namespace Aqua_chess
{
	Aqua_chess::Rook::Rook(Coordinate rank_, Coordinate file_, Piece_color color_) : Piece(rank_, file_, color_)
	{
	}

	Rook::~Rook()
	{
		//std::cout << "deleted Rook" << std::endl;
	}
	std::vector<Move> Rook::get_possible_moves(Board &board)
	{
		assert(board.get_piece(rank, file) == this);
		std::vector<Move> moves = std::vector<Move>();
		// north
		for (int i = rank - 1 ; i >= Coordinate::RANK_8; --i) {
			Coordinate next_rank = static_cast<Coordinate>(i);
			Piece *piece = board.get_piece(next_rank, file);
			if (!piece) {
				Move move = Move(rank, file, next_rank, file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, next_rank, file);
				moves.push_back(move);
				break;
			}
			else if (piece->get_color() == color) {
				break;
			}
		}
		// south
		for (int i = rank + 1; i <= Coordinate::RANK_1; ++i) {
			Coordinate next_rank = static_cast<Coordinate>(i);
			Piece *piece = board.get_piece(next_rank, file);
			if (!piece) {
				Move move = Move(rank, file, next_rank, file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, next_rank, file);
				moves.push_back(move);
				break;
			}
			else if (piece->get_color() == color) {
				break;
			}
		}
		// east
		for (int i = file + 1; i <= Coordinate::FILE_H; ++i) {
			Coordinate next_file = static_cast<Coordinate>(i);
			Piece *piece = board.get_piece(rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
				break;
			}
			else if (piece->get_color() == color) {
				break;
			}
		}
		// west
		for (int i = file - 1; i >= Coordinate::FILE_A; --i) {
			Coordinate next_file = static_cast<Coordinate>(i);
			Piece *piece = board.get_piece(rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, rank, next_file);
				moves.push_back(move);
				break;
			}
			else if (piece->get_color() == color) {
				break;
			}
		}
		return moves;
	}
}
