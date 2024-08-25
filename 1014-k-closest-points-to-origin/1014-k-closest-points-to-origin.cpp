class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        multimap<int, int> mymap;
        for(int i=0; i<n; i++)
        {
            mymap.insert({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        }
        vector<vector<int>> ans;
        int count=0;
        for(auto it=mymap.begin(); count<k; ++it, ++count)
        {
            ans.push_back(points[it->second]);
        }
        return ans;
    }
};