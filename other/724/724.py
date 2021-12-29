from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        preSum = 0
        total = sum(nums)
        size = len(nums)
        for i in range(size):
            if 2 * preSum + nums[i] == total:
                return i
            preSum += nums[i]
        
        return -1

if __name__ == '__main__':
	sol = Solution()
	nums = [1, 7, 3, 6, 5, 6]
	print(sol.pivotIndex(nums))
	nums = [1, 2, 3]
	print(sol.pivotIndex(nums))
	nums = [2, 1, -1]
	print(sol.pivotIndex(nums))
	