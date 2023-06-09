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
					std::cout << " " << getLetter(i);
                	for(int j = 0; j < 8; j++){
                        Piece piece;
                        piece = board[i][j].getPiece();
						std::cout << " | " << piece.getPieceSymbol();
                	}
					std::cout << " | " << std::endl;
                	drawLine();
        		}
			drawLineWithNumbers();
		}

		void drawLineWithNumbers(){
			std::cout << "   ";
			for(int n = 0; n < 8; n++){
				std::cout << "| " << getRowNumber(n) << " ";
			}
			std::cout << "| " << std::endl;
		}

		void drawLine(){
			//std::cout << "---|-";
			std::cout << "  -|-";
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
					setRookMoveset(arr[1]);
                    board[num][i].piece = arr[1];
                    board[num][i].hasPiece = true;
                }else if((i==1) || (i==6)){
					setKnightMoveset(arr[2]);
                    board[num][i].piece = arr[2];
                    board[num][i].hasPiece = true;
                }else if((i==2) || (i==5)){
					setBishopMoveset(arr[3]);
                    board[num][i].piece = arr[3];
                    board[num][i].hasPiece = true;
                }else if(i == 3){
					setQueenMoveset(arr[4]);
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
				for(int i = 0; i < 8; i++){
					//setWhitePawnMoveset(pawn);
					board[num][i].piece = pawn;
					board[num][i].hasPiece = true;
				}
			}
			for(int i = 0; i < 8; i++){
				//setBlackPawnMoveset(pawn);
				board[num][i].piece = pawn;
				board[num][i].hasPiece = true;
			}
		}

		void setBlackPawnMoveset(Piece piece){
			// Move 1
			Move move_one;
			move_one.setMove(-1,0);
			piece.moveset.push_back(move_one);
			// Move 2
			Move move_two;
			move_two.setMove(-2,0);
			piece.moveset.push_back(move_two);
			// Move 3
			Move attack_one;
			attack_one.setMove(-1,1);
			piece.moveset.push_back(attack_one);
			// Move 4
			Move attack_two;
			attack_two.setMove(-1,-1);
			piece.moveset.push_back(attack_two);
		}

		void setWhitePawnMoveset(Piece piece){
			// Move 1
			Move move_one;
			move_one.setMove(1,0/*,0,0,0,0*/);
			piece.moveset.push_back(move_one);
			// Move 2
			Move move_two;
			move_two.setMove(2,0);
			piece.moveset.push_back(move_two);
			// Move 3
			Move attack_one;
			attack_one.setMove(1,1);
			piece.moveset.push_back(attack_one);
			// Move 4
			Move attack_two;
			attack_two.setMove(1,-1);
			piece.moveset.push_back(attack_two);

		}

		void setRookMoveset(Piece piece){
			Move move;

			// VERTICAL
			// Move 1
			move.setMove(1,0);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(2,0);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(3,0);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(4,0);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(5,0);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(6,0);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(7,0);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(-1,0);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(-2,0);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(-3,0);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(-4,0);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(-5,0);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(-6,0);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(-7,0);
			piece.moveset.push_back(move);

			// HORIZONTAL
			// Move 1
			move.setMove(0,1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(0,2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(0,3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(0,4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(0,5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(0,6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(0,7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(0,-1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(0,-2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(0,-3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(0,-4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(0,-5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(0,-6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(0,-7);
			piece.moveset.push_back(move);
		}

		void setKnightMoveset(Piece piece){
			Move move;

			// Move 1
			move.setMove(1,2);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(2,1);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(-1,2);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(-2,1);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(1,-2);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(2,-1);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(-1,-2);
			piece.moveset.push_back(move);
			// Move 8
			move.setMove(-2,-1);
			piece.moveset.push_back(move);
		}

		void setBishopMoveset(Piece piece){
			Move move;

			// Move 1
			move.setMove(1,1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(2,2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(3,3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(4,4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(5,5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(6,6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(7,7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(1,-1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(2,-2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(3,-3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(4,-4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(5,-5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(6,-6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(7,-7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(-1,1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(-2,2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(-3,3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(-4,4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(-5,5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(-6,6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(-7,7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(-1,-1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(-2,-2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(-3,-3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(-4,-4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(-5,-5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(-6,-6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(-7,-7);
			piece.moveset.push_back(move);
		}

		void setQueenMoveset(Piece piece){
			Move move;

			// HORIZONTAL
			// Move 1
			move.setMove(0,1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(0,2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(0,3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(0,4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(0,5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(0,6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(0,7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(0,-1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(0,-2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(0,-3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(0,-4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(0,-5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(0,-6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(0,-7);
			piece.moveset.push_back(move);

			// VERTICAL
			// Move 1
			move.setMove(1,0);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(2,0);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(3,0);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(4,0);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(5,0);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(6,0);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(7,0);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(-1,0);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(-2,0);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(-3,0);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(-4,0);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(-5,0);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(-6,0);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(-7,0);
			piece.moveset.push_back(move);

			// DIAGONAL
			// Move 1
			move.setMove(1,1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(2,2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(3,3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(4,4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(5,5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(6,6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(7,7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(1,-1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(2,-2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(3,-3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(4,-4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(5,-5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(6,-6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(7,-7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(-1,1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(-2,2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(-3,3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(-4,4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(-5,5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(-6,6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(-7,7);
			piece.moveset.push_back(move);

			// Move 1
			move.setMove(-1,-1);
			piece.moveset.push_back(move);
			// Move 2
			move.setMove(-2,-2);
			piece.moveset.push_back(move);
			// Move 3
			move.setMove(-3,-3);
			piece.moveset.push_back(move);
			// Move 4
			move.setMove(-4,-4);
			piece.moveset.push_back(move);
			// Move 5
			move.setMove(-5,-5);
			piece.moveset.push_back(move);
			// Move 6
			move.setMove(-6,-6);
			piece.moveset.push_back(move);
			// Move 7
			move.setMove(-7,-7);
			piece.moveset.push_back(move);
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

		int getRowNumber(int pos){
			switch (pos){
                case 0:
                    return 8;
                case 1:
                    return 7;
                case 2:
                    return 6;
                case 3:
                    return 5;
                case 4:
                    return 4;
                case 5:
                    return 3;
                case 6:
                    return 2;
                case 7:
                    return 1;
                default:
                    return 0;
        	}
		}

		int getRow(std::string space){
			for(int i = 0; i < 8; i++){
				for(int j = 0; j < 8; j++){
					if(space == board[i][j].id){
						return i;
					}
				}
			}
			return -1;
		}

		int getColumn(std::string space){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(space == board[i][j].id){
                        return j;
                    }
                }
            }
			return -1;
        }

		bool isValid(std::string space){
			for(int i = 0; i < 8; i++){
				for(int j = 0; j < 8; j++){
					if(space == board[i][j].id){
					       return true;
					}	       
				}
			}

			return false;
		}

		bool isZero(int num_one, int num_two){
			int sum = num_one + num_two;
			int diff = num_one - num_two;
			if((sum == 0) || (diff == 0)){
				return true;
			}else{
				return false;
			}
		}

		void move(std::string space_one, std::string space_two){
			if(isValid(space_one) && isValid(space_two)){
				int curr_row = getRow(space_one);
				int curr_col = getColumn(space_one);
				int target_row = getRow(space_two);
				int target_col = getColumn(space_two);

				int row_diff = curr_row - target_row;
				int col_diff = curr_col - target_col;

				Move move;
				move.setMove(row_diff, col_diff);

				Piece piece;
				piece = board[curr_row][curr_col].piece;

				std::cout << piece.moveset.size() << std::endl;

				for(std::size_t i = 0; i < piece.moveset.size(); i++){
					if(move.isEqual(piece.moveset[i])){
						std::cout << "MOVING PIECE..." << std::endl;
						Space nextSpace;
						nextSpace.piece = board[curr_row][curr_col].piece;
						nextSpace.id = board[target_row][target_col].id;
						nextSpace.hasPiece = true;
						board[target_row][target_col] = nextSpace;

						Space currSpace;
						currSpace.piece = {};
						currSpace.id = board[curr_row][curr_col].id;
						currSpace.hasPiece = false;
						board[curr_row][curr_col] = currSpace;
					}
				}
			}else{
				std::cout << "Enter valid spaces!" << std::endl;
			}
		}
};

#endif