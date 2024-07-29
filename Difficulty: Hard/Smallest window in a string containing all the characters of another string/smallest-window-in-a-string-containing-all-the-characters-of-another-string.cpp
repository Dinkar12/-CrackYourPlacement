//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int>cur(26,0);
        for(int i=0;i<p.size();i++)
        {
            cur[p[i]-'a']++;
        }
        int i=0,j=0,counter=p.size(),minstart=0,minlen=INT_MAX;
        int n=s.size();
        while(j<n)
        {
            if(cur[s[j]-'a']>0)
            {
                counter--;
            }
            
            cur[s[j]-'a']--;
            
            while(counter==0)
            {
                if(j-i+1<minlen)
                {
                    minstart=i;
                    minlen=j-i+1;
                }
                
                cur[s[i]-'a']++;  
                if(cur[s[i]-'a']>0)
                {
                    counter++;
                }
                i++;
            }
            
            j++;
        }
        
        return (minlen!=INT_MAX?s.substr(minstart,minlen):"-1");
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends