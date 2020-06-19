// 单词接龙II
/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

    每次转换只能改变一个字母。
    转换后得到的单词必须是字典中的单词。

说明:

    如果不存在这样的转换序列，返回一个空列表。
    所有单词具有相同的长度。
    所有单词只由小写字母组成。
    字典中不存在重复的单词。
    你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 构造图， BFS
// 以下代码来自官解

# include "leetcode.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (const string& word : wordList) {
            // 构造哈希映射
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(endWord)) {
            return {};
        }
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++) {
            // 构造边
            for (int j = i + 1; j < idWord.size(); j++) {
                if (transformCheck(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        const int dest = wordId[endWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(id, INT32_MAX);
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int index : now) {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }
private:
    unordered_map<string, int> wordId;
    vector<string> idWord;
    vector<vector<int>> edges;
    bool transformCheck(const string& str1, const string& str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                ++differences;
            }
        }
        return differences == 1;
    }
};



/*
基于上面的思路我们考虑如何编程实现。

方便起见，我们先给每一个单词标号，即给每个单词分配一个 id。创建一个由单词 word到 id 对应的映射 wordId，并将 beginWord 与 wordList 中所有的单词都加入这个映射中。之后我们检查 endWord 是否在该映射内，若不存在，则输入无解。我们可以使用哈希表实现上面的映射关系。

同理我们可以创建一个由对应 id 到 word 的映射 idWord，方便最后输出结果。由于 id 实际上是整数且连续，所以这个映射用数组实现即可。

接下来我们将 idWord 中的单词两两匹配，检查它们是否可以通过改变一个字母进行互相转换。如果可以，则在这两个点之间建一条双向边。

为了保留相同长度的多条路径，我们采用 cost 数组，其中 cost[i] 表示 beginWord 对应的点到第 i 个点的代价（即转换次数）。初始情况下其所有元素初始化为无穷大。

接下来将起点加入队列开始广度优先搜索，队列的每一个节点中保存从起点开始的所有路径。

对于每次取出的节点 now，每个节点都是一个数组，数组中的最后一个元素为当前路径的最后节点 last :

    若该节点为终点，则将其路径转换为对应的单词存入答案;
    若该节点不为终点，则遍历和它连通的节点（假设为 to ）中满足 cost[to]>=cost[now]+1cost[to] >= cost[now] + 1cost[to]>=cost[now]+1 的加入队列，并更新 cost[to]=cost[now]+1cost[to] = cost[now] + 1cost[to]=cost[now]+1。如果 cost[to]<cost[now]+1cost[to] < cost[now] + 1cost[to]<cost[now]+1，说明这个节点已经被访问过，不需要再考虑。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/word-ladder-ii/solution/dan-ci-jie-long-ii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/