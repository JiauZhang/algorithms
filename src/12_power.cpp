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
 * 题目描述
 *     给定一个double类型的浮点数base和int类型的整数exponent。
 *     求base的exponent次方。
 * 
 * 解题思路：
 *     采用二分法加速幂运算
 *     注意事项：
 *     1. 当exponent为负数，base非常接近0.0时，会出现 0 除操作，
 *        由于duoble和float型表示小数时都有误差
 *        所以不能用 == 来判断base是否为零，而应该应该判断这个数的绝对值是否
 *        很接近 0.0，比如0.0000001，这样就可以认为它是零了
 *     2. 幂运算不用重复逐个相乘计算，可以使用二分法
 *     3. 判断exponent的奇偶性时，可以使用效率更好的位与运算 exp & 0x01
 * 
 */

class Solution {
public:
    bool invalid_input = false;
    double Power(double base, int exponent) {
        if (is_zero(base) && exponent<0) {
            invalid_input = true;
            return 0.0;
        }
        
        unsigned int exp = exponent;
        if (exponent<0)
            exp = (unsigned int)(-exponent);
        
        double res = do_power(base, exp);
        if (exponent<0)
            res = 1/res;
        
        return res;
    }
    
    double do_power(double base, unsigned int exp) {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base;
        double res = do_power(base, exp>>1);
        res = res * res;
        if (exp & 0x01)
            res = res * base;
        
        return res;
    }
    
    bool is_zero(double x) {
        if (x>-0.0000001 && x<0.0000001)
            return true;
        
        return false;
    }
};