/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

/*
* https://leetcode-cn.com/problems/rotate-array
* 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
* 
* 示例 1:
*     输入: [1,2,3,4,5,6,7] 和 k = 3
*     输出: [5,6,7,1,2,3,4]
* 解释:
*     向右旋转 1 步: [7,1,2,3,4,5,6]
*     向右旋转 2 步: [6,7,1,2,3,4,5]
*     向右旋转 3 步: [5,6,7,1,2,3,4]
* 
* 示例 2:
*     输入: [-1,-100,3,99] 和 k = 2
*     输出: [3,99,-1,-100]
* 解释: 
*     向右旋转 1 步: [99,-1,-100,3]
*     向右旋转 2 步: [3,99,-1,-100]
* 
* 说明:
*     尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题
*     要求使用空间复杂度为 O(1) 的 原地 算法
*     
* 解题思路：
*     第一种：暴力操作法，操作流程与示例相同，时间复杂度 O(k*n)
*     第二种：将数组分成连续包含 k 个数的子区间，这样每个子区间的数
*             往后移动 k 即可，然而此时涉及到并不是需要 k 次这样的操作
*             操作次数与 k 与 n 的最大公约数相等，如 Solution_1 所示
*             为什么是这样子的，例如 n = 8, k = 6
*             当对第一个元素操作时，其终止条件是重新回到出发点处
*             即此时有 n*p = k*q --> 8*p = 6*q
*             使得该等式成立时的最小 p 和 q 为 8*3 = 6*4
*             6* 4 表示一次交替后移会操作到四个数，而数组一共 8 个数
*             故需要操作 8/4 = 2 次即可操作完所有数
*             通过上述计算方法可知，其实是先找到了 k 和 p 之间的最小公倍数
*             然后除以了一次交替操作的个数，其最终结果就是最大公约数!
*     第三种：使用数组反转来完成，例如 1, 2, 3, 4, 5, 6, 7
*             即 n = 7, 这里让 k = 2
*             操作步骤为如下：
*             1, 2, 3, 4, 5, 6, 7  --> 7, 6, 5, 4, 3, 2, 1
*             --> 5, 6, 7, 1, 2, 3, 4
*/

class Solution_1 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0)
            return;
        
        int max = gcd(nums.size(), k);
        for (int i=0; i<max; i++) {
            int start = i, current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
            } while (start != current);
        }
    }

    int gcd(int a, int b) {
        while (1) {
            int c = a % b;
            if (c == 0) {
                return b;
            } else {
                a = b;
                b = c;
            }
        }

        return -1;
    }
};

class Solution_2 {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size() == 0 || k == 0)
            return;
        
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }

    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
};