/*
薯队长写了n篇笔记，编号从1~n,每篇笔记都获得了不少点赞数。    
薯队长想从中选出一些笔记，作一个精选集合。挑选的时候有两个规则：
1.不能出现连续编号的笔记。 
2.总点赞总数最多 
如果满足1，2条件有多种方案，挑选笔记总数最少的那种 

输入描述:
输入包含两行。第一行整数n表示多少篇笔记。 第二行n个整数分别表示n篇笔记的获得的点赞数。   
 （0<n<=1000,    0<=点赞数<=1000) 

输出描述:
输出两个整数x,y。空格分割。
 x表示总点赞数，y表示挑选的笔记总数。
*/

// 动态规划　!
// dp[i] = max(dp[i+1], dp[i+2] + likes[i])

# include <iostream>
# include <vector>
using namespace std;

int bestLike(vector<int>& likes, int start){

}

int main(){
    int n;
    cin >> n;
    vector<int> likes(n, 0);
    for(int i=0; i<n; i++){
        cin >> likes[i];
    }
}