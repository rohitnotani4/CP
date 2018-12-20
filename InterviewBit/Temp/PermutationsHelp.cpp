#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int>& input)
{
	cout<<"{ ";
	for(int i=0;i<input.size();i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<"}";
}

void permuteHelper(vector<vector<int> >& result, vector<int> input, vector<int> chosen, int index)
{
	cout<<"PermutationHelper : Input = ";
    printArray(input); 
    cout<<" Chosen = ";
    printArray(chosen);
    cout<<"\n";
    if(input.size() == 0)
    {
    	cout<<"Returning "<<"\n";
        result.push_back(chosen);
        return ;
    }
    else
    {
    	int size = input.size();
	    for(int i = 0;i<size;i++)
	    {
	        // Choose
	        chosen.push_back(input[i]);
	        int value =  input[i];
	        vector<int>::iterator it;
	        it = input.begin() + i;
	        input.erase(it);
	        
	        permuteHelper(result, input, chosen, i);
	        
	        input.insert(it, value);
	        chosen.pop_back();
	        cout<<"\nInput = ";
	        printArray(input); 
	        cout<<" Chosen = ";
    		printArray(chosen);
    		cout<<"\n";
	    }	
    }
    
    return ;
}

void printResult(vector<vector<int> >& result)
{
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
			cout<<result[i][j]<<" ";
			
		cout<<"\n";
	}

}

int main() 
{
	vector<int> A { 1, 2, 3 }; 
	vector<vector<int> > result;
    vector<int> chosen;

    sort(A.begin(), A.end());
    permuteHelper(result, A, chosen, 0);
	printResult(result);
	cout<<"\nhelloworld";
	return 0;
}
