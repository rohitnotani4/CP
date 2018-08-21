/*
https://www.interviewbit.com/problems/diffk-ii/
*/
int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<int, int> hashTable;
    int difference = B;
    for(int index=0;index<A.size();index++)
    {
        // To find A[i] - A[j] = B implies A[i] = A[j] + B || A[j] = A[i] - B
        int ai = A[index] + B;
        int aj = A[index] - B;
        
        if(hashTable.find(ai) != hashTable.end())
            return 1;
        
        if(hashTable.find(aj) != hashTable.end())
            return 1;
       
        hashTable[A[index]] = index;
    }
    return 0;
}
