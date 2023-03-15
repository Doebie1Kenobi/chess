#include <iostream>
#include "board.h"


using namespace std;
/*
void drawLine(){
	cout << "-|-";
        for(int n = 0; n < 8; n++){
		cout<< "--|-";
	}
	cout << endl;
}

string getLetter(int position){
	switch (position){
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

void displayBoard(Space board[][8]){
	drawLine();
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			Piece piece;
			piece = board[i][j].getPiece();
			cout << " | " << piece.getPieceSymbol();//getPieceSymbol(piece);
		}
		cout << " | " << endl;
		drawLine();
	}
}


*/
int main() {
	// Initialize board
	/*
	Space board[8][8] = {};

	for (int i = 0; i < 8; i++){
		int num = 8;
		for (int j = 0; j < 8; j++){
			Space newSpace;
			newSpace.piece = {};
			string id = getLetter(i) + to_string(num);
			newSpace.id = id;
			newSpace.hasPiece = false;
			board[i][j] = newSpace;
			num--;
		}
	}

	displayBoard(board);
	*/

	Board b = {};
	b.initialize();
	b.displayBoard();

	Piece whitePieces[6] = {};
	Piece blackPieces[6] = {};

	/*
	// Create each white piece
	for(int i = 0; i < 6; i++) {
		Piece newPiece;
		newPiece.value = i + 1;
		newPiece.color = "White";
		newPiece.active = true;
		whitePieces[i] = newPiece;
	}

	for(int i = 0; i < 6; i++){
		Piece newPiece;
		newPiece.value = i + 1;
		newPiece.color = "Black";
		newPiece.active = true;
		blackPieces[i] = newPiece;
	}

	// Add black pieces 
	for(int i = 0; i < 8; i++){
		if((i == 0) || (i==7)){
			board[0][i].piece = blackPieces[1];
			board[0][i].hasPiece = true;
		}else if((i==1) || (i==6)){
			board[0][i].piece = blackPieces[2];
			board[0][i].hasPiece = true;
		}else if((i==2) || (i==5)){
			board[0][i].piece = blackPieces[3];
			board[0][i].hasPiece = true;
		}else if(i == 3){
			board[0][i].piece = blackPieces[4];
			board[0][i].hasPiece = true;
		}else{
			board[0][i].piece = blackPieces[5];
			board[0][i].hasPiece = true;
		}
	}

	// Add white pieces
	for(int i = 0; i < 8; i++){
                if((i == 0) || (i==7)){
                        board[7][i].piece = whitePieces[1];
			board[7][i].hasPiece = true;
                }else if((i==1) || (i==6)){
                        board[7][i].piece = whitePieces[2];
			board[7][i].hasPiece = true;
                }else if((i==2) || (i==5)){
                        board[7][i].piece = whitePieces[3];
			board[7][i].hasPiece = true;
                }else if(i == 3){
                        board[7][i].piece = whitePieces[4];
			board[7][i].hasPiece = true;
                }else{
                        board[7][i].piece = whitePieces[5];
			board[7][i].hasPiece = true;
                }
        }

	//Add Pawns
	for(int i = 0; i < 8; i++){
		board[1][i].piece = blackPieces[0];
		board[1][i].hasPiece = true;
	}

	for(int i = 0; i < 8; i++){
                board[6][i].piece = whitePieces[0];
		board[6][i].hasPiece = true;
        }

	displayBoard(board);
	*/
	return 0;
}
