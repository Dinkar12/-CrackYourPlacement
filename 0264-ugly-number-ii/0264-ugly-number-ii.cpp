class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int p1=0, p2=0, p3=0;
        for(int i=1; i<n; i++)
        {
            int twomulti=dp[p1]*2;
            int threemulti=dp[p2]*3;
            int fivemulti=dp[p3]*5;
            dp[i]=min(twomulti, min(threemulti, fivemulti));
            if(dp[i]==twomulti) p1++;
            if(dp[i]==threemulti) p2++;
            if(dp[i]==fivemulti) p3++;
        }
        return dp[n-1];
    }
};