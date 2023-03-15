#ifndef BOARD_H
#define BOARD_H

#include "space.h"


class Board {
        public:
                Space board[8][8] = {};

		void initialize(){
			for(int i = 0; i < 8; i++){
				int num = 8;
				for(int j = 0; j < 8; j++){
					Space newSpace;
					newSpace.piece = {};
					std::string id = getLetter(i) + std::to_string(num);
					newSpace.id = id;
					newSpace.hasPiece = false;
					board[i][j] = newSpace;
					num--;
				}
			}
		}

		void displayBoard(){
			drawLine();
        		for(int i = 0; i < 8; i++){
                		for(int j = 0; j < 8; j++){
                        		Piece piece;
                        		piece = board[i][j].getPiece();
					std::cout << " | " << piece.getPieceSymbol();
                		}
				std::cout << " | " << std::endl;
                		drawLine();
        		}

		}

		void drawLine(){
			std::cout << "-|-";
        		for(int n = 0; n < 8; n++){
				std::cout<< "--|-";
        		}
			std::cout << std::endl;
		}

		std::string getLetter(int pos){
			switch (pos){
                		case 0:
                        		return "a";
                		case 1:
                        		return "b";
                		case 2:
                        		return "c";
                		case 3:
                        		return "d";
                		case 4:
                        		return "e";
                		case 5:
                        		return "f";
                		case 6:
                        		return "g";
                		case 7:
                        		return "h";
                		default:
                        		return "";
        		}
		}
};

#endif
