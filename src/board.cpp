#include "board.h"

Board::Piece Board::GetPieceAtPosition(Position position)
{
	return boardArray[position.y][position.x];
}

int Board::GetStaticEvaluation()
{
	int score = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			score += pieceValues[boardArray[i][j]];
		}
	}
	return score;
}

bool Board::UpdateBoard(Board::Move move)
{
	std::set<Board::Position> possibleMoves = GetPossibleMovesByPiece(move.start);

	// if move in possible moves
	if (possibleMoves.find(move.end) != possibleMoves.end())
	{
		// move piece
		boardArray[move.end.y][move.end.x] = boardArray[move.start.y][move.start.x];
		boardArray[move.start.y][move.start.x] = Board::Piece::None;
		return true;
	}
	else return false;
}


std::set<Board::Position> Board::GetPossibleMovesByPiece(Board::Position position)
{
	std::set<Board::Position> possibleMoves;

	Piece piece = boardArray[position.y][position.x];

	switch (piece)
	{
	case Piece::BlackRook:
		break;
	case Piece::BlackKnight:
		break;
	case Piece::BlackBishop:
		break;
	case Piece::BlackQueen:
		break;
	case Piece::BlackKing:
		break;
	case Piece::BlackPawn:
		break;

	case Piece::WhiteRook:
		break;
	case Piece::WhiteKnight:
		break;
	case Piece::WhiteBishop:
		break;
	case Piece::WhiteQueen:
		break;
	case Piece::WhiteKing:
		break;
	case Piece::WhitePawn:
		break;
	}

	return possibleMoves;
}

bool Board::IsPieceBlack(Piece piece)
{
	return
		piece == Piece::BlackRook ||
		piece == Piece::BlackKnight ||
		piece == Piece::BlackBishop ||
		piece == Piece::BlackQueen ||
		piece == Piece::BlackKing ||
		piece == Piece::BlackPawn;
}
