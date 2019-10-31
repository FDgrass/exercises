package main

import (
	"fmt"
	"sort"
)

type numAndIndex struct {
	num   int
	index int
}

func twoSum(nums []int, target int) []int {
	src := make([]numAndIndex, 0, len(nums))
	for idx, num := range nums {
		src = append(src, numAndIndex{num, idx})
	}
	sort.Slice(src, func(i, j int) bool {
		return src[i].num < src[j].num
	})
	idx1 := 0
	idx2 := len(src) - 1

	for idx1 < idx2 {
		sum := src[idx1].num + src[idx2].num
		if sum == target {
			return []int{src[idx1].index, src[idx2].index}

		} else if sum < target {
			idx1++
		} else {
			idx2--
		}
	}
	return nil
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9
	ans := twoSum(nums, target)
	fmt.Println(ans)
}
