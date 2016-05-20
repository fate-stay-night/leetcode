#! /usr/bin/python
#coding:utf-8

class Solution(object):
	def longestPalindrome(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		if len(s) <= 1:
			return s
		b = "^" + (s.replace("","#")) + "$"
		ids = mx = 0
		l = [0 for n in range(len(b))]
		for i in range(1,len(b)-1):
			l[i] = min(l[2*ids -i], (mx - i)) if mx > i else 0

			while b[i + 1 + l[i]] == b [i - 1 - l[i]]:
				l[i] = l[i] + 1

			if i + l[i] > mx:
				ids = i 
				mx = i + l[i]
		return s[(l.index(max(l)) - max(l))/2 : (l.index(max(l)) - max(l))/2 + max(l)]

m = Solution()
print m.longestPalindrome("a")
