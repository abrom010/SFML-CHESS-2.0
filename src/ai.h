#pragma once
#include <vector>
#include "board.h"
class Ai
{
public:
	static Board::Move FindBestMove(Board);
	static std::vector<Board::Move> GetAllPossibleMoves(Board);

};

