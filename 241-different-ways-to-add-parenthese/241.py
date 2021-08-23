#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        if expression.isdigit():
            return [int(expression)]
        res = []
        for i, val in enumerate(expression):
            if val in ['+', '-', '*']:
                left = self.diffWaysToCompute(expression[:i])
                right = self.diffWaysToCompute(expression[i+1:])
                for l in left:
                    for r in right:
                        if val == '+':
                            res.append(l+r) 
                        if val == '-':
                            res.append(l-r) 
                        if val == '*':
                            res.append(l*r) 
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.diffWaysToCompute("2-1-1"))
    print(sol.diffWaysToCompute("2*3-4*5"))