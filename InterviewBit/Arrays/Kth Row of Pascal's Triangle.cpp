/*
https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
*/

void copy_contents (vector<int> & temp, vector<int> & ans)
{
    for(int i=0;i<temp.size();i++)
        ans.push_back(temp[i]);
    temp.clear();
}
 
vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    
    vector<int> ans,temp;
    if(A==0)
        ans.push_back(1);
    else
    if(A==1)
    {
        ans.push_back(1);
        ans.push_back(1);
    }
    else
    {
        ans.push_back(1);
        ans.push_back(1);
        
        for(int i=2;i<=A;i++)
        {
            temp.push_back(1);
            for(int j=0;j<ans.size()-1;j++)
            {
                temp.push_back(ans[j]+ans[j+1]);
            }
            temp.push_back(1);
            
            ans.clear();
            
            copy_contents(temp,ans);
        }
    }
                
	return ans;	
 
    
}
