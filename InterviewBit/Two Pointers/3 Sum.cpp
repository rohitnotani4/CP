/*
https://www.interviewbit.com/problems/3-sum/
*/

int Solution::threeSumClosest(vector<int> &A, int B) {

    vector<vector<int> > answer;

    if(A.size() < 3)
        return 0;

    sort(A.begin(), A.end());
    
    int size = A.size();
    int result = A[0] + A[1] + A[A.size()-1];
    for(int i=0;i<size-2;i++)
    {
        // Because sum of fixElement + others should be 0
        int fixElement = A[i];         
        int startIndex = i+1, endIndex = size-1;
        while(startIndex < endIndex)
        {
            int sum = fixElement + A[startIndex] + A[endIndex];
            if(sum > B)
                endIndex--;
            else
                startIndex++;        

            if (abs(sum - B) < abs(result - B)) 
            {
                result = sum;
            }
        }

    }
     return result;
}
