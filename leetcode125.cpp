// 验证回文串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

/*
记一笔 c++的几个内置函数

    islower(char c) 是否为小写字母
    isupper(char c) 是否为大写字母
    isdigit(char c) 是否为数字
    isalpha(char c) 是否为字母
    isalnum(char c) 是否为字母或者数字
    toupper(char c) 字母小转大
    tolower(char c) 字母大转小

作者：karlzhang
链接：https://leetcode-cn.com/problems/valid-palindrome/solution/9877-ci-ti-mu-de-shou-xi-7ge-zi-mu-shu-zi-pan-duan/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

# include "leetcode.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0, size = s.size(), tail = size-1;
        if(size == 0) return true;
        while(tail > head){
            while(head < tail && !isValid(s[head])) head++;
            while(head < tail && !isValid(s[tail])) tail--;
            if(s[head] == s[tail] || (isalpha(s[head]) && 
                isalpha(s[tail]) && abs(s[head] - s[tail])==32)) {
                    head++;
                    tail--;
                }
            else return false;
        }
        return true;
    }
private:
    bool isValid(char c){
        if(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            return true;
        else
            return false;
    }
};