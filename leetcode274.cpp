// H 指数
/*
给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。
h 指数的定义：h 代表“高引用次数”（high citations），
一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。
（其余的 N - h 篇论文每篇被引用次数 不超过 h 次。）
例如：某人的 h 指数是 20，这表示他已发表的论文中，每篇被引用了至少 20 次的论文总共有 20 篇。
*/
// 如果按降序排序的话结果会更加清晰

# include "leetcode.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if (size == 0) return 0;
        sort(citations.begin(), citations.end());  // 从小到大排序
        int index = size - 1;  // 访问指针
        for (int i = size; i >= 0; i--) {
            while (index >= 0 && citations[index] >= i) index--;
            if (citations[index] >= i) index = -1;  // 减到头的情况
            int cnt = size - 1 - index;   // 引用次数大于h的数目
            if (cnt >= i) return cnt;
        }
        return 0;
    }
};