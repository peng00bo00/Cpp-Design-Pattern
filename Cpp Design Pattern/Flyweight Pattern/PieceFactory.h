#pragma once
#include <map>
#include "Piece.h"


class PieceFactory
{
public:
	~PieceFactory()
	{
		for (auto iter = m_FlyWeightMap.begin(); iter != m_FlyWeightMap.end(); ++iter)
		{
			Piece* tmpfw = iter->second;
			delete tmpfw;
		}

		m_FlyWeightMap.clear();
	}

	Piece* getFlyWeight(EnumColor tmpColor)
	{
		auto iter = m_FlyWeightMap.find(tmpColor);

		if (iter == m_FlyWeightMap.end())
		{
			Piece* tmpPiece = nullptr;

			if (tmpColor == EnumColor::Black)
			{
				tmpPiece = new BlackPiece();
			}
			else {
				tmpPiece = new WhitePiece();
			}
			m_FlyWeightMap.insert(std::make_pair(tmpColor, tmpPiece));

			return tmpPiece;
		}
		else
		{
			return iter->second;
		}
	}

private:
	std::map<EnumColor, Piece*> m_FlyWeightMap;
};

