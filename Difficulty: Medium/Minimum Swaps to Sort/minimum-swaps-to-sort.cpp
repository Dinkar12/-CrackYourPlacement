//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	     vector<int> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(i);
        }
        sort(a.begin(),a.end(),[&](int a, int b)->bool{
            return nums[b]>nums[a];
        });
        int count=0;
        bool flag=true;
        while(flag){
            flag=false;
            for(int i=0;i<nums.size();i++){
                if(a[i]!=i){
                    swap(a[a[i]],a[i]);
                    //check
                   // if(a[i]==i) flag=false;
                    flag=true;
                    count++;
                }
            }
        }
        return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends