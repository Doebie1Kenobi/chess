#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "move.h"

class Piece {
	public:
		int value;
		std::string color;
		bool active;
		std::vector<Move> moveset;

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

		void setMoveset(){
			switch (value){
				case 1:
					if(color == "White"){
						setWhitePawnMoveset();
					}else{
						setBlackPawnMoveset();
					}
					break;

				default:
					break;
				
			}
		}

		void setWhitePawnMoveset(){
			// Move 1
			Move move_one;
			move_one.setMove(1,0/*,0,0,0,0*/);
			moveset.push_back(move_one);
			// Move 2
			Move move_two;
			move_two.setMove(2,0);
			moveset.push_back(move_two);
			// Move 3
			Move attack_one;
			attack_one.setMove(1,1);
			moveset.push_back(attack_one);
			// Move 4
			Move attack_two;
			attack_two.setMove(1,-1);
			moveset.push_back(attack_two);

		}
		void setBlackPawnMoveset(){
			// Move 1
			Move move_one;
			move_one.setMove(-1,0);
			moveset.push_back(move_one);
			// Move 2
			Move move_two;
			move_two.setMove(-2,0);
			moveset.push_back(move_two);
			// Move 3
			Move attack_one;
			attack_one.setMove(-1,1);
			moveset.push_back(attack_one);
			// Move 4
			Move attack_two;
			attack_two.setMove(-1,-1);
			moveset.push_back(attack_two);
		}
};

#endif