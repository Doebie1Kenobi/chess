#ifndef PIECE_H
#define PIECE_H

#include "move.h"

class Piece {
	public:
		int value;
		std::string color;
		bool active;
		Move moveSet[10] = {};

		char getPieceSymbol(){
			switch (value) {
                		case 1:
                        		return 'P';
                		case 2:
                        		return 'R';
                		case 3:
                        		return 'N';
                		case 4:
                        		return 'B';
                		case 5:
                        		return 'Q';
                		case 6:
                        		return 'K';
                		default:
                        		return ' ';
			}

		}
};

/*
char Piece::getPieceSymbol(int value) {
	switch (value) {
		case 1:
                        return 'P';
                case 2:
                        return 'R';
                case 3:
                        return 'N';
                case 4:
                        return 'B';
                case 5:
                        return 'Q';
                case 6:
                        return 'K';
                default:
                        return ' ';
	}
}
*/

#endif
