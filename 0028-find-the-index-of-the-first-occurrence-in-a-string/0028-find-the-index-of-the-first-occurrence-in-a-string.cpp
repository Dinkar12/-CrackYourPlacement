class Solution {
    void calculate_longestPrefixSuffix(string &needle,int m,vector<int>& lps){
        int l=0,r=1;
        while(r<m){
            if(needle[l]==needle[r]){
                lps[r] = 1+l;
                l++;
                r++;
            } else {
                if(l>0)
                    l = lps[l-1];
                else
                    r++;
            }
        }
    }
    int patternMatcher(string& haystack,int n,string& needle,int m,vector<int>& lps){
        int haystack_pos=0;
        int needle_pos=0;
        while(needle_pos<m and haystack_pos<n){
            if(haystack[haystack_pos]==needle[needle_pos]){
                haystack_pos++;
                needle_pos++;
            }
            if(needle_pos==m)
                return haystack_pos-m;
            
            if(haystack[haystack_pos]!=needle[needle_pos]){
                if(needle_pos>0)
                    needle_pos = lps[needle_pos-1];
                else
                    haystack_pos++;
            }
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m>n)
            return -1;
        
        vector<int> lps(m,0); 
        calculate_longestPrefixSuffix(needle,m,lps);
        return patternMatcher(haystack,n,needle,m,lps);
    }
};