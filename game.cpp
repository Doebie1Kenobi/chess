#include <iostream>
#include "board.h"


using namespace std;

int main() {
	// Create new board and initialize it
	Board b = {};
	b.initialize();
	
	// Create and add each white piece
	Piece whitePieces[6] = {};
	for(int i = 0; i < 6; i++) {
		Piece newPiece;
		newPiece.value = i + 1;
		newPiece.color = "White";
		newPiece.active = true;
		whitePieces[i] = newPiece;
	}
	b.addPawns(whitePieces[0]);
	b.addPiecesToBoard(whitePieces);	

	// Create each black piece
	Piece blackPieces[6] = {};
	for(int i = 0; i < 6; i++){
		Piece newPiece;
		newPiece.value = i + 1;
		newPiece.color = "Black";
		newPiece.active = true;
		blackPieces[i] = newPiece;
	}
	b.addPawns(blackPieces[0]);
	b.addPiecesToBoard(blackPieces);

	string piece = "";
	string space = "";
	while(true){
		b.displayBoard();
		cout << "Enter the piece you want to move: "; 
		cin >> piece;
		cout << "Enter the space you want to move it to: "; 
		cin >> space;
		b.move(piece, space);	
	}

	return 0;
}