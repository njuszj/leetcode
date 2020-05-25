// 外观数列

# include "leetcode.h"

class Solution {
public:
    string countAndSay(int n) {
        int cnt = 1;
        string prev = "1";
        while(cnt < n){
            string sub_res;
            char c_curr = prev[0];
            int c_cnt = 1;
            for(int i = 1; i < prev.size(); i++){
                if(prev[i] == c_curr)
                    c_cnt++;
                else{
                    sub_res += (to_string(c_cnt)+c_curr);
                    c_cnt = 1;
                }
                c_curr = prev[i];
            }
            sub_res += (to_string(c_cnt)+c_curr);
            prev = sub_res;
            cnt++;
        }
        return prev;
    }
};

int main(int argc, char** argv){
    Solution s;
    string r = s.countAndSay(atoi(argv[1]));
    cout << r << endl;
}