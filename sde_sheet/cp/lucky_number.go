https://codeforces.com/problemset/problem/630/C]

// https://codeforces.com/problemset/problem/1355/A
package main

import (
	"fmt"
	"math"
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
	var n int
	_, err := fmt.Scan(&n)
	if err != nil {
		return
	}
	fmt.Println(2 * int64(int64(math.Pow(2, float64(n)))-1))
}
