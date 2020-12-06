#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "board.h"

std::vector<Board::Position> GetMovesBlackRook(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	for (int i = position.x - 1; i >= 0; i--)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(i, position.y));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(i, position.y));
		}
		else
		{
			if (!board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(i, position.y));
			}
			break;
		}
	}

	for (int i = position.x + 1; i < 8; i++)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(i, position.y));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(i, position.y));
		}
		else
		{
			if (!board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(i, position.y));
			}
			break;
		}
	}

	for (int i = position.y - 1; i >= 0; i--)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(position.x, i));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(position.x, i));
		}
		else
		{
			if (!board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(position.x, i));
			}
			break;
		}
	}

	for (int i = position.y + 1; i < 8; i++)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(position.x, i));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(position.x, i));
		}
		else
		{
			if (!board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(position.x, i));
			}
			break;
		}
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesBlackKnight(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	int x1 = position.x - 2;
	int x2 = position.x + 2;
	int y1 = position.y - 2;
	int y2 = position.y + 2;

	int x3 = position.x - 1;
	int x4 = position.x + 1;
	int y3 = position.y - 1;
	int y4 = position.y + 1;

	std::vector<Board::Position> positions;

	positions.push_back(Board::Position(x1, y3));
	positions.push_back(Board::Position(x1, y4));

	positions.push_back(Board::Position(x2, y3));
	positions.push_back(Board::Position(x2, y4));

	positions.push_back(Board::Position(x3, y1));
	positions.push_back(Board::Position(x3, y2));

	positions.push_back(Board::Position(x4, y1));
	positions.push_back(Board::Position(x4, y2));

	for (const Board::Position& pos : positions)
	{
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece == Board::Piece::None || !board.IsPieceBlack(piece) && piece != Board::Piece::Null)
		{
			possibleMoves.push_back(pos);
		}
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesBlackBishop(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	std::vector<Board::Position> positions;

	int x, y;

	x = position.x - 1;
	y = position.y - 1;
	while (x >= 0 && y >= 0)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (!board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x--;
		y--;
	}

	x = position.x - 1;
	y = position.y + 1;
	while (x >= 0 && y < 8)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (!board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x--;
		y++;
	}

	x = position.x + 1;
	y = position.y - 1;
	while (x < 8 && y >= 0)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (!board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x++;
		y--;
	}

	x = position.x + 1;
	y = position.y + 1;
	while (x < 8 && y < 8)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (!board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x++;
		y++;
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesBlackQueen(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	std::vector<Board::Position> rook = GetMovesBlackRook(board, position);
	std::vector<Board::Position> bishop = GetMovesBlackBishop(board, position);
	possibleMoves.insert(possibleMoves.end(), rook.begin(), rook.end());
	possibleMoves.insert(possibleMoves.end(), bishop.begin(), bishop.end());
	return possibleMoves;
}

std::vector<Board::Position> GetMovesBlackKing(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	int x0 = position.x;
	int x1 = position.x - 1;
	int x2 = position.x + 1;
	int y0 = position.y;
	int y1 = position.y - 1;
	int y2 = position.y + 1;

	std::vector<Board::Position> positions;
	positions.push_back(Board::Position(x0,y1));
	positions.push_back(Board::Position(x0,y2));

	positions.push_back(Board::Position(x1,y0));
	positions.push_back(Board::Position(x1,y1));
	positions.push_back(Board::Position(x1,y2));

	positions.push_back(Board::Position(x2,y0));
	positions.push_back(Board::Position(x2,y1));
	positions.push_back(Board::Position(x2,y2));
	
	for (const Board::Position& pos : positions)
	{
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None || !board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(pos);
			}
		}
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesBlackPawn(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	int x = position.x;
	int y = position.y + 1;
	int y2 = y + 1;
	Board::Position pos = Board::Position(x, y);
	Board::Piece piece = board.GetPieceAtPosition(pos);
	if (piece == Board::Piece::None) possibleMoves.push_back(pos);

	if (position.y == 1)
	{
		pos = Board::Position(x, y2);
		piece = board.GetPieceAtPosition(pos);
		if (piece == Board::Piece::None) possibleMoves.push_back(pos);
	}

	int x2 = position.x - 1;
	int x3 = position.x + 1;

	pos = Board::Position(x2, y);
	piece = board.GetPieceAtPosition(pos);
	if (piece != Board::Piece::None && !board.IsPieceBlack(piece) && piece!=Board::Piece::Null) possibleMoves.push_back(pos);

	pos = Board::Position(x3, y);
	piece = board.GetPieceAtPosition(pos);
	if (piece != Board::Piece::None && !board.IsPieceBlack(piece) && piece != Board::Piece::Null) possibleMoves.push_back(pos);
	return possibleMoves;
}

std::vector<Board::Position> GetMovesWhiteRook(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	for (int i = position.x - 1; i >= 0; i--)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(i, position.y));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(i, position.y));
		}
		else
		{
			if (board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(i, position.y));
			}
			break;
		}
	}

	for (int i = position.x + 1; i < 8; i++)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(i, position.y));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(i, position.y));
		}
		else
		{
			if (board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(i, position.y));
			}
			break;
		}
	}

	for (int i = position.y - 1; i >= 0; i--)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(position.x, i));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(position.x, i));
		}
		else
		{
			if (board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(position.x, i));
			}
			break;
		}
	}

	for (int i = position.y + 1; i < 8; i++)
	{
		Board::Piece piece = board.GetPieceAtPosition(Board::Position(position.x,i));
		if (piece == Board::Piece::None)
		{
			possibleMoves.push_back(Board::Position(position.x, i));
		}
		else
		{
			if (board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(Board::Position(position.x, i));
			}
			break;
		}
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesWhiteKnight(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	int x1 = position.x - 2;
	int x2 = position.x + 2;
	int y1 = position.y - 2;
	int y2 = position.y + 2;

	int x3 = position.x - 1;
	int x4 = position.x + 1;
	int y3 = position.y - 1;
	int y4 = position.y + 1;

	std::vector<Board::Position> positions;

	positions.push_back(Board::Position(x1, y3));
	positions.push_back(Board::Position(x1, y4));

	positions.push_back(Board::Position(x2, y3));
	positions.push_back(Board::Position(x2, y4));

	positions.push_back(Board::Position(x3, y1));
	positions.push_back(Board::Position(x3, y2));

	positions.push_back(Board::Position(x4, y1));
	positions.push_back(Board::Position(x4, y2));

	for (const Board::Position& pos : positions)
	{
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece == Board::Piece::None || board.IsPieceBlack(piece) && piece != Board::Piece::Null)
		{
			possibleMoves.push_back(pos);
		}
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesWhiteBishop(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	std::vector<Board::Position> positions;

	int x, y;

	x = position.x - 1;
	y = position.y - 1;
	while (x >= 0 && y >= 0)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{		
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x--;
		y--;
	}

	x = position.x - 1;
	y = position.y + 1;
	while (x >= 0 && y < 8)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x--;
		y++;
	}

	x = position.x + 1;
	y = position.y - 1;
	while (x < 8 && y >= 0)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x++;
		y--;
	}

	x = position.x + 1;
	y = position.y + 1;
	while (x < 8 && y < 8)
	{
		Board::Position pos(x, y);
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None)
			{
				possibleMoves.push_back(pos);
			}
			else
			{
				if (board.IsPieceBlack(piece))
				{
					possibleMoves.push_back(pos);
				}
				break;
			}
		}
		x++;
		y++;
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesWhiteQueen(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	std::vector<Board::Position> rook = GetMovesWhiteRook(board, position);
	std::vector<Board::Position> bishop = GetMovesWhiteBishop(board, position);
	possibleMoves.insert(possibleMoves.end(), rook.begin(), rook.end());
	possibleMoves.insert(possibleMoves.end(), bishop.begin(), bishop.end());
	return possibleMoves;
}

std::vector<Board::Position> GetMovesWhiteKing(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	int x0 = position.x;
	int x1 = position.x - 1;
	int x2 = position.x + 1;
	int y0 = position.y;
	int y1 = position.y - 1;
	int y2 = position.y + 1;

	std::vector<Board::Position> positions;
	positions.push_back(Board::Position(x0, y1));
	positions.push_back(Board::Position(x0, y2));

	positions.push_back(Board::Position(x1, y0));
	positions.push_back(Board::Position(x1, y1));
	positions.push_back(Board::Position(x1, y2));

	positions.push_back(Board::Position(x2, y0));
	positions.push_back(Board::Position(x2, y1));
	positions.push_back(Board::Position(x2, y2));

	for (const Board::Position& pos : positions)
	{
		Board::Piece piece = board.GetPieceAtPosition(pos);
		if (piece != Board::Piece::Null)
		{
			if (piece == Board::Piece::None || board.IsPieceBlack(piece))
			{
				possibleMoves.push_back(pos);
			}
		}
	}
	return possibleMoves;
}

std::vector<Board::Position> GetMovesWhitePawn(Board board, Board::Position position)
{
	std::vector<Board::Position> possibleMoves;
	int x = position.x;
	int y = position.y - 1;
	int y2 = y - 1;
	Board::Position pos = Board::Position(x, y);
	Board::Piece piece = board.GetPieceAtPosition(pos);
	if (piece == Board::Piece::None) possibleMoves.push_back(pos);

	if (position.y == 6)
	{
		pos = Board::Position(x, y2);
		piece = board.GetPieceAtPosition(pos);
		if (piece == Board::Piece::None) possibleMoves.push_back(pos);
	}

	int x2 = position.x - 1;
	int x3 = position.x + 1;

	pos = Board::Position(x2, y);
	piece = board.GetPieceAtPosition(pos);
	if (piece != Board::Piece::None && board.IsPieceBlack(piece) && piece != Board::Piece::Null) possibleMoves.push_back(pos);

	pos = Board::Position(x3, y);
	piece = board.GetPieceAtPosition(pos);
	if (piece != Board::Piece::None && board.IsPieceBlack(piece) && piece != Board::Piece::Null) possibleMoves.push_back(pos);
	
	return possibleMoves;
}

Board::Piece Board::GetPieceAtPosition(Position position)
{
	int x = position.x;
	int y = position.y;
	if (x < 8 && x >= 0 && y < 8 && y >= 0)
	{
		return boardArray[y][x];
	}
	else
	{
		return Board::Piece::Null;
	}
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
	std::vector<Board::Position> possibleMoves = GetPossibleMovesByPiece(move.start);

	if(std::find(possibleMoves.begin(), possibleMoves.end(), move.end) != possibleMoves.end())
	{
		boardArray[move.end.y][move.end.x] = boardArray[move.start.y][move.start.x];
		boardArray[move.start.y][move.start.x] = Board::Piece::None;
		return true;
	}
	else
{
		return false;
	}
}


std::vector<Board::Position> Board::GetPossibleMovesByPiece(Board::Position position)
{
	Piece piece = GetPieceAtPosition(position);

	switch (piece)
	{
	case Piece::BlackRook:
		return GetMovesBlackRook(*this, position);
	case Piece::BlackKnight:
		return GetMovesBlackKnight(*this, position);
	case Piece::BlackBishop:
		return GetMovesBlackBishop(*this, position);
	case Piece::BlackQueen:
		return GetMovesBlackQueen(*this, position);
	case Piece::BlackKing:
		return GetMovesBlackKing(*this, position);
	case Piece::BlackPawn:
		return GetMovesBlackPawn(*this, position);

	case Piece::WhiteRook:
		return GetMovesWhiteRook(*this, position);
	case Piece::WhiteKnight:
		return GetMovesWhiteKnight(*this, position);
	case Piece::WhiteBishop:
		return GetMovesWhiteBishop(*this, position);
	case Piece::WhiteQueen:
		return GetMovesWhiteQueen(*this, position);
	case Piece::WhiteKing:
		return GetMovesWhiteKing(*this, position);
	case Piece::WhitePawn:
		return GetMovesWhitePawn(*this, position);

	case Piece::None:
		std::vector<Board::Position> empty;
		return empty;
	}
}

bool Board::IsPieceBlack(Piece piece)
{
	return
		(
			piece == Piece::BlackRook ||
			piece == Piece::BlackKnight ||
			piece == Piece::BlackBishop ||
			piece == Piece::BlackQueen ||
			piece == Piece::BlackKing ||
			piece == Piece::BlackPawn
		);
}