package main

import (
	"fmt"
)

func subarraySum(nums []int, k int) int {
    pre, count := 0, 0
    mp := map[int]int{0 : 1}
    for i := 0; i < len(nums); i++ {
        pre += nums[i]
        diff := pre - k
        if _, ok := mp[diff]; ok {
            count += mp[diff]
        }
        mp[pre] += 1
    }
    return count
}

func main() {
	nums := []int{1, 1, 1}
	fmt.Println(subarraySum(nums, 2))
	nums = []int{1, 2, 3, 3}
	fmt.Println(subarraySum(nums, 3))
}