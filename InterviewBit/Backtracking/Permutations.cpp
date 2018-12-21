/*
https://www.interviewbit.com/problems/permutations/
*/

void permuteHelper(vector<vector<int> >& result, vector<int> input, vector<int> chosen, int index)
{
    if(input.size() == 0)
    {
        result.push_back(chosen);
    }
    else
    {
        int size = input.size();
        for(int i = 0; i<size; i++)
        {
            // Choose
            chosen.push_back(input[i]);
            int value =  input[i];
            vector<int>::iterator it;
            it = input.begin() + i;
            input.erase(it);
            
            permuteHelper(result, input, chosen, i);
            
            //Un-Chose
            input.insert(it, value);
            chosen.pop_back();
        }    
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
       
    vector<vector<int> > result;
    vector<int> chosen;
    if (A.size() == 0)
        return result;
    sort(A.begin(), A.end());
    permuteHelper(result, A, chosen, 0);
    return result;
}
