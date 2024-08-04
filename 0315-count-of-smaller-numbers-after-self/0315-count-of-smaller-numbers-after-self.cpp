class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans,cnt(n,0);
        ans.push_back(nums[n-1]);
        cnt[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>ans.back()){
                    ans.push_back(nums[i]);
                    cnt[i]=ans.size()-1;
            }
            else{
                int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans.insert(ans.begin()+ind,nums[i]);
                cnt[i]=ind;
            }
        }
        return cnt;
    }
};