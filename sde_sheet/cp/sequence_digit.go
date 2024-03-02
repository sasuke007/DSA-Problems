https://codeforces.com/problemset/problem/1355/A
package main

import (
	"fmt"
)

func getDigits(n int) []int {
	digits := make([]int, 0)
	for n != 0 {
		digits = append(digits, n%10)
		n /= 10
	}
	return digits
}

func findMax(arr []int) int {
	maxElement := arr[0]
	for i := 0; i < len(arr); i++ {
		if arr[i] > maxElement {
			maxElement = arr[i]
		}
	}
	return maxElement
}

func findMin(arr []int) int {
	minElement := arr[0]
	for i := 0; i < len(arr); i++ {
		if minElement > arr[i] {
			minElement = arr[i]
		}
	}
	return minElement
}

func main() {
	var tc int
	_, err := fmt.Scan(&tc)
	if err != nil {
		return
	}
	for i := 0; i < tc; i++ {
		var n, k int
		_, err := fmt.Scan(&n, &k)
		if err != nil {
			return
		}
		temp := n
		for k > 1 {
			digits := getDigits(n)
			n += findMin(digits) * findMax(digits)
			if n == temp {
				break
			}
			temp = n
			k--
		}
		fmt.Println(temp)
	}
}
