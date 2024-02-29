https://codeforces.com/problemset/problem/486/B

package main

import (
	"fmt"
)

func main() {
	var n, m int
	_, err := fmt.Scanf("%d %d\n", &n, &m)
	if err != nil {
		return
	}
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		for j := 0; j < m; j++ {
			_, err := fmt.Scan(&a[i][j])
			if err != nil {
				return
			}
		}
	}
	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, m)
		for j := 0; j < m; j++ {
			b[i][j] = 1
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if a[i][j] == 0 {
				for k := 0; k < n; k++ {
					b[k][j] = 0
				}
				for k := 0; k < m; k++ {
					b[i][k] = 0
				}
			}
		}
	}
	found := true
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			calculated := 0
			for k := 0; k < n; k++ {
				calculated |= b[k][j]
			}
			for k := 0; k < m; k++ {
				calculated |= b[i][k]
			}
			if calculated != a[i][j] {
				found = false
				break
			}
		}
	}
	if found {
		fmt.Println("YES")
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				fmt.Print(b[i][j], " ")
			}
			fmt.Println()
		}
	} else {
		fmt.Println("NO")
	}

}
