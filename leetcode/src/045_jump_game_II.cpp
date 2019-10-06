/*
题目：
    给定一个非负整数数组，你最初位于数组的第一个位置。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:
    输入: [2,3,1,1,4]
    输出: 2
    解释: 跳到最后一个位置的最小跳跃数是 2。
          从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

说明:
    假设你总是可以到达数组的最后一个位置。
*/

/*
    贪婪算法(Greedy Algorithm), 时间复杂度 O(n)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, cur = 0, prev = 0;
        while (cur < nums.size()-1) {
            step++;
            int temp = cur;
            int index = 0;
            // 因为当前点可达，则它前方的点中上次的产生最大可达点之间都可达了
            // 故检查这段中的元素最大的可达距离
            for (int i=prev; i<=temp; i++) {
                if (cur < nums[i] + i) {
                    // 记录上次最大可达 与 当前点 之间的点中产生最大可达的点坐标
                    index = i;
                    cur = nums[i] + i;
                }
            }
            if (cur == temp)
                return -1;
            
            prev = index;
        }
        
        return step;
    }
};