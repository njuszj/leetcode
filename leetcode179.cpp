// 最大数
// 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数
// 只要考虑首位就可以了，如果首位相同，则应该依次考虑下一位
// 测试用例 [12, 121] 未通过

/*
关键在于比较函数的构建
public int compare(String a, String b) {
    String order1 = a + b;
    String order2 = b + a;
    return order2.compareTo(order1);
    }
}
作者：LeetCode
链接：https://leetcode-cn.com/problems/largest-number/solution/zui-da-shu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

这样写比我的更简单明了，不易出错
但是比较难想到...注意是一个字符串拼接
*/
# include "leetcode.h"

bool firstGreater(int n, int m){
    stack<int> s1, s2;
    int first = 0;
    while(n){
        s1.push(n % 10);
        n = n/10;
    }
    while(m){
        s2.push(m % 10);
        m = m / 10;
    }
    first = s1.top();
    while(!s1.empty() && !s2.empty()){
        if(s1.top() < s2.top()) return false;
        else if(s1.top() > s2.top()) return true;
        else {
            s1.pop();
            s2.pop();
        }
    }
    if(s1.empty() && !s2.empty() && first<=s2.top()) return false;
    if(s1.empty() && !s2.empty() && first>s2.top()) return true;
    if(s2.empty() && !s1.empty() && first>s1.top()) return false;
    if(s2.empty() && !s1.empty() && first<=s1.top()) return true;
    return true;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), firstGreater);
        for(int n : nums)
            res.append(to_string(n));
        return res;
    }
};

int main(){
    bool x = firstGreater(999, 9922122);
    vector<int> v = {1,99,10,888,9999};
    printVector(v);
    sort(v.begin(), v.end(), firstGreater);
    printVector(v);
}