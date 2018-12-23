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
 
bool getSolution(int row, vector<pair<int,int> >& placedQueens, vector<vector<string> >& ans, int A)
{
    if(row == A)
        return true;
 
    for(int j=0;j<A;j++)
    {
        bool place = false;
        pair<int,int> currenPos = make_pair(row,j);
        
        place = canPlace(currenPos,placedQueens);
        if(place)
        {
            // cout<<"Position "<<currenPos.first<<","<<currenPos.second<<"\n";
            placedQueens.push_back(currenPos);
            if(getSolution(row+1,placedQueens,ans,A))
            {
                // cout<<"We have a solution"<<"\n";
                ans.push_back(AddToAnswer(placedQueens,A));
            }
            placedQueens.pop_back();    
        }
    }
    
    return false;
}
 
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<string> > ans;
    vector<pair<int,int> >queenPosition;
    int row = 0;
    getSolution(0,queenPosition,ans,A);
    
    // cout<<"No of solutions = "<<ans.size()<<"\n";
    return ans;
}
