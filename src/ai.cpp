#include <vector>
#include <iostream>
#include "ai.h"

std::vector<Board::Move> Ai::GetAllPossibleBlackMoves(Board board)
{
    std::vector<Board::Move> moves;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Board::Piece piece = board.GetPieceAtPosition(Board::Position(i, j));
            if (board.IsPieceBlack(piece))
            {
                Board::Position startingPosition(i, j);
                for (auto endingPosition : board.GetPossibleMovesByPiece(startingPosition))
                {
                    Board::Move move = Board::Move(startingPosition, endingPosition);
                    moves.push_back(move);
                }
                
            }
        }
    }
    return moves;
}

std::vector<Board::Move> Ai::GetAllPossibleWhiteMoves(Board board)
{
	std::vector<Board::Move> moves;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Board::Piece piece = board.GetPieceAtPosition(Board::Position(i, j));
				if (!board.IsPieceBlack(piece))
			{
				Board::Position startingPosition(i, j);
				for (auto endingPosition : board.GetPossibleMovesByPiece(startingPosition))
				{
					Board::Move move = Board::Move(startingPosition, endingPosition);
					moves.push_back(move);
				}

			}
		}
	}
	return moves;
}

int Ai::Maxi(int ply, Board board)
{
    if (ply == 0)
        return board.GetStaticEvaluation();

    int max = INT_MIN;
    for (const Board::Move& move : Ai::GetAllPossibleBlackMoves(board))
    {
        Board bd = board;
        bd.UpdateBoard(move);

        int evaluation = Ai::Mini(ply-1, bd);
        if (evaluation > max) max = evaluation;
    }
    return max;
}

int Ai::Mini(int ply, Board board)
{
    if (ply == 0)
        return board.GetStaticEvaluation();

    int min = INT_MAX;
    for (const Board::Move& move : Ai::GetAllPossibleWhiteMoves(board))
    {
        Board bd = board;
        bd.UpdateBoard(move);

        int evaluation = Ai::Maxi(ply-1, bd);
        if (evaluation < min) min = evaluation;
    }
    return min;
}

Board::Move Ai::FindBestMove(Board board)
{
    std::vector<Board::Move> moves = GetAllPossibleBlackMoves(board);
    
    int max = INT_MIN;
    int indexWithMax=0;

    for (int i=0; i < moves.size(); i++)
    {
        Board bd = board;
        bd.UpdateBoard(moves[i]);
        int eval = Maxi(2, bd);
        if (eval > max)
        {
            indexWithMax = i;
            max = eval;
        }
    }

    return moves[indexWithMax];
}

