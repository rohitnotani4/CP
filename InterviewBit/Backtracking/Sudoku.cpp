/*
https://www.interviewbit.com/problems/sudoku/
*/

vector<vector<int> > convertDotsToZero(vector<vector<char> > &A)
{
    vector<vector<int> > board;
    for(int i=0;i<A.size();i++)
    {
        vector<int> row;
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j] == '.')
            {
                row.push_back(0);
            }
            else
            {
                row.push_back((int)A[i][j] - '0');
            }
        }
        board.push_back(row);
    }
    return board;
}

void convertBack(vector<vector<int> >& board, vector<vector<char> > &A)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            A[i][j] = (board[i][j] + '0');
        }
    }
}

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
void solveSudokuHelper(vector<vector<int> >&  board, vector<vector<char> > &A)
{
    int x = 0, y = 0;
    
    vector<int> possibleNumbers;
    
    if (isFull(board))
    {
        // cout<<"Board Solved Successfully!"<<"\n";
        // printBoard(board);
        convertBack(board, A);
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
            solveSudokuHelper(board, A);
        }
        
        // backtrack
        board[x][y] = 0;
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > board;
    
    board = convertDotsToZero(A);

    solveSudokuHelper(board, A);
}
