/*
https://www.interviewbit.com/problems/add-one-to-number/
*/



    vector<int> addition (vector<int>& A, int length_A, vector<int>& B,int length_B)
    {
    	vector<int> source;
    	vector<int> ans;
    	int i,j,k,l,temp,sum,ra_length,carry;
    	
    	i = length_A - 1;
    	j = length_B - 1;
    	
    	carry=0;
    	do 
    	{
    		if (j >= 0)
    		{
    			sum =(A[i] + B[j]+carry);
    			
    			if (sum >= 10)
    			{
    				temp = sum%10;
    				source.push_back(temp);
    				carry=sum/10;
    			}
    			else 
    			{
    				temp = sum;
    				source.push_back(temp);
    				carry=0;
    			}
    			i--;
    			j--;
    		} 
    		else 
    		{
    		    sum = A[i] + carry;
    		    if (sum >= 10)
    			{
    				temp = sum%10;
    				source.push_back(temp);
    				carry=sum/10;
    			}
    			else
    			{
    			    temp = sum;
    			    source.push_back(temp);
    			    carry=0;
    			}
    			i--;
    		}
    	}while (i >= 0);
    	
    	if(carry==1)
    		source.push_back(carry);
    	
    	ra_length = source.size();
    	
    	for (int m =ra_length - 1; m >= 0; m--) 
    			ans.push_back(source[m]);
    	
    	while(ans.front()==0)
    	{
    		ans.erase(ans.begin());
    	}
     
    	return ans;
    }
     
     
    vector<int> Solution::plusOne(vector<int> &A) {
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        vector<int> B;
        vector<int> C;
        int temp=1;
        B.push_back(temp);
        C = addition(A,A.size(),B,B.size());
        return C;
    }

