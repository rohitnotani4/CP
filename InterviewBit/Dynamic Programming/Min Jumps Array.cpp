/*
https://www.interviewbit.com/problems/min-jumps-array/
*/

int Solution::jump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if (A.size() <= 1) 
        return 0;
    int curLevelMax = 0; // Marks the last element in a level
    int nextLevelMax = 0; // Marks the last element in the next level
    int level = 0, i = 0;
    while (i <= curLevelMax)
    {
        while(i <= curLevelMax) 
        {
            nextLevelMax = max(nextLevelMax, A[i] + i);
            if (nextLevelMax >= A.size() - 1) 
                return level + 1;
            i++;
        }
        level++;
        curLevelMax = nextLevelMax;
    }
    return -1;
}
