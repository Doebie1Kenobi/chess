#ifndef SPACE_H
#define SPACE_H

#include "piece.h"

class Space {
	public:
		Piece piece;
		std::string color;
		std::string id;
		bool hasPiece;

		Piece getPiece(){
			return piece;
		}
};

#endif
