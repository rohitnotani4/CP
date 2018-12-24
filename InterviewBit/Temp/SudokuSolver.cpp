#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// function to print the board on to the console
void printBoard(vector<vector<int> >& board)
{
	cout<<"*********************"<<"\n";
	for(int i=0;i<9;i++)
	{
		if(i==3 || i ==6)
			cout<<"*********************"<<"\n";
		for(int j=0;j<9;j++)
		{
			if(j==3 || j==6)
				cout<<"* ";
			
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"*********************"<<"\n";
}

// function to check if the board is full or not
// returns true if it is full and false if it isn't
// it works on the fact that if it finds at least one 
// zero in the board it returns false

bool isFull(vector<vector<int> >& board)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(board[i][j] == 0)
				return false;
		}
	}
	return true;
}


// function to find all of the possible numbers
// which can be put at the specifies location by
// checking the horizontal and vertical and the 
// three by three square in which the numbers are
// housed
vector<int> possibleEntries(vector<vector<int> >& board,int x, int y)
{
	vector<int> temp, possibleNumbers;
	for(int i=0;i<10;i++)
		temp.push_back(1);
	
	// For horizontal entries
	for(int j=0;j<9;j++)
	{
		if(board[x][j] != 0)
		{
			temp[board[x][j]] = 0;
		}
	}
	
	// For vertical entries
	for(int i=0;i<9;i++)
	{
		if(board[i][y] != 0)
		{
			temp[board[i][y]] = 0;
		}
	}
	
	// For squares of three x three
    int k = 0;
    int l = 0;
    if (x >= 0 && x <= 2)
		k = 0;
	else
	if(x >=3 && x <=5)
		k = 3;
	else
		k = 6;
    
	if (y >= 0 && y <= 2)
		l = 0;
	else
	if(y >= 3 && y <= 5)
		l = 3;
	else
		l = 6;
	
	for(int p = k;p<k+3;p++)
	{
		for(int q = l;q <l+3; q++)
		{
			if(board[p][q] != 0)
			{
				temp[board[p][q]] = 0;
			}
		}
	}

	for(int r = 1; r < 10; r++)
	{
		if(temp[r] == 1)
			possibleNumbers.push_back(r);
	}	
	return possibleNumbers;
}

// recursive function which solved the board and 
// prints it.
void sudokuSolver(vector<vector<int> >&  board)
{
	int x = 0, y = 0;
	
	vector<int> possibleNumbers;
	
	if (isFull(board))
	{
		cout<<"Board Solved Successfully!"<<"\n";
		printBoard(board);
		return ;
	}
	else
	{
	    // find the first vacant spot
    	bool vacantSpotFound = false;
    	for(int i = 0;i < 9; i++)
    	{
    		for(int j = 0; j < 9; j++)
    		{
    			if(board[i][j] == 0)
    			{
    				x = i;
    				y = j;
    				vacantSpotFound = true;
    				break;
    			}
    		}
    		if(vacantSpotFound)
    		    break;
    	}
    	
    	// get all the possibilities for x,y
    	possibleNumbers = possibleEntries(board, x, y);
    	
    	// go through all the possibilities and call the the function
        // again and again
    	for(int l = 0; l < possibleNumbers.size(); l++)
    	{
    		board[x][y] = possibleNumbers[l];
    		sudokuSolver(board);
    	}
    	
    	// backtrack
    	board[x][y] = 0;
	}
}

 
int main()
{
	vector<vector<int>> board (9, vector<int> (9, 0));
    board[0][0] = 0;
    board[0][1] = 0;
    board[0][2] = 0;
    board[0][3] = 3;
    board[0][4] = 0;
    board[0][5] = 0;
    board[0][6] = 2;
    board[0][7] = 0;
    board[0][8] = 0;
    board[1][0] = 0;
    board[1][1] = 0;
    board[1][2] = 0;
    board[1][3] = 0;
    board[1][4] = 0;
    board[1][5] = 8;
    board[1][6] = 0;
    board[1][7] = 0;
    board[1][8] = 0;
    board[2][0] = 0;
    board[2][1] = 7;
    board[2][2] = 8;
    board[2][3] = 0;
    board[2][4] = 6;
    board[2][5] = 0;
    board[2][6] = 3;
    board[2][7] = 4;
    board[2][8] = 0;
    board[3][0] = 0;
    board[3][1] = 4;
    board[3][2] = 2;
    board[3][3] = 5;
    board[3][4] = 1;
    board[3][5] = 0;
    board[3][6] = 0;
    board[3][7] = 0;
    board[3][8] = 0;
    board[4][0] = 1;
    board[4][1] = 0;
    board[4][2] = 6;
    board[4][3] = 0;
    board[4][4] = 0;
    board[4][5] = 0;
    board[4][6] = 4;
    board[4][7] = 0;
    board[4][8] = 9;
    board[5][0] = 0;
    board[5][1] = 0;
    board[5][2] = 0;
    board[5][3] = 0;
    board[5][4] = 8;
    board[5][5] = 6;
    board[5][6] = 1;
    board[5][7] = 5;
    board[5][8] = 0;
    board[6][0] = 0;
    board[6][1] = 3;
    board[6][2] = 5;
    board[6][3] = 0;
    board[6][4] = 9;
    board[6][5] = 0;
    board[6][6] = 7;
    board[6][7] = 6;
    board[6][8] = 0;
    board[7][0] = 0;
    board[7][1] = 0;
    board[7][2] = 0;
    board[7][3] = 7;
    board[7][4] = 0;
    board[7][5] = 0;
    board[7][6] = 0;
    board[7][7] = 0;
    board[7][8] = 0;
    board[8][0] = 0;
    board[8][1] = 0;
    board[8][2] = 9;
    board[8][3] = 0;
    board[8][4] = 0;
    board[8][5] = 5;
    board[8][6] = 0;
    board[8][7] = 0;
    board[8][8] = 0;

    printBoard(board);
    sudokuSolver(board);
	return 0;
}
