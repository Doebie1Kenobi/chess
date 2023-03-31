#ifndef MOVE_H
#define MOVE_H

class Move {
	public:
		int vertical = 0;
		int horizontal = 0;
		int rDiagonalUp = 0;
		int lDiagonalUp = 0;
		int rDiagonalDown = 0;
		int lDiagonalDown = 0;	

		void setMove(int v, int h, int rdu, int ldu, int rdd, int ldd){
			vertical = v;
			horizontal = h;
			rDiagonalUp = rdu;
			lDiagonalUp = ldu;
			rDiagonalDown = rdd;
			lDiagonalDown = ldd;
		}
	
	
	
};

#endif
