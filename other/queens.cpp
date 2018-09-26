#include <iostream>

using namespace std;
class nQueens{
	public:
		nQueens();
		~nQueens();
		void createBoard(int n);
		void getBoardDimentions();
	private:
		int n;

		//Get a pointer to a dynamically created 2D Array filled with NxN 0's - Represents the Board
		int **board;
		createBoard();
	
};

nQueens::nQueens(int n){

}

nQueens::nQueens(){

}

nQueens::~nQueens(){
	delete [] board;
	cout << "nQueens Instance Deleted." << endl;
}

void nQueens::getBoardDimentions(){
	cout << "Please enter the dimentions of the board you would like to solve: ";
	cin >> n;
}

void nQueens::createBoard(){
	n = getBoardDimentions();

	board = new int*[n];

	for (int i = 0; i < n; i++){
		board[i] = new int[n];
		for (int j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}

}

void nQueens::show(int** board){
	for (int i = 0; i < n; i++){for (int j = 0; j < n; j++){cout << board[i][j];}cout << endl;}
}


int main(){
	nQueens test;

	return 0;
}