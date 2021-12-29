package main

import ("fmt")

func pivotIndex(nums []int) int {
    sum := 0
    total := 0
    for _, val := range nums {
        total += val
    }

    for i, val := range nums {
        if 2 * sum + val == total {
            return i
        }
        sum += val
    }
    return -1
}


func main() {
	nums := []int{1, 7, 3, 6, 5, 6}
	fmt.Println(pivotIndex(nums))
	nums = []int{1, 2, 3}
	fmt.Println(pivotIndex(nums))
	nums = []int{2, 1, -1}
	fmt.Println(pivotIndex(nums))
}