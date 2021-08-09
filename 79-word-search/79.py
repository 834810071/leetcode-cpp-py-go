#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not word:
            return True
        rows = len(board)
        cols = 0 if not rows else len(board[0])
        if cols == 0:
            return False
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0]:
                    visied = [[False for x in range(cols)] for y in range(rows)]
                    res = Solution.found(board, i, j, visied, word, 0, rows, cols)
                    if res:
                        return True
        
        return False
    
    @staticmethod
    def found(board: List[List[str]], x: int, y: int, visied: [[]], word: str, index: int, rows: int, cols: int):
        if index == len(word):
            return True
        if x < 0 or y < 0 or x >= rows or y >= cols:
            return False
        if word[index] != board[x][y] or visied[x][y]:
            return False
        visied[x][y] = True
        res = Solution.found(board, x+1, y, visied, word, index+1, rows, cols) or \
              Solution.found(board, x-1, y, visied, word, index+1, rows, cols) or \
              Solution.found(board, x, y+1, visied, word, index+1, rows, cols) or \
              Solution.found(board, x, y-1, visied, word, index+1, rows, cols)
        visied[x][y] = False
        return res

if __name__ == '__main__':
    sol = Solution()
    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    word = "ABCCED"
    print(sol.exist(board, word))

    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    word = "SEE"
    print(sol.exist(board, word))

    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    word = "ABCB"
    print(sol.exist(board, word))