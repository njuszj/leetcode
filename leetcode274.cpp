// H ָ��
/*
����һλ�о������ı����ô��������飨�����ô����ǷǸ�����������дһ��������������о��ߵ� h ָ����
h ָ���Ķ��壺h ���������ô�������high citations����
һ��������Ա�� h ָ����ָ���������� ��N ƪ�����У��ܹ��� h ƪ���ķֱ����������� h �Ρ�
������� N - h ƪ����ÿƪ�����ô��� ������ h �Ρ���
���磺ĳ�˵� h ָ���� 20�����ʾ���ѷ���������У�ÿƪ������������ 20 �ε������ܹ��� 20 ƪ��
*/
// �������������Ļ�������������

# include "leetcode.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if (size == 0) return 0;
        sort(citations.begin(), citations.end());  // ��С��������
        int index = size - 1;  // ����ָ��
        for (int i = size; i >= 0; i--) {
            while (index >= 0 && citations[index] >= i) index--;
            if (citations[index] >= i) index = -1;  // ����ͷ�����
            int cnt = size - 1 - index;   // ���ô�������h����Ŀ
            if (cnt >= i) return cnt;
        }
        return 0;
    }
};