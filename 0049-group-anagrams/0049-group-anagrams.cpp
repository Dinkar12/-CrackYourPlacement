class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mp;
        vector<vector<string>> ans;
        int index = 0;
        string tmp = "";
        for(int i = 0; i < strs.size(); i++)
        {
            tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            if(mp.find(tmp) != mp.end())
            {
                ans[mp[tmp]].push_back(strs[i]);
                continue;
            }
            mp[tmp] = index;
            ans.push_back(vector<string>{strs[i]});
            index++;
        }
        return ans;
    }
};