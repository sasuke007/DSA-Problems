https://codeforces.com/problemset/problem/1389/A

package main

import "fmt"

func main() {
	var n int
	_, err := fmt.Scanf("%d\n", &n)
	if err != nil {
		return
	}
	for i := 0; i < n; i++ {
		var a, b int
		_, err = fmt.Scanf("%d %d\n", &a, &b)
		if 2*a <= b {
			fmt.Printf("%d %d\n", a, 2*a)
		} else {
			fmt.Printf("%d %d\n", -1, -1)
		}
	}
}
