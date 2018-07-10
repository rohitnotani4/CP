/*
https://www.interviewbit.com/problems/reverse-the-string/
*/

void Solution::reverseWords(string &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	int size = A.size();
	string reverse;
	int i=size-1;
	
	while(i>=0 && A[i]==' ')
	{
		i--;
	}
 
	if(i >= 0)
	{
		do
		{
			if(A[i]!=' ')
			{
				reverse.push_back(A[i]);
				i--;
			}
			else
			{
				reverse.push_back(' ');
				while(i>=0 && A[i]==' ')
					i--;
			}    
		}while(i>=0);
	}
	
	A.clear();
	if(!reverse.empty())
	{
		int j=0;
		if(reverse[reverse.size()-1] == ' ')
			j++;
		
		string temp;    
		for(;j<reverse.size();j++)
		{
			if(reverse[j]!=' ')
			{
				temp.push_back(reverse[j]);    
			}
			else
			{
				for(int k=temp.size()-1;k>=0;k--)
					A.push_back(temp[k]);
				A.push_back(' ');
				temp.clear();
			}
		}
		if(temp.size()>0)
		{
			for(int k=temp.size()-1;k>=0;k--)
					A.push_back(temp[k]);
		}			
	}
}
