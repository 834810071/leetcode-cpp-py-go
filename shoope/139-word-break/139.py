#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        size = len(s)
        dp = [False] * (size + 1)
        dp[0] = True
        for i in range(1, size + 1):
            for j in range(i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    break

        return dp[-1]


if __name__ == '__main__':
    sol = Solution()
    s = "leetcode"
    wordDict = ["leet", "code"]
    print(sol.wordBreak(s, wordDict))

    s = "applepenapple"
    wordDict = ["apple", "pen"]
    print(sol.wordBreak(s, wordDict))

    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    print(sol.wordBreak(s, wordDict))
