#!/usr/bin/env python
# -*- coding:utf-8 -*-


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(reversed(s.split()))


if __name__ == '__main__':
    sol = Solution()
    print(sol.reverseWords("the sky is blue"))
    print(sol.reverseWords("  hello world  "))
    print(sol.reverseWords("a good   example"))
    print(sol.reverseWords("  Bob    Loves  Alice   "))
    print(sol.reverseWords("Alice does not even like bob"))
