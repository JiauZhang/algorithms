/*
题目描述
    请实现一个函数，将一个字符串中的每个空格替换成“%20”。
    例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
解题思路：
    为了节省空间，这里假设源字符串后方有足够的空间，这里采用就地替换的方法
    但是如果从前往后替换的话，每遇到一次空格都需要整体移动后方的字符串
    复杂度太高，所以从后方开始替换，为了确定字符串最后的长度，所以需要
    先统计字符串中空格的数量，然后得到尾部指针，遇到空格就替换，没有就复制
 */
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (!str || length<0)
            return;
        
        int spaces = 0;
        for (int l=0; l<length; l++) {
            if (str[l] == ' ')
                spaces++;
        }
        
        if (spaces == 0)
            return;
        
        int tail = length + 2*spaces - 1;
        /* 记得需要给新的字符串一个结束符！ */
        str[tail+1] = '\0';
        for (int l=length-1; l>=0; l--) {
            if (str[l] != ' ') {
                str[tail--] = str[l];
            } else {
                str[tail--] = '0';
                str[tail--] = '2';
                str[tail--] = '%';
            }
        }
	}
};