package main

import "fmt"

var n, k int

func main() {

	var T int;
	fmt.Scanf("%d\n", &T)
	// fmt.Print(T)
	for t := 0; t < T; t++{
		fmt.Scanf("%d%d\n", &n, &k)
		j := 0;
		for i := 0; i < n; i++ {
			fmt.Printf("%c", 'a' + j)
			j++;
			j %= k;
		}
		fmt.Println()
	}
}