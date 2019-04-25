/*
 *题目：
 *    二维数组中的查找
 *
 *题目描述：
 *    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 *    每一列都按照从上到下递增的顺序排序。请完成一个函数，
 *    输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *
 *解题思路：
 *   因为数组是有序的，所以采用对角顺序比较数据大小，这样一次就可以排除一行
 *
 */

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int x = array.size();
        int y = array[0].size();
        
        for (int i=0; i<x; i++) {
            for (int j=y-1; j>=0; j--) {
                if (target > array[i][j])
                    break;
                if (target == array[i][j])
                    return true;
                if (j == 0)
                    return false;
            }
        }        
        return false;
    }
};