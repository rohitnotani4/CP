/* Question
https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
*/

// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])

int find_distance(int x1,int y1,int x2,int y2)
{
    
    return max(sqrt( ((x2-x1)*(x2-x1))), sqrt(((y2-y1)*(y2-y1)) ));
}

int Solution::coverPoints(vector<int> &X, vector<int> &Y) 
{
    
    int distance,sum=0,first_x,first_y,second_x, second_y;
    
 
    
    for(int i=1;i<X.size();i++)
    {
        //printf("x1=%d y1=%d x2=%d and y2=%d\n",X[i-1],Y[i-1],X[i],Y[i]);
        sum += find_distance(X[i-1],Y[i-1],X[i],Y[i]);
    }
        
    return sum;

}
