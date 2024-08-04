class Solution {
public:
    int countpartitions(vector<int>& nums, int maxsum)
    {
        int n=nums.size();
        int partitions=1;
        long long subarraysum=0;
        for(int i=0; i<n; i++)
        {
            if(subarraysum + nums[i]<=maxsum)
            {
                subarraysum += nums[i];
            }
            else
            {
                partitions++;
                subarraysum=nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int partitions=countpartitions(nums, mid);
            if(partitions>k)
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