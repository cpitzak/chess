#pragma once
#include <map>
#include<vector>
#include "Piece.h"
#include "Move.h"

namespace Aqua_chess 
{
	class Board
	{
	public:
		Board();
		~Board();

		Piece *get_piece(Coordinate rank, Coordinate file);
		bool is_occupied(Coordinate rank, Coordinate file);
		bool make_move(std::string move_coordinates);
		bool make_move(Move &move);

		friend std::ostream &operator<<(std::ostream &out, const Board &b);

	private:
		const short int BOARD_DIMENSION = 8;
		std::vector<std::vector<Piece*>> board;
	};
}
