/*
https://www.interviewbit.com/problems/hotel-bookings-possible/
*/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{ 
    vector< pair <int,int> > startEnd;
    for(int m=0;m<arrive.size();m++)
    {
        startEnd.push_back( make_pair(arrive[m],1) );
        startEnd.push_back( make_pair(depart[m],0) );
    }
    
    sort(startEnd.begin(),startEnd.end());
    
    int i=0,occupied = 0;
    
    while(i < startEnd.size())
    {
        if(startEnd[i].second == 1) // Someone is checking in
        {
            if(occupied < K)
                occupied++;
            else
                return false;
        }
        else
        if(startEnd[i].second == 0) // Someone is checking out
        {
            occupied--;
        }
        i++;
    }
    
    return true;
}
