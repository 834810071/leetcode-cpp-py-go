package main

import (
    "sort"
    "fmt"
)

func maximumProduct(nums []int) int {
    sort.Ints(nums)
    n := len(nums)
    return max(nums[0] * nums[1] * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3])
}

func max(a, b int) int {
    if (a < b) {
        return b
    }
    return a
}

func main() {
    nums := []int{1,2,3}
    fmt.Println(maximumProduct(nums))
    nums = []int{1,2,3,4}
    fmt.Println(maximumProduct(nums))
    nums = []int{-1,-2,-3}
    fmt.Println(maximumProduct(nums))
}