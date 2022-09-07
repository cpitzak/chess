#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <vector>
#include "Board.h"
#include "Bishop.h"
#include "Coordinate.h"

TEST_CASE("Bishop possible moves after e2e3") {
	Aqua_chess::Board board = Aqua_chess::Board();
	REQUIRE(board.make_move("e2e3"));
	Aqua_chess::Piece *empty_piece = board.get_piece(Aqua_chess::Coordinate::RANK_2, Aqua_chess::Coordinate::FILE_E);
	Aqua_chess::Piece *pawn = board.get_piece(Aqua_chess::Coordinate::RANK_3, Aqua_chess::Coordinate::FILE_E);
	Aqua_chess::Bishop *bishop = dynamic_cast<Aqua_chess::Bishop*>(board.get_piece(Aqua_chess::Coordinate::RANK_1, Aqua_chess::Coordinate::FILE_F));
	REQUIRE(empty_piece == nullptr);
	REQUIRE(pawn != nullptr);
	REQUIRE(pawn->get_color() == Aqua_chess::Piece_color::White);
	REQUIRE(bishop != nullptr);
	REQUIRE(bishop->get_color() == Aqua_chess::Piece_color::White);

	std::vector<Aqua_chess::Move> possible_moves = bishop->get_possible_moves(board);
	REQUIRE(possible_moves.size() == 5);

	SECTION("bishop possible moves after a7a6") {
		REQUIRE(board.make_move("a7a6"));
		empty_piece = board.get_piece(Aqua_chess::Coordinate::RANK_7, Aqua_chess::Coordinate::FILE_A);
		pawn = board.get_piece(Aqua_chess::Coordinate::RANK_6, Aqua_chess::Coordinate::FILE_A);
		REQUIRE(empty_piece == nullptr);
		REQUIRE(pawn != nullptr);
		REQUIRE(pawn->get_color() == Aqua_chess::Piece_color::Black);

		std::vector<Aqua_chess::Move> possible_moves = bishop->get_possible_moves(board);
		REQUIRE(possible_moves.size() == 5);

		SECTION("bishop possible moves after c2c4") {
			REQUIRE(board.make_move("c2c4"));
			empty_piece = board.get_piece(Aqua_chess::Coordinate::RANK_2, Aqua_chess::Coordinate::FILE_C);
			pawn = board.get_piece(Aqua_chess::Coordinate::RANK_4, Aqua_chess::Coordinate::FILE_C);
			REQUIRE(empty_piece == nullptr);
			REQUIRE(pawn != nullptr);
			REQUIRE(pawn->get_color() == Aqua_chess::Piece_color::White);

			std::vector<Aqua_chess::Move> possible_moves = bishop->get_possible_moves(board);
			REQUIRE(possible_moves.size() == 2);
		}

	}

	
}