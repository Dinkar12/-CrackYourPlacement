class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        map<int, set<int>*> sets;

        for (int i = 0 ; i < n ; i ++){

            set<int>* cluster = new set<int>;
            cluster->insert(i+1);
            sets[i+1] =  cluster;

        }

        vector<int> ans(2);

        for (const auto& edge : edges){
            int a = edge[0];
            int b = edge[1];

            if (sets[a] != sets[b]){
                set<int>* a_s = sets[a];
                set<int>* b_s = sets[b];
                a_s->insert(b_s->begin(), b_s->end());

                for (int preS : *b_s) {
                    sets[preS] = a_s;
                }

                delete b_s;
            }
            else{
                ans[0] = a;
                ans[1] = b;
            }
        }

        return ans;
    }
};