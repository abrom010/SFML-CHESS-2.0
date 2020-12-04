#pragma once
#include <vector>
#include <set>
#include <unordered_map>

class Board
{
public:
	bool gameOver = false;

	class Position
	{
	public:
		int x, y;
		Position(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		Position()
		{
			this->x = 0;
			this->y = 0;
		}
	};

	class Move
	{
	public:
		Position start, end;
		Move(Position start, Position end)
		{
			this->start = start;
			this->end = end;
		}
	};

	enum class Piece
	{
		BlackRook, BlackKnight, BlackBishop, BlackQueen, BlackKing, BlackPawn,
		WhiteRook, WhiteKnight, WhiteBishop, WhiteQueen, WhiteKing, WhitePawn,
		None
	};

	std::vector<std::vector<Piece>> boardArray
	{
		{ Piece::BlackRook, Piece::BlackKnight, Piece::BlackBishop, Piece::BlackQueen, Piece::BlackKing, Piece::BlackBishop, Piece::BlackKnight, Piece::BlackRook},
		{ Piece::BlackPawn, Piece::BlackPawn, Piece::BlackPawn, Piece::BlackPawn, Piece::BlackPawn, Piece::BlackPawn, Piece::BlackPawn, Piece::BlackPawn },
		{ Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None },
		{ Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None },
		{ Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None },
		{ Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None, Piece::None },
		{ Piece::WhitePawn, Piece::WhitePawn, Piece::WhitePawn, Piece::WhitePawn, Piece::WhitePawn, Piece::WhitePawn, Piece::WhitePawn, Piece::WhitePawn },
		{ Piece::WhiteRook, Piece::WhiteKnight, Piece::WhiteBishop , Piece::WhiteQueen, Piece::WhiteKing , Piece::WhiteBishop, Piece::WhiteKnight, Piece::WhiteRook },
	};

	std::unordered_map<Piece, int> pieceValues
	{
		{Piece::BlackPawn, 10},
		{Piece::BlackKnight, 30},
		{Piece::BlackBishop, 30},
		{Piece::BlackRook, 50},
		{Piece::BlackQueen, 90},
		{Piece::BlackKing, 900},

		{Piece::WhitePawn, -10},
		{Piece::WhiteKnight, -30},
		{Piece::WhiteBishop, -30},
		{Piece::WhiteRook, -50},
		{Piece::WhiteQueen, -90},
		{Piece::WhiteKing, -900},
	};

	std::set<Position> GetPossibleMovesByPiece(Position);
	Piece GetPieceAtPosition(Position);
	int GetStaticEvaluation();
	bool UpdateBoard(Move);
	bool IsPieceBlack(Piece);
};

