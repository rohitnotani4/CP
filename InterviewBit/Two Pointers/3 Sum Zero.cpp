/*
https://www.interviewbit.com/courses/1/topics/7/problems/3-sum-zero/previous_submissions/
*/

vector<vector<int> > Solution::threeSum(vector<int> &A) 
{

    vector<vector<int> > answer;

    if(A.size() < 3)
        return answer;

    sort(A.begin(), A.end());
    int size = A.size();
    for(int i=0;i<size-1;i++)
    {
        // Because sum of fixElement + others should be 0
        int fixElement = A[i];         
        int startIndex = i+1, endIndex = size-1;
        while(startIndex < endIndex)
        {
            if(fixElement + A[startIndex] + A[endIndex] == 0)
            {
                vector<int> temp{ fixElement, A[startIndex],A[endIndex] };
                answer.push_back(temp);
                startIndex++;
                endIndex--;

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (startIndex < endIndex && A[startIndex] == temp[1]) 
                    startIndex++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (startIndex < endIndex && A[endIndex] == temp[2]) 
                    endIndex--;

            }
            else
            if(fixElement + A[startIndex] + A[endIndex] > 0)
                endIndex--;
            else
                startIndex++;        
        }

        // Processing duplicates of Number 1
        while (i + 1 < A.size() && A[i + 1] == A[i]) 
            i++;
    }
    return answer;
}
