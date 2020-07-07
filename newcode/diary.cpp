/*
 薯队长写了一篇笔记草稿，请你帮忙输出最后内容。
 1.输入字符包括，"("    ,    ")"    和    "<"和其他字符。 
 2.其他字符表示笔记内容。
 3.()之间表示注释内容，任何字符都无效。    括号保证成对出现。
 4."<"表示退格,    删去前面一个笔记内容字符。括号不受"<"影响
    input> Corona(Trump)USA<<<Virus
   output> CoronaVirus
*/
# include <iostream>
# include <algorithm>
# include <string>
# include <stack>
using namespace std;

int main(){
    string str_in, res;
    cin >> str_in;
    stack<char> trace;
    int skip = 0;
    for(int i=0; i<str_in.size(); i++){
        if(str_in[i] == '('){
            skip ++;
        }
        else if(str_in[i] == ')'){
            skip --;
        }
        if(skip || str_in[i] == ')') continue;
        if(!trace.empty() && str_in[i] == '<') trace.pop();
        else trace.push(str_in[i]);
    }
    while(!trace.empty()){
        res += trace.top();
        trace.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}