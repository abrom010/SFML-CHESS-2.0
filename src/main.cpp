#include <iostream>
#include <SFML\Graphics.hpp>
#include <thread>

#include "board.h"
#include "ai.h"

Board::Position hoveringPiecePosition;
bool showingMoves = false;
bool aiMoving = false;
std::vector<Board::Position> possibleMoves;

sf::Texture BlackRook, BlackKnight, BlackBishop, BlackQueen, BlackKing, BlackPawn,
WhiteRook, WhiteKnight, WhiteBishop, WhiteQueen, WhiteKing, WhitePawn;

void LoadTextures()
{
    BlackRook.loadFromFile("images/blackrook.png");
    BlackKnight.loadFromFile("images/blackknight.png");
    BlackBishop.loadFromFile("images/blackbishop.png");
    BlackQueen.loadFromFile("images/blackqueen.png");
    BlackKing.loadFromFile("images/blackking.png");
    BlackPawn.loadFromFile("images/blackpawn.png");
    WhiteRook.loadFromFile("images/whiterook.png");
    WhiteKnight.loadFromFile("images/whiteknight.png");
    WhiteBishop.loadFromFile("images/whitebishop.png");
    WhiteQueen.loadFromFile("images/whitequeen.png");
    WhiteKing.loadFromFile("images/whiteking.png");
    WhitePawn.loadFromFile("images/whitepawn.png");
}

sf::Texture* GetTexture(Board::Piece piece)
{
    switch (piece)
    {
    case Board::Piece::BlackRook:
        return &BlackRook;
    case Board::Piece::BlackKnight:
        return &BlackKnight;
    case Board::Piece::BlackBishop:
        return &BlackBishop;
    case Board::Piece::BlackQueen:
        return &BlackQueen;
    case Board::Piece::BlackKing:
        return &BlackKing;
    case Board::Piece::BlackPawn:
        return &BlackPawn;

    case Board::Piece::WhiteRook:
        return &WhiteRook;
    case Board::Piece::WhiteKnight:
        return &WhiteKnight;
    case Board::Piece::WhiteBishop:
        return &WhiteBishop;
    case Board::Piece::WhiteQueen:
        return &WhiteQueen;
    case Board::Piece::WhiteKing:
        return &WhiteKing;
    case Board::Piece::WhitePawn:
        return &WhitePawn;
    }
}

std::vector<sf::Sprite> GetSpritesFromBoard(Board board)
{
    std::vector<sf::Sprite> sprites;
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Board::Position position(i, j);
            Board::Piece piece = board.GetPieceAtPosition(position);

            if (piece == Board::Piece::None) continue;

            sf::Sprite sprite(*GetTexture(piece));

            sf::Vector2u size = ((*GetTexture(piece)).getSize());
            float percent = .8f;
            float xScale = percent * 90.0f / size.x;
            float yScale = percent * 90.0f / size.y;
            sprite.setScale(xScale, yScale);

            sprite.setPosition((float)i*(720/8) + size.x / 2, (float)j*(720/8) + size.y / 2);
            sprites.push_back(sprite);
        }
    }

    return sprites;
}

void MoveAi(Board* board)
{
    Ai ai;
    Board::Move move = ai.FindBestMove(*board);
    (*board).UpdateBoard(move);
    aiMoving = false;
}

void ShowMoves(sf::RenderWindow& window, Board& board)
{
    if (!showingMoves)
    {
        std::cout << "clicked\n";
        sf::Vector2i clickPosition = sf::Mouse::getPosition(window);
        if (clickPosition.x > 720.0f || clickPosition.y > 720.0f) return;

        Board::Position position(clickPosition.x / 90, clickPosition.y / 90);

        Board::Piece piece = board.GetPieceAtPosition(position);
        if (board.IsPieceBlack(piece)) return;

        possibleMoves = board.GetPossibleMovesByPiece(position);
        if (possibleMoves.size() > 0)
        {
            hoveringPiecePosition = position;
            showingMoves = true;
        }

    }
    else
    {
        showingMoves = false;
        sf::Vector2i clickPosition = sf::Mouse::getPosition(window);
        if (clickPosition.x > 720.0f || clickPosition.y > 720.0f) return;

        Board::Position position(clickPosition.x / 90, clickPosition.y / 90);
        if (board.UpdateBoard(Board::Move(hoveringPiecePosition, position)))
        {
            aiMoving = true;
            std::thread thread(MoveAi, &board);
            thread.detach();
        }
        
    }
    
}


int main()
{
    LoadTextures();
    sf::RenderWindow window(sf::VideoMode(720, 720), "Chess2.0", sf::Style::Close | sf::Style::Titlebar);
    Board board = Board();

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture background;
    background.loadFromFile("images/board.png");
    sf::Sprite bg(background);
    bg.setScale(720.0f / background.getSize().x, 720.0f / background.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if(!aiMoving) ShowMoves(window, board);
                break;
            }
            
        }

        window.clear();
        window.draw(bg);

        for (sf::Sprite sprite : GetSpritesFromBoard(board))
        {
            window.draw(sprite);
        }

        if (showingMoves)
        {
            for (auto pos : possibleMoves)
            {
                sf::RectangleShape box({ 90.0f, 90.0f });
                box.setPosition(pos.x * 90.0f, pos.y * 90.0f);
                box.setFillColor(sf::Color(50, 50, 50, 210));
                window.draw(box);
            }
        }

        
        window.display();
    }
}