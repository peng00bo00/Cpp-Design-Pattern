#include "Piece.h"
#include "PieceFactory.h"


static constexpr EnumColor Black = EnumColor::Black;
static constexpr EnumColor White = EnumColor::White;


int main() {
	PieceFactory* pfactory = new PieceFactory();

	Piece* p_piece1 = pfactory->getFlyWeight(Black);
	p_piece1->draw({3, 3});

	Piece* p_piece2 = pfactory->getFlyWeight(White);
	p_piece2->draw({ 5, 5 });

	Piece* p_piece3 = pfactory->getFlyWeight(Black);
	p_piece3->draw({ 4, 6 });

	Piece* p_piece4 = pfactory->getFlyWeight(White);
	p_piece4->draw({ 5, 7 });

	delete pfactory;

	return 0;
}