#include <assert.h>
#include "Bishop.h"
#include "Board.h"

namespace Aqua_chess
{
	Aqua_chess::Bishop::Bishop(Coordinate rank_, Coordinate file_, Piece_color color_) : Piece(rank_, file_, color_)
	{
	}

	Bishop::~Bishop()
	{
		//std::cout << "deleted Bishop" << std::endl;
	}
	std::vector<Move> Bishop::get_possible_moves(Board &board)
	{
		assert(board.get_piece(rank, file) == this);
		std::vector<Move> moves = std::vector<Move>();
		// north east
		for (int i = rank - 1, j = file + 1; i >= Coordinate::RANK_8 && j <= Coordinate::FILE_H; --i, ++j) {
			Coordinate next_rank = static_cast<Coordinate>(i);
			Coordinate next_file = static_cast<Coordinate>(j);
			Piece *piece = board.get_piece(next_rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, next_rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, next_rank, next_file);
				moves.push_back(move);
				break;
			}
			else if (piece->get_color() == color) {
				break;
			}
		}
		// south east
		for (int i = rank + 1, j = file + 1; i <= Coordinate::RANK_1 && j <= Coordinate::FILE_H; ++i, ++j) {
			Coordinate next_rank = static_cast<Coordinate>(i);
			Coordinate next_file = static_cast<Coordinate>(j);
			Piece *piece = board.get_piece(next_rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, next_rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, next_rank, next_file);
				moves.push_back(move);
				break;
			}
			else if (piece->get_color() == color) {
				break;
			}
		}
		// south west
		for (int i = rank + 1, j = file - 1; i <= Coordinate::RANK_1 && j >= Coordinate::FILE_A; ++i, --j) {
			Coordinate next_rank = static_cast<Coordinate>(i);
			Coordinate next_file = static_cast<Coordinate>(j);
			Piece *piece = board.get_piece(next_rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, next_rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, next_rank, next_file);
				moves.push_back(move);
				break;
			}
			else if (piece->get_color() == color) {
				break;
			}
		}
		// north west
		for (int i = rank - 1, j = file - 1; i >= Coordinate::RANK_8 && j >= Coordinate::FILE_A; --i, --j) {
			Coordinate next_rank = static_cast<Coordinate>(i);
			Coordinate next_file = static_cast<Coordinate>(j);
			Piece *piece = board.get_piece(next_rank, next_file);
			if (!piece) {
				Move move = Move(rank, file, next_rank, next_file);
				moves.push_back(move);
			}
			else if (piece->get_color() != color) {
				Move move = Move(rank, file, next_rank, next_file);
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
