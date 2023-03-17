#include <iostream>
#include "board.h"


using namespace std;

int main() {
	// Initialize board
	Board b = {};
	b.initialize();
	b.displayBoard();

	Piece whitePieces[6] = {};
	Piece blackPieces[6] = {};

	
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

	b.addPiecesToBoard(blackPieces);
	b.addPiecesToBoard(whitePieces);
	b.addPawns(blackPieces[0]);
	b.addPawns(whitePieces[0]);

	b.displayBoard();

	string piece = "";
	string space = "";
	while(true){
		cout << "Enter the piece you want to move: "; 
		cin >> piece;
		cout << "Enter the space you want to move it to: "; 
		cin >> space;
		b.move(piece, space);
		b.displayBoard();	
	}

	return 0;
}
