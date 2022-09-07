#include<iostream>
#include <stdexcept>
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Coordinate.h"
#include "Move_factory.h"

namespace Aqua_chess
{
	Board::Board() : board{ BOARD_DIMENSION, std::vector<Piece*>(BOARD_DIMENSION)}
	{
		// setup black pieces
		board[Coordinate::RANK_8][Coordinate::FILE_A] = new Rook(Coordinate::RANK_8, Coordinate::FILE_A, Piece_color::Black);
		board[Coordinate::RANK_8][Coordinate::FILE_B] = new Knight(Coordinate::RANK_8, Coordinate::FILE_B, Piece_color::Black);
		board[Coordinate::RANK_8][Coordinate::FILE_C] = new Bishop(Coordinate::RANK_8, Coordinate::FILE_C, Piece_color::Black);
		board[Coordinate::RANK_8][Coordinate::FILE_D] = new Queen(Coordinate::RANK_8, Coordinate::FILE_D, Piece_color::Black);
		board[Coordinate::RANK_8][Coordinate::FILE_E] = new King(Coordinate::RANK_8, Coordinate::FILE_E, Piece_color::Black);
		board[Coordinate::RANK_8][Coordinate::FILE_F] = new Bishop(Coordinate::RANK_8, Coordinate::FILE_F, Piece_color::Black);
		board[Coordinate::RANK_8][Coordinate::FILE_G] = new Knight(Coordinate::RANK_8, Coordinate::FILE_G, Piece_color::Black);
		board[Coordinate::RANK_8][Coordinate::FILE_H] = new Rook(Coordinate::RANK_8, Coordinate::FILE_H, Piece_color::Black);
		for(int i = Coordinate::FILE_A; i <= Coordinate::FILE_H; ++i) {
			Coordinate file = static_cast<Coordinate>(i);
			board[Coordinate::RANK_7][file] = new Pawn(Coordinate::RANK_7, file, Piece_color::Black);
		}

		// setup white pieces
		board[Coordinate::RANK_1][Coordinate::FILE_A] = new Rook(Coordinate::RANK_1, Coordinate::FILE_A, Piece_color::White);
		board[Coordinate::RANK_1][Coordinate::FILE_B] = new Knight(Coordinate::RANK_1, Coordinate::FILE_B, Piece_color::White);
		board[Coordinate::RANK_1][Coordinate::FILE_C] = new Bishop(Coordinate::RANK_1, Coordinate::FILE_C, Piece_color::White);
		board[Coordinate::RANK_1][Coordinate::FILE_D] = new Queen(Coordinate::RANK_1, Coordinate::FILE_D, Piece_color::White);
		board[Coordinate::RANK_1][Coordinate::FILE_E] = new King(Coordinate::RANK_1, Coordinate::FILE_E, Piece_color::White);
		board[Coordinate::RANK_1][Coordinate::FILE_F] = new Bishop(Coordinate::RANK_1, Coordinate::FILE_F, Piece_color::White);
		board[Coordinate::RANK_1][Coordinate::FILE_G] = new Knight(Coordinate::RANK_1, Coordinate::FILE_G, Piece_color::White);
		board[Coordinate::RANK_1][Coordinate::FILE_H] = new Rook(Coordinate::RANK_1, Coordinate::FILE_H, Piece_color::White);
		for (int i = Coordinate::FILE_A; i <= Coordinate::FILE_H; ++i) {
			Coordinate file = static_cast<Coordinate>(i);
			board[Coordinate::RANK_2][file] = new Pawn(Coordinate::RANK_2, file, Piece_color::White);
		}

		std::vector<Move> moves = board[Coordinate::RANK_8][Coordinate::FILE_A]->get_possible_moves(*this);

	}


	Board::~Board()
	{
		for (auto& row : board) {
			for (auto& piece : row) {
				if (piece) {
					delete piece;
					piece = nullptr;
				}
			}
		}
		//std::cout << "deleted pieces" << std::endl;
	}

	Piece * Board::get_piece(Coordinate rank, Coordinate file)
	{
		return board[rank][file];
	}

	bool Board::is_occupied(Coordinate file, Coordinate rank)
	{
		return !(board[rank][file] == nullptr);
	}

	bool Board::make_move(std::string move_coordinates)
	{
		try {
			Move move = Move_factory::create(move_coordinates);
			return make_move(move);
		}
		catch (const std::invalid_argument& e) {
			return false;
		}
		return false;
	}

	bool Board::make_move(Move &move)
	{
		// TOOD: validate before making move
		Piece *piece = board[move.get_from_rank()][move.get_from_file()];
		if (board[move.get_to_rank()][move.get_to_file()]) {
			delete board[move.get_to_rank()][move.get_to_file()];
			board[move.get_to_rank()][move.get_to_file()] = nullptr;
		}
		piece->set_rank(move.get_to_rank());
		piece->set_file(move.get_to_file());
		board[move.get_to_rank()][move.get_to_file()] = piece;
		board[move.get_from_rank()][move.get_from_file()] = nullptr;
		return true;
	}

	std::ostream & operator<<(std::ostream & out, const Board &b)
	{
		for (auto& row : b.board) {
			for (auto& piece : row) {
				if (dynamic_cast<Rook*>(piece)) {
					if (piece->get_color() == Piece_color::White) {
						std::cout << "R ";
					}
					else {
						std::cout << "r ";
					}
				}
				else if (dynamic_cast<Knight*>(piece)) {
					if (piece->get_color() == Piece_color::White) {
						std::cout << "N ";
					}
					else {
						std::cout << "n ";
					}
				}
				else if (dynamic_cast<Bishop*>(piece)) {
					if (piece->get_color() == Piece_color::White) {
						std::cout << "B ";
					}
					else {
						std::cout << "b ";
					}
				}
				else if (dynamic_cast<Queen*>(piece)) {
					if (piece->get_color() == Piece_color::White) {
						std::cout << "Q ";
					}
					else {
						std::cout << "q ";
					}
				}
				else if (dynamic_cast<King*>(piece)) {
					if (piece->get_color() == Piece_color::White) {
						std::cout << "K ";
					}
					else {
						std::cout << "k ";
					}
				}
				else if (dynamic_cast<Pawn*>(piece)) {
					if (piece->get_color() == Piece_color::White) {
						std::cout << "P ";
					}
					else {
						std::cout << "p ";
					}
				}
				else {
					std::cout << ". ";
				}
			}
			if (&row != &b.board.back()) {
				std::cout << std::endl;
			}
		}
		return out;
	}

}
