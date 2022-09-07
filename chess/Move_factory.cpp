#include <stdexcept>
#include "Move_factory.h"

namespace Aqua_chess
{
	Move_factory::~Move_factory()
	{
	}

	Move Move_factory::create(std::string move_coordinates)
	{
		bool success = true;
		if (move_coordinates.size() != 4) {
			throw std::invalid_argument("Error: Invalid coordinates");
		}
		char f_file = move_coordinates.substr(0, 1).c_str()[0];
		char f_rank = move_coordinates.substr(1, 1).c_str()[0];

		char t_file = move_coordinates.substr(2, 1).c_str()[0];
		char t_rank = move_coordinates.substr(3, 1).c_str()[0];

		Coordinate from_file = coordinate_from_str(f_file);
		Coordinate from_rank = coordinate_from_str(f_rank);
		Coordinate to_file = coordinate_from_str(t_file);
		Coordinate to_rank = coordinate_from_str(t_rank);

		return Move(from_rank, from_file, to_rank, to_file);
	}

	Coordinate Move_factory::coordinate_from_str(char coordinate)
	{
		switch (coordinate) {
		case 'a':
			return Coordinate::FILE_A;
		case 'b':
			return Coordinate::FILE_B;
		case 'c':
			return Coordinate::FILE_C;
		case 'd':
			return Coordinate::FILE_D;
		case 'e':
			return Coordinate::FILE_E;
		case 'f':
			return Coordinate::FILE_F;
		case 'g':
			return Coordinate::FILE_G;
		case 'h':
			return Coordinate::FILE_H;
		case '1' :
			return Coordinate::RANK_1;
		case '2':
			return Coordinate::RANK_2;
		case '3':
			return Coordinate::RANK_3;
		case '4':
			return Coordinate::RANK_4;
		case '5':
			return Coordinate::RANK_5;
		case '6':
			return Coordinate::RANK_6;
		case '7':
			return Coordinate::RANK_7;
		case '8':
			return Coordinate::RANK_8;
		}
		throw std::invalid_argument("Error: Invalid coordinates");
	}
}
