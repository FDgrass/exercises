package main

import (
	"fmt"
	"sort"
)

type IntSlice []int
func (s IntSlice) Len() int {
	return len(s)
}
func (s IntSlice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}
func (s IntSlice) Less(i, j int) bool {
	return s[i] < s[j]
}

func main(){
	var n int
	fmt.Scanf("%d\n", &n)
	nums := make([]int, n)
	for i := 0; i < n; i++{
		fmt.Scanf("%d", &nums[i])
	}
	sort.Sort(IntSlice(nums))
	
	ans := 0
	for i := 0; i < n; i += 2 {
		ans += nums[i + 1] - nums[i]
	}
	fmt.Print(ans)
}