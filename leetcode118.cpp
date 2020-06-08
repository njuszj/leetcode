// Éú³ÉÑî»ÔÈý½Ç

# include "leetcode.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int layer = 0;
        while (layer < numRows) {
            vector<int> sub_res = { 1 };
            if (layer > 0){
                for (int i = 1; i < layer + 1; i++) {
                    if (i == layer) sub_res.push_back(1);
                    else sub_res.push_back(res[layer - 1][i - 1] + res[layer - 1][i]);
                }
            }
            res.push_back(sub_res);
            layer++;
        }
        return res;
    }
};