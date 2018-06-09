/*
https://www.interviewbit.com/problems/spiral-order-matrix-ii/
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector < vector<int> > mat;
    
    int left=0,right=A-1,top=0,bottom=A-1;    
    int dir = 0,count=0;
    
    
    int value=0;
    for(int i=0;i<A;i++)
    {
        vector <int> temp;
        for(int j=0;j<A;j++)
        {
            temp.push_back(value);
        }
        mat.push_back(temp);
    }
    
    while( left <= right && top <= bottom)
    {
        if(dir==0)
        {
            for(int i=left;i<=right;i++)
            {
                count++;
                mat[top][i] = count;
                //printf("%d ",mat[top][i]);
            }
            top++;    
        }
        else 
        if(dir == 1)
        {
            for(int i=top;i<=bottom;i++)
            {
                count++;
                //printf("%d ",mat[i][right]);
                mat[i][right]=count;
            }    
            right--;    
        }
        else 
        if(dir == 2)
        {
            for(int i=right;i>=left;i--)
            {
                count++;
                //printf("%d ",mat[bottom][i]);
                mat[bottom][i]=count;
            }
            bottom--;    
        }
        else
        {
            for(int i=bottom;i>=top;i--)
            {
                count++;
                //printf("%d ",mat[i][left]);
                mat[i][left] = count;
            }
                
            left++;    
        }
        
        dir = (dir+1)%4;
    }
    return mat;
    
}
