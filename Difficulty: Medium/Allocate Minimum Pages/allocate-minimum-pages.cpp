//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
    public:
    int countstudents(int arr[], int pages, int n)
    {
        int students=1;
        long long pagesstudent=0;
        for(int i=0; i<n; i++)
        {
            if(pagesstudent + arr[i]<=pages)
            {
                pagesstudent +=arr[i];
            }
            else
            {
                students++;
                pagesstudent=arr[i];
            }
        }
        return students;
    }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n) return -1;
        int low=0,high=0;
        for(int i=0;i<n;i++)
        {
            low=max(low,arr[i]);
            high+=arr[i];
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int students=countstudents(arr, mid, n);
            if(students > m)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends