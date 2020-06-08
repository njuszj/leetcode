<<<<<<< HEAD
// 三角形最小路径和
/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
*/

// 解决方案： 自底向上求解，依次求到每个节点的最优选择

# include "leetcode.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size(); // 层数
        if (size == 0) return 0;
        if (size == 1) return triangle[0][0];
        for (int i = size - 2; i >= 0; i--) {
            int layer_size = triangle[i].size();
            for (int j = 0; j < layer_size; j++) {
                // 每一层每个节点到底部的最短距离
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
=======
// 涓夎褰㈢殑鏈�灏忚矾寰勫拰

/*
缁欏畾涓�涓笁瑙掑舰锛屾壘鍑鸿嚜椤跺悜涓嬬殑鏈�灏忚矾寰勫拰銆傛瘡涓�姝ュ彧鑳界Щ鍔ㄥ埌涓嬩竴琛屼腑鐩搁偦鐨勭粨鐐逛笂銆�
鐩搁偦鐨勭粨鐐� 鍦ㄨ繖閲屾寚鐨勬槸 涓嬫爣 涓� 涓婁竴灞傜粨鐐逛笅鏍� 鐩稿悓鎴栬�呯瓑浜� 涓婁竴灞傜粨鐐逛笅鏍� + 1 鐨勪袱涓粨鐐广��
*/

// 鍥炴函娉曚細瓒呮椂!!
// 搴旇浣跨敤鍔ㄦ�佽鍒�
//    鎬濊矾: 浣跨敤 dp[i][j] 璁板綍绗琲灞備腑绗琷涓綅缃渶灏忚矾寰勫��
//    dp[i][j] = MIN(dp[i-1][j-1]+Tri[i][j], dp[i-1][j]+Tri[i][j])
/*
    绫讳技涓婇潰鐨勬�濊矾锛屼絾鏄痙p鍚箟涓嶅悓
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& t) {
            for (int i = t.size() - 2; i >= 0; --i)
                for (int j = 0; j < t[i].size(); ++j)
                    t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
            return t[0][0];
        }
    };


浣滆�咃細Gary_coding
閾炬帴锛歨ttps://leetcode-cn.com/problems/triangle/solution/c-zhong-gui-zhong-ju-de-4msjie-fa-dp-kong-jian-o1-/
鏉ユ簮锛氬姏鎵ｏ紙LeetCode锛�
钁椾綔鏉冨綊浣滆�呮墍鏈夈�傚晢涓氳浆杞借鑱旂郴浣滆�呰幏寰楁巿鏉冿紝闈炲晢涓氳浆杞借娉ㄦ槑鍑哄銆�
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
>>>>>>> b5bceb60679d9e4014bc49c7686be5965b5eb0ea
};