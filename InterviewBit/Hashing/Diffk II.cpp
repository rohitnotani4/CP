/*
https://www.interviewbit.com/problems/diffk-ii/
*/

nt Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<int, int> hashTable;
    
    int difference = B;
    for(int i=0;i<A.size();i++)
    {
        if(hashTable.find(difference + A[i]) != hashTable.end() ||
          (hashTable.find(A[i] - difference) != hashTable.end()))
        {
            return 1;
        }
        else
        {
            hashTable[A[i]] = i;
        }
    
    }
    return 0;
}
