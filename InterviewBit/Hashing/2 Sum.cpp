/*
https://www.interviewbit.com/problems/2-sum/
*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    multimap <int, int> hastTable;
    multimap <int, int>::iterator got;
    int secondNumber, minIndex1= INT_MAX, minIndex2 = INT_MAX;
    
    for(int i=0;i<A.size();i++)
        hastTable.insert(pair<int,int>(A[i],i+1));
    
    for(int i=0;i<A.size();i++)
    {
        secondNumber = B - A[i];
        // got = hastTable.find(secondNumber);
        std::pair <std::multimap<int,int>::iterator, std::multimap<int,int>::iterator> ret;
        ret = hastTable.equal_range(secondNumber);
        
        
        for(multimap<int,int>::iterator it=ret.first; it!=ret.second; ++it)
        {
            // std::cout << ' ' << it->second;
            // if(got->second > (i+1) && got->second < minIndex1)
            if(it->second > (i+1) && it->second < minIndex2)
            {   
                // cout<<A[i]<<" and "<<secondNumber<<"\n";
                minIndex2 = it->second;
                minIndex1 = i+1;
                // cout<<"Index1 = "<<minIndex1<< " and Index2= "<<minIndex2<<"\n";
            }
        }
    }
    
    if(minIndex1 != INT_MAX)
    {
        ans.push_back(minIndex1);
        ans.push_back(minIndex2);
    }
    return ans;
}
