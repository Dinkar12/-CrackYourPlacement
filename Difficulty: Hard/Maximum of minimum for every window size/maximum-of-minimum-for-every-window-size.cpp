//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        stack<int> s;
        vector<int> left(n, -1), right(n, n);
        for(int i=0; i<n; i++)
        {
            while(s.size() && arr[s.top()]>=arr[i]) s.pop();
            if(s.size()) left[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(s.size()) right[i]=s.top();
            s.push(i);
        }
        vector<int> ans(n+1);
        for(int i=0; i<n; i++)
        {
            int len=right[i]-left[i]-1;
            ans[len]=max(ans[len], arr[i]);
        }
        for(int i=n-1; i>=1; i--)
        {
            ans[i]=max(ans[i], ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends