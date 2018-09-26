/*                                                                              
Name: Julian Bartholomee                                                        
Email: jbp402@psu.edu                                                           
Due Date: September 17 2018                                                     
Class: CMPSC 122 - Intermediate Programming Fall 2018                           
Professor Sukmoon - T, Th: 1:35                                                 
                                                                                
Description:                                                                    
This program first reads in a file describing the setup of a chess board        
to evaluate. Next, the chess board is evaluated. If a valid solution,           
 it is detected. If not, the exact queens that are attacking each other will    
be printed out.                                                                 
                                                                                
Acknowledgement:                                                                
I used the c++ reference to familiarize myself with ostringstream: http://www.c\
plusplus.com/reference/sstream/ostringstream/                                   
                                                                                
                                                                                
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//Read in chess board from file
bool** ReadChessboard(char* filepath, int& num_rows, int& num_cols, int& num_queens)
{
    fstream infile;
    infile.open(filepath);

    infile >> num_rows;
    infile >> num_cols;

    /////////////////////////////////////////////////////////////////
    // Modify and enter your code here, to create board with adding
    // queens into the board.

    /*  Dynamically create 2 dimentional array "board". 
	Declaring a pointer to an array of pointers to bool types.
	False = Empty Space, True = Queen. Default full of false.        */
    bool** board = new bool*[num_rows];
    for(int i = 0; i < num_rows; i++){
	board[i] = new bool[num_cols];
	for(int j = 0; j < num_cols; j++){
	    board[i][j] = false;
	}
    }

    //Read in the number of queens we will try to place, declare coordinate variables x and y for later.
    
    infile >> num_queens;
    int x,y;

    //Iterate through the given queen locations. Set each location of a queen to true. 
    for(int i = 0; i < num_queens; i++){
	infile >> x >> y;
    	board[x][y] = true;
    }

    //Close the input file.
    infile.close();

    return board;
}


//Display the chess board
void PrintChessboard(bool** board, int& num_rows, int& num_cols)
{
    cout << "Print chess board:" << endl << endl;
    /////////////////////////////////////////////////////////////////
    // Enter your code here, to print chess board with queens.
    // Print
    //   * " Q" to print a queen, and
    //   * " ." to print an empty cell.


    //Print indicies
    cout << "  ";
    for (int i = 0; i < num_cols; i++){
	cout << " ";
	cout << i;
    }
    cout << endl;

    //Print the actual board
    for (int i = 0; i < num_rows; i++){
	cout << " ";
	cout << i;
	for (int j = 0; j < num_cols; j++){
	    if (board[i][j]){
		cout << " Q";
	    } else {
		cout << " .";
	    }
    	}
	cout << endl;
    }
    cout << endl;
	
}

//Recursive ray casting method. 
void rayCast(bool** board, int directions[2], int row, int col, int& x, int& y, int& num_rows, int& num_cols, bool& there_are_attacks, ostringstream& attacked_queens){
    row += directions[0];
    col += directions[1];

    //Base case: Be within the board dimentions.
    if (   ( (row >= 0) && (row < num_rows) ) && ( (col >= 0) && (col < num_cols) )  ){
	
	//If we find a queen
	if (board[row][col]){
	    there_are_attacks = true;

	    // add message to ostringstream object
	    attacked_queens << "Queen (" << x << "," << y << ") attacks queen (" << row << "," << col << ").\n";
	
	    //Without this return statement, the raycast will also seach for XRay attacks.
	    return;
	}

	

	rayCast(board, directions, row, col, x, y, num_rows, num_cols, there_are_attacks, attacked_queens);
    }
}







// Helper function for rayCast(). Sets off the search for more queens in every direction.
void getVictims(bool** board, int& row, int& col, int& num_rows, int& num_cols, bool& there_are_attacks, ostringstream& attacked_queens){
    //All queen direction unit vectors.
    int queen_directions[8][2] =
    {
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1},
        {-1,-1},
        {-1,0},
        {-1,1}

    };

    //Set off the search for more queens in every direction.
    for(int i = 0; i < 8; i++){
	rayCast(board, queen_directions[i], row, col, row, col, num_rows, num_cols, there_are_attacks, attacked_queens);
    }
}

//
void evaluateSolution(bool** board, int& num_rows, int& num_cols, int& num_queens, bool& is_nqueens, bool& there_are_attacks, ostringstream& attacked_queens){
    //Get the victims of each queen on the board currently.
    for(int i = 0; i < num_rows; i++){
	for(int j = 0; j < num_cols; j++){
	    if(board[i][j]){
		getVictims(board,i,j,num_rows,num_cols,there_are_attacks, attacked_queens);
	    }
	}
    }


    //Determine if nqueens is satisfied
    if (((num_rows == num_cols) && (num_cols == num_queens)) && (!there_are_attacks)){
	is_nqueens = true;
    }

}

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        cout << "Need the input file containing chess board size and queen locations." << endl;
        return 0;
    }

    int num_rows;
    int num_cols;
    int num_queens;
    bool** board = ReadChessboard(argv[1], num_rows, num_cols, num_queens);

    ostringstream attacked_queens;
    
    PrintChessboard(board, num_rows, num_cols);
    

    bool is_nqueens        = false;
    bool there_are_attacks = false;


    /////////////////////////////////////////////////////////////////
    // Enter your code here.
    // If you want create your own functions

    evaluateSolution(board, num_rows, num_cols, num_queens,is_nqueens, there_are_attacks, attacked_queens);


    /////////////////////////////////////////////////////////////////


    if(is_nqueens)
        cout << "Solution to the N Queen Problem? Yes" << endl << endl;
    else
        cout << "Solution to the N Queen Problem? No" << endl << endl;

    if(there_are_attacks)
    {
        cout << "There is at least one queen attacking other queen(s)." << endl;

        /////////////////////////////////////////////////////////////////
        // Enter your code to print list of queens attacking other queens

	cout << attacked_queens.str();

        /////////////////////////////////////////////////////////////////
    }
    else
    {
        cout << "There is no queen attacking other queen(s)." << endl;
    }

    /////////////////////////////////////////////////////////////////
    // Enter your code to delete dynamically allocated memories
    for(int i = 0; i < num_rows; i++){
	delete [] board[i];
    }
    delete [] board;

    return 0;

    /////////////////////////////////////////////////////////////////
}
