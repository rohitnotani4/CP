/*
https://www.interviewbit.com/problems/n3-repeat-number/
*/

int Solution::solve(vector<string> &A) {

    int ans = 0;
    float value;
    //Divide in range
    vector<float> firstRange, secondRange,thirdRange;
    string::size_type sz;
    for(int i=0;i<A.size();i++)
    {
        value = stof(A[i],&sz);
        // cout<<value<<" ";
        if(value > 0 && value < ((float)2)/3)
            firstRange.push_back(value);
        else
        if(value >= (((float)2)/3) && value <= (float)1)
            secondRange.push_back(value);
        else
        if(value > (float)1 && value < (float)2)    
            thirdRange.push_back(value);
    }

    float xMin1=INT_MAX,xMin2=INT_MAX,xMax1=INT_MIN,xMax2=INT_MIN,xMax3=INT_MIN;
    for(int i=0;i<firstRange.size();i++)
    {
        if(firstRange[i] < xMin1)
        {
            if(xMin1 < xMin2)
                xMin2 = xMin1;
            xMin1 = firstRange[i];
        }
        else
        if(firstRange[i] < xMin2)
        {
            xMin2 = firstRange[i];
        }


        if(firstRange[i] > xMax1)
        {
            if(xMax2 > xMax3)
                xMax3 = xMax2;

            if(xMax1 > xMax2)
                xMax2 = xMax1;

            xMax1 = firstRange[i];    
        }
        else
        if(firstRange[i] > xMax2)
        {
            if(xMax2 > xMax3)
                xMax3 = xMax2;
            xMax2 = firstRange[i];    
        }
        else
        if(firstRange[i] > xMax3)
        {
            xMax3 = firstRange[i];    
        }
    }
    float yMin1=INT_MAX,yMin2=INT_MAX,yMax1=INT_MIN,zMin1 = INT_MAX;
    for(int i=0;i<secondRange.size();i++)
    {
        if(secondRange[i] < yMin1)
        {
            if(yMin1 < yMin2)
                yMin2 = yMin1;
            yMin1 = secondRange[i];
        }
        else
        if(secondRange[i] < yMin2)
        {
            yMin2 = secondRange[i];
        }

        if(secondRange[i] > yMax1)
            yMax1 = secondRange[i];
    }

    for(int i=0;i<thirdRange.size();i++)
    {
        if(thirdRange[i] < zMin1)
            zMin1 = thirdRange[i];
    }

    if(firstRange.size() > 0 || secondRange.size() >0 || thirdRange.size() > 0)
    {
        if(xMax1 + xMax2 + xMax3 >= (float)1)
        {
            ans=1;
        }
        else
        if( (xMin1 + xMin2 + zMin1) > 1 && (xMin1 + xMin2 + zMin1) < (float)2)
        {
            ans=1;
        }
        else
        if( (xMin1 + yMin1 + yMin2) > 1 && (xMin1 + yMin1 + yMin2) < (float)2)
        {
            ans=1;
        }
        else
        if( (xMin1 + yMin1 + zMin1) > 1 && (xMin1 + yMin1 + zMin1) < (float)2)
        {
            ans=1;
        }
        else
        if( (xMax1 + xMax2 + yMin1) > 1 && (xMax1 + xMax2 + yMin1) < (float)2)
        {
            ans = 1;
        }
        else
        if( (xMin1 + xMin2 + yMax1) > (float)1 && (xMin1 + xMin2 + yMax1) < 2)
        {
            ans = 1;
        }
    }

    return ans;
}
