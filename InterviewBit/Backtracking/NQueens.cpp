/*
https://www.interviewbit.com/problems/nqueens/
*/

vector<string> AddToAnswer(vector<pair<int,int> >& placedQueens,int A)
{
    vector<string> oneSolution;
    for(int i=0;i<placedQueens.size();i++)
    {
        string temp (A, '.');
        temp[placedQueens[i].second] = 'Q';
        oneSolution.push_back(temp);
    }
    return oneSolution;
}

bool canPlace(pair<int,int> currentPos, vector<pair<int,int> >& placedQueens)
{
    for(int i=0;i<placedQueens.size();i++)
    {
        if(currentPos.second == placedQueens[i].second
            || ( (currentPos.first + currentPos.second) == 
               (placedQueens[i].first + placedQueens[i].second))
            || ( (currentPos.first - currentPos.second) == 
               (placedQueens[i].first - placedQueens[i].second))
            )
                return false;
    }
    return true;
}

void getSolution(vector<vector<string> >& result, vector<pair<int,int> >& placedQueens, int currRow, int N)
{
    if(currRow == N)
    {
        result.push_back(AddToAnswer(placedQueens, N));
        return ;
    }

    for(int j=0;j<N;j++)
    {
        pair<int,int> currenPos = make_pair(currRow, j);
        if(canPlace(currenPos, placedQueens))
        {
            placedQueens.push_back(currenPos);
            
            getSolution(result, placedQueens, currRow+1, N);
            
            placedQueens.pop_back();    
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<string> > result;
    vector<pair<int,int> > queenPosition;
    getSolution(result, queenPosition, 0, A);
    return result;
}
