<<<<<<< HEAD
// Èý½ÇÐÎ×îÐ¡Â·¾¶ºÍ
/*
¸ø¶¨Ò»¸öÈý½ÇÐÎ£¬ÕÒ³ö×Ô¶¥ÏòÏÂµÄ×îÐ¡Â·¾¶ºÍ¡£Ã¿Ò»²½Ö»ÄÜÒÆ¶¯µ½ÏÂÒ»ÐÐÖÐÏàÁÚµÄ½áµãÉÏ¡£

ÏàÁÚµÄ½áµã ÔÚÕâÀïÖ¸µÄÊÇ ÏÂ±ê Óë ÉÏÒ»²ã½áµãÏÂ±ê ÏàÍ¬»òÕßµÈÓÚ ÉÏÒ»²ã½áµãÏÂ±ê + 1 µÄÁ½¸ö½áµã¡£
*/

// ½â¾ö·½°¸£º ×Ôµ×ÏòÉÏÇó½â£¬ÒÀ´ÎÇóµ½Ã¿¸ö½ÚµãµÄ×îÓÅÑ¡Ôñ

# include "leetcode.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size(); // ²ãÊý
        if (size == 0) return 0;
        if (size == 1) return triangle[0][0];
        for (int i = size - 2; i >= 0; i--) {
            int layer_size = triangle[i].size();
            for (int j = 0; j < layer_size; j++) {
                // Ã¿Ò»²ãÃ¿¸ö½Úµãµ½µ×²¿µÄ×î¶Ì¾àÀë
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
=======
// ä¸‰è§’å½¢çš„æœ€å°è·¯å¾„å’Œ

/*
ç»™å®šä¸€ä¸ªä¸‰è§’å½¢ï¼Œæ‰¾å‡ºè‡ªé¡¶å‘ä¸‹çš„æœ€å°è·¯å¾„å’Œã€‚æ¯ä¸€æ­¥åªèƒ½ç§»åŠ¨åˆ°ä¸‹ä¸€è¡Œä¸­ç›¸é‚»çš„ç»“ç‚¹ä¸Šã€‚
ç›¸é‚»çš„ç»“ç‚¹ åœ¨è¿™é‡ŒæŒ‡çš„æ˜¯ ä¸‹æ ‡ ä¸Ž ä¸Šä¸€å±‚ç»“ç‚¹ä¸‹æ ‡ ç›¸åŒæˆ–è€…ç­‰äºŽ ä¸Šä¸€å±‚ç»“ç‚¹ä¸‹æ ‡ + 1 çš„ä¸¤ä¸ªç»“ç‚¹ã€‚
*/

// å›žæº¯æ³•ä¼šè¶…æ—¶!!
// åº”è¯¥ä½¿ç”¨åŠ¨æ€è§„åˆ’
//    æ€è·¯: ä½¿ç”¨ dp[i][j] è®°å½•ç¬¬iå±‚ä¸­ç¬¬jä¸ªä½ç½®æœ€å°è·¯å¾„å€¼
//    dp[i][j] = MIN(dp[i-1][j-1]+Tri[i][j], dp[i-1][j]+Tri[i][j])
/*
    ç±»ä¼¼ä¸Šé¢çš„æ€è·¯ï¼Œä½†æ˜¯dpå«ä¹‰ä¸åŒ
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& t) {
            for (int i = t.size() - 2; i >= 0; --i)
                for (int j = 0; j < t[i].size(); ++j)
                    t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
            return t[0][0];
        }
    };


ä½œè€…ï¼šGary_coding
é“¾æŽ¥ï¼šhttps://leetcode-cn.com/problems/triangle/solution/c-zhong-gui-zhong-ju-de-4msjie-fa-dp-kong-jian-o1-/
æ¥æºï¼šåŠ›æ‰£ï¼ˆLeetCodeï¼‰
è‘—ä½œæƒå½’ä½œè€…æ‰€æœ‰ã€‚å•†ä¸šè½¬è½½è¯·è”ç³»ä½œè€…èŽ·å¾—æŽˆæƒï¼Œéžå•†ä¸šè½¬è½½è¯·æ³¨æ˜Žå‡ºå¤„ã€‚
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