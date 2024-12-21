#pragma once
#include <iostream>
#include <string>


struct Position
{
	int m_x;
	int m_y;

	Position(int x, int y) : m_x(x), m_y(y) { }

	friend std::ostream& operator<<(std::ostream& os, const Position& pos) {
		os << "(" << pos.m_x << ", " << pos.m_y << ")";
		return os;
	}
};

enum class EnumColor
{
	Black,
	White,
};

class Piece
{
public:
	virtual ~Piece() { }
	virtual void draw(Position pos) = 0;
};


class BlackPiece : public Piece
{
public:
	virtual void draw(Position pos)
	{
		std::cout << "A black piece is drawn at " << pos << " ." << std::endl;
	}
};


class WhitePiece : public Piece
{
public:
	virtual void draw(Position pos)
	{
		std::cout << "A white piece is drawn at " << pos << " ." << std::endl;
	}
};