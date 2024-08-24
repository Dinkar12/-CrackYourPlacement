class Solution {
public:
    string reorganizeString(string s) {
        if(s.size()==1) return s;
        int frequency[26];
        for(int e=0;e<26;e++) frequency[e]=0;
        for(int e=0;e<s.size();e++){
            frequency[s[e]-97]++;
        }
        int acceptor=0;
        if(s.size()%2==0) acceptor=s.size()/2;
        else acceptor=(s.size()/2)+1;
        string str="";
        int e=0;
        for(;e<26;e++){
            if(frequency[e]>acceptor) break;
        }
        if(e!=26) return "";
        int x=1;
        int skip=-1;
        while(x!=0)
        {
            int largest=0;
            int index=-1;
            for(e=0;e<26;e++){
                if(frequency[e]>largest && e!=skip){
                    largest=frequency[e];
                    index=e;
                }
            }
            if(largest==0) break;
            str+=index+97;
            frequency[index]--;
            skip=index;
        }
        return str;
    }
};