'''
	For more information see <https://github.com/JiauZhang/algorithms>
'''

class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        if len(s) < 1:
            return s

        flag, res = True, ""
        for i in range(0, len(s), k):
            res += s[i:i+k][::-1] if flag else s[i:i+k]
            flag = not flag

        return res
