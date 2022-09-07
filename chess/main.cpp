//#include <iostream>
//#include <string>
//#include "Board.h"
//#include "Piece.h"
//#include "King.h"
//#include "Piece_color.h"
//
//int main(int argc, char *argv[])
//{
//	Aqua_chess::Board board = Aqua_chess::Board();
//
//	bool is_game_over = false;
//
//	while (!is_game_over) {
//		std::cout << board << std::endl << std::endl;
//		std::cout << "Enter move (e2e4): ";
//		std::string input = "";
//		std::cin >> input;
//		std::string from = input.substr(0, 2);
//		std::string to = input.substr(2, 2);
//		if (!board.make_move(from, to)) {
//			std::cout << "invalid coordinates. try again." << std::endl;
//		}
//	}	
//	return 0;
//}