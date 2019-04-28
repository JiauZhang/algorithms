/*
 * 题目描述:
 *     把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
 *     输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
 *     例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
 *     NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 * 
 * 解题思路：
 *     由于每个部分都是有序的，所以可以利用这个特性，采用二分法。
 *     首先是判断数组有没有经过旋转，即vec[left]>=vec[right]
 *     如果不满足，那么一定是没有旋转的，所以最小值就是vec[left]
 *     如果经过旋转了，下面就是判断vec[mid]落在了哪个区域
 *     如果vec[mid]<vec[left]，那么肯定是落在了左边的区域
 *     如果vec[mid]>vec[left]，那么肯定是落在了右边的区域
 *     如果vec[mid]=vec[left]，这说明left到mid间的数字都相等，所以自接
 *     将其算到右边区域也无妨。即最后认为vec[mid]>=vec[left]为落入了右边区域
 *     
 *     这里有两个特殊情况：
 *     1. vec[mid] == vec[left] == vec[right]
 *        这就没法判断到低落入了哪个区域了
 *        例如：3, 3, 3, [3], 1, 2, 3 --- 3, 1, 2, [3], 3, 3, 3
 *        这种情况就只能对两边分别找最小值了
 *     2. 当只剩下两个数组元素------不然会发生死循环
 *        例如：9, 1
 *        由于mid = (left + right) / 2
 *        所以mid = left，根据区域判断条件后，left=mid
 *        这里就进入了死循环了，所以必须注意这个条件
 *        检查是否只剩两个数组了！！！
 * 
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> vec) {
        if (vec.size() == 0)
            return 0;
        
        if (vec.size() == 1)
            return vec[0];
        
        int left = 0;
        int right = vec.size() - 1;
        int mid = left;
        
        while (vec[left]>=vec[right]) {
            if (right - left == 1) {
			    mid = right;
			    break;
		    }
            
            mid = (left + right) / 2;
            if (vec[left] == vec[right] && \
                vec[right] == vec[mid]) {
                return find_min(vec, left, right);
            }
            
            if (vec[mid] < vec[left]) {
                right = mid;
            } else if (vec[mid] >= vec[left]) {
                left = mid;
            }
        }
        
        return vec[mid];
    }   
    
    int find_min(vector<int> &vec, int start, int end) {
        int min = vec[start];
        while (start <= end) {
            if (min>vec[start])
               min = vec[start];
            start++;
        }
        
        return min;
    }
};