//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       long long int s=0;
        for(int i=0;i<n;i++){
            s+=(p[i].petrol - p[i].distance);
        }
        if(s<0)
            return -1;
    
        //kadane's
        int index=0;
        int c=0;
        for(int i=0;i<n;i++){
            c+=(p[i].petrol - p[i].distance);
            if(c<0){
                c=0;
                index=i+1;
                
            }
            
        }
        return index;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends