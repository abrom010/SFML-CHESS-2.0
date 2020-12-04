#include <set>
#include "ai.h"

std::vector<Board::Move> Ai::GetAllPossibleMoves(Board board)
{
    std::set<Board::Move> moves;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Board::Piece piece = board.boardArray[j][i];
            if (piece != Board::Piece::None &&
                    (
                        piece == Board::Piece::BlackRook ||  
                        piece == Board::Piece::BlackKnight ||
                        piece == Board::Piece::BlackBishop ||
                        piece == Board::Piece::BlackQueen ||
                        piece == Board::Piece::BlackKing ||
                        piece == Board::Piece::BlackPawn
                    )
                )
            {
                Board::Position startingPosition(j, i);
                for (auto endingPosition : board.GetPossibleMovesByPiece(startingPosition))
                {
                    Board::Move move = Board::Move(startingPosition, endingPosition);
                    moves.insert(move);
                }
                
            }
        }
    }
}

int Maxi(int ply, Board board)
{
    if (ply == 0)
        return board.GetStaticEvaluation();

    int max = INT_MIN;
    for (const Board::Move& move : Ai::GetAllPossibleMoves(board))
    {
        Board bd = board;
        bd.UpdateBoard(move);

        int evaluation = Mini(5, bd);
        if (evaluation > max) evaluation = max;
    }
    return max;
}

int Mini(int ply, Board board)
{
    if (ply == 0)
        return board.GetStaticEvaluation();

    int min = INT_MAX;
    for (const Board::Move& move : Ai::GetAllPossibleMoves(board))
    {
        Board bd = board;
        bd.UpdateBoard(move);

        int evaluation = Maxi(5, bd);
        if (evaluation < min) evaluation = min;
    }
    return min;
}

Board::Move Ai::FindBestMove(Board board)
{
    std::vector<Board::Move> moves = GetAllPossibleMoves(board);
    
    int max = INT_MIN;
    int indexWithMax=0;

    for (int i=0; i < moves.size(); i++)
    {
        Board bd = board;
        bd.UpdateBoard(moves[i]);
        if (Maxi(5, bd) > max) indexWithMax = i;
    }

    return moves[indexWithMax];
}

