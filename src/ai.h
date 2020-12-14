#pragma once
#include <vector>
#include "board.h"
class Ai
{
public:
	static Board::Move FindBestMove(Board);
	static std::vector<Board::Move> GetAllPossibleBlackMoves(Board);
	static std::vector<Board::Move> GetAllPossibleWhiteMoves(Board);

	static int Maxi(int, Board);
	static int Mini(int, Board);
};

