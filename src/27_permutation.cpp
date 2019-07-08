/*
 题目描述
     输入一个字符串,按字典序打印出该字符串中字符的所有排列。
     例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
     输入描述:
 
 注：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字
 
 解题思路：
     1. 递归产生，每进入一次递归，为了产生新的组合，需要将在起始位置的字符与其后方的进行
        交换，最后需要复原，这样下一次就可以重复该步骤而不出错
     2. 交换位置可以看做是在取自己可能的字符，start就可以看做是某个排列中的某个位置
     
 八皇后问题：
     8*8的棋盘上，任意两个皇后不能在同一行、同一列、同一对角线上
     
 解题思路：
     1. 首先把列作为待排序字符，8个列索引分别代表8个皇后的 列位置，为了确定还需要行位置
     2. 下面对8个列位置，即皇后进行行排列，即得到的结果就是
        第 i 行放 列索引为 k 的皇后，这样每个皇后的位置就确定了，且是行列唯一的
     3. 最后检查 这些组合中符合 不在同一对角线上的排列
 
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        
        if (str.size() == 0)
            return res;
        
        do_permutation(str, 0, res);
        
        return res;
    }
    
    void do_permutation(string &str, int start, vector<string> &res)
    {
        if (start == str.size() && 
            // 防止重复字符出现，也可以在最后处理
            find(res.begin(), res.end(), str) == res.end()) {
            res.push_back(str);
        } else {
            for (int i=start; i<str.size(); i++) {
                // 交换位置，产生新的组合
                char temp = str[i];
                str[i] = str[start];
                str[start] = temp;
                
                do_permutation(str, start+1, res);
                // 复原位置
                temp = str[start];
                str[start] = str[i];
                str[i] = temp;
            }
        }
    }
};