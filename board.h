#ifndef BOARD_H
#define BOARD_H

#include "space.h"


class Board {
        public:
                Space board[8][8] = {};
		Piece whiteArr[6] = {};

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

		void addPiecesToBoard(Piece arr[6]){
			int num = 0;
			if(arr[0].color == "White"){
				num = 7;
			}

			for(int i = 0; i < 8; i++){
				if((i == 0) || (i==7)){
                        		board[num][i].piece = arr[1];
                        		board[num][i].hasPiece = true;
                		}else if((i==1) || (i==6)){
                        		board[num][i].piece = arr[2];
                        		board[num][i].hasPiece = true;
                		}else if((i==2) || (i==5)){
                        		board[num][i].piece = arr[3];
                        		board[num][i].hasPiece = true;
                		}else if(i == 3){
                        		board[num][i].piece = arr[4];
                        		board[num][i].hasPiece = true;
                		}else{
                        		board[num][i].piece = arr[5];
                        		board[num][i].hasPiece = true;
                		}

			}
		}

		void addPawns(Piece pawn){
			int num = 1;
			if(pawn.color == "White"){
				num = 6;
			}
			for(int i = 0; i < 8; i++){
				board[num][i].piece = pawn;
				board[num][i].hasPiece = true;
			}
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
