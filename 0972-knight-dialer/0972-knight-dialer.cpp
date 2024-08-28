class Solution {
public:
    int knightDialer(int n) {
        const vector<vector<int>> graph = {
            {4, 6},    
            {6, 8},    
            {7, 9},     
            {4, 8},     
            {0, 3, 9},  
            {},         
            {0, 1, 7},  
            {2, 6},     
            {1, 3},     
            {2, 4},     
        };
        vector<int> dp0(10, 1), dp1(10);
        for (int i = 2; i <= n; i++) {
            fill(dp1.begin(), dp1.end(), 0);
            for (int curr = 0; curr <= 9; curr++) {
                for (auto& next : graph[curr]) {
                    dp1[next] = (dp1[next] + dp0[curr]) % int(1e9 + 7);
                }
            }
            swap(dp0, dp1);
        }
        int result = 0;
        for (int cell = 0; cell <= 9; cell++) result = (result + dp0[cell]) % int(1e9 + 7);
        return result;
    }
};