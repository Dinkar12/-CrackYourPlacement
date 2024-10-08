//{ Driver Code Starts
//Initial Template for C++

#include  <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
//User function Template for C++
int getmax(int arr[], int n)
{
    int mx=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > mx)
        {
            mx=arr[i];
        }
    }
    return mx;
}

void countsort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10]={0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) 
{ 
   // code here
   int m=getmax(arr, n);
   for(int exp=1; m/exp > 0; exp *= 10)
   {
       countsort(arr,n,exp);
   }
} 

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
  
        radixSort(arr, n); 
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    return 0; 
} 
// } Driver Code Ends