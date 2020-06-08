// 三角形的最小路径和

/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
*/

// 回溯法会超时!!
// 应该使用动态规划
//    思路: 使用 dp[i][j] 记录第i层中第j个位置最小路径值
//    dp[i][j] = MIN(dp[i-1][j-1]+Tri[i][j], dp[i-1][j]+Tri[i][j])
/*
    类似上面的思路，但是dp含义不同
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& t) {
            for (int i = t.size() - 2; i >= 0; --i)
                for (int j = 0; j < t[i].size(); ++j)
                    t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
            return t[0][0];
        }
    };


作者：Gary_coding
链接：https://leetcode-cn.com/problems/triangle/solution/c-zhong-gui-zhong-ju-de-4msjie-fa-dp-kong-jian-o1-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

# include "leetcode.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        layers = triangle.size();
        if(layers == 0) return 0;
        dst(triangle, 0, 1, triangle[0][0]);
        return minium;
    }
private:
    int layers = 0;
    int minium = INT32_MAX;
    void dst(vector<vector<int>> & t, int i,int curr, int s){
        if(curr == layers){
            if(s < minium) minium = s;
        } 
        else{
            dst(t, i,curr+1, s+t[curr][i]);
            dst(t, i+1, curr+1, s+t[curr][i+1]);
        }
    }
};