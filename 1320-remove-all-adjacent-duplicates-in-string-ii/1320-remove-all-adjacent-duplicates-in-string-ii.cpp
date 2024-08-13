class Solution {
public:
    string removeDuplicates(string s, int k) {
        ios_base::sync_with_stdio(false);
        stack<pair<char,int>> st;
        int count=1;
        for(int i=0;i<s.length();i++){
            if(!st.empty()){
            }
            count=1;
            if(st.empty()){
                st.push({s[i],count});
            }
            else{
                if(!st.empty() && st.top().first==s[i]){
                    count=st.top().second;
                    char x = st.top().first;
                    st.pop();
                    while(i<s.length() && s[i]==x){
                        if(count==k){
                            count=0;
                        }
                        count++;
                        i++;
                    }
                    i--;
                    if(count==k){
                        count=0;
                    }
                    if(count!=0){
                        st.push({x,count});
                    }
                }
                else{
                    char x = s[i];
                    i++;
                    while(i<s.length() && s[i]==x){
                        if(count==k){
                            count=0;
                        }
                        count++;
                        i++;
                    }
                    if(count==k){
                        count=0;
                    }
                    if(count!=0){
                        st.push({x,count});
                    }
                    i--;
                }
            }
        }
        s="";
        while(!st.empty()){
            int b = st.top().second;
            while(b--){
                s.push_back(st.top().first);
            }
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};