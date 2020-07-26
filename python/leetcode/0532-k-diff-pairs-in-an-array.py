'''
	For more information see <https://github.com/JiauZhang/algorithms>
'''

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0

        c = collections.Counter(nums)
        res = 0

        for n in c:
            if k > 0:
                diff = n - k
                if c[diff] != 0:
                    res += 1
            else:
                if c[n] > 1:
                    res += 1
        
        return res